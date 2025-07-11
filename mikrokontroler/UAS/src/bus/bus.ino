#include <LineFollower.h>
#include <config.h>

void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    setupMotor();
    setupSensor();
    IrBegin();
    /*
    setup_wifi();
    setup_mqtt();
    // koenk ke wifi
    
    xTaskCreatePinnedToCore(
        mqttClientTask, "MQTT Client",
        4096, NULL, 1,
        &mqttTaskHandle, 0
    );
    
    xTaskCreatePinnedToCore(
        publishDebug, "Publish Debug",
        4096, NULL, 1,
        NULL, 0
    );
    */
}

void loop(){

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
    
    // MAJU LURUS
        case 0b00000:
            goStraight();
            posisi = "⬆️";
            break;
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
            stopAll();
            posisi = "🛑";
            break;
    }

    vTaskDelay(20 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(20 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);

}