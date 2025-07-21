#include <sensor.h>
#include <motor.h>
#include <PubSubClient.h>
#include <WiFi.h>

WiFiClient espClient;
PubSubClient client(espClient);

bool b1, b2, b3, b4, b5;
String posisi;
int HalteState = 10; // lama di halte
int Keberangkatan = 0;
uint32_t tmp_halte;

const char* topicSoundHalteA = "sound/haltea";
const char* topicSoundHalteB = "sound/halteb";
const char* topicSalam = "sound/salam";

void stopAll() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void forwardLR(uint8_t vL, uint8_t vR) {
    // kiri maju
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, vL);
    // kanan maju
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, vR);
}

// Gerakan utama
void goStraight()        { forwardLR(vMax,   vMax  ); }
void turnLeftSoft()      { forwardLR(vMax,   vSoft ); }
void turnLeftHard()      { forwardLR(vMax,   vHard ); }
void turnRightSoft()     { forwardLR(vSoft,  vMax  ); }
void turnRightHard()     { forwardLR(vHard,  vMax  ); }

void LineFollow(){
    b1 = !digitalRead(S1);
    b2 = !digitalRead(S2);
    b3 = !digitalRead(S3);
    b4 = !digitalRead(S4);
    b5 = !digitalRead(S5);

    // susun jadi pola bit b1..b5 → bit4..bit0
    uint8_t pat = (b1<<4) | (b2<<3) | (b3<<2) | (b4<<1) | b5;

    switch(pat) {
    // STOP
        case 0b11111:
            stopAll();
            posisi = "🛑";
            break;
        case 0b00000:
            stopAll();
            posisi = "🛑";
            break;    
    // MAJU LURUS
        case 0b01110:
            goStraight();
            posisi = "⬆️";
            break;
        case 0b00100:
            goStraight();
            posisi = "⬆️";
            break;

    // BELIK KIRI RINGAN
        case 0b01000:
            turnLeftSoft();
            posisi = "↖️";
            break;
        case 0b01100:
            turnLeftSoft();
            posisi = "↖️";
            break;
        case 0b11100:
            turnLeftSoft();
            posisi = "↖️";
            break;
        case 0b11110:
            turnLeftSoft();
            posisi = "↖️";
            break;

    // BELIK KIRI TAJAM
        case 0b10000:
            turnLeftHard();
            posisi = "⬅️";
            break;
        case 0b11000:
            turnLeftHard();
            posisi = "⬅️";
            break;

    // BELIK KANAN RINGAN
        case 0b00010:
            turnRightSoft();
            posisi = "↗️";
            break;
        case 0b00110:
            turnRightSoft();
            posisi = "↗️";
            break;
        case 0b00111:
            turnRightSoft();
            posisi = "↗️";
            break;
        case 0b01111:
            turnRightSoft();
            posisi = "↗️";
            break;

    // BELIK KANAN TAJAM: S4+S5 hitam → 0b00011
        case 0b00001:
            turnRightHard();
            posisi = "➡️";
            break;
        case 0b00011:
            turnRightHard();
            posisi = "➡️";
            break;

    // pola lain
        default:
            goStraight();
            posisi = "⬆️";
            break;
    }
}

void lineFollowerTask(void *param) {while (true){
    
    IrLoop();
    if(H1 == ir_data & tmp_halte != H1) {
        Keberangkatan = HalteState;
        stopAll();
        client.publish(topicSoundHalteA, "1"); // Kirim nilai 1 ke topicSoundHalteA
        while (Keberangkatan > 1){
            Keberangkatan--;
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        tmp_halte = H1;
    } else if(H2 == ir_data & tmp_halte != H2){
        Keberangkatan = HalteState;
        stopAll();
        while (Keberangkatan > 1){
            Keberangkatan--;
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        tmp_halte = H2;
    } else if(R_MERAH_L1 == ir_data || R_MERAH_L2 == ir_data) {
        stopAll();
    } else if(R_KUNING_L1 == ir_data || R_KUNING_L2 == ir_data) {
        stopAll();
    } else if(R_HIJAU_L1 == ir_data || R_HIJAU_L2 == ir_data) {
        LineFollow();
    } else {
        LineFollow();
    }
    
    vTaskDelay(20 / portTICK_PERIOD_MS);
}}