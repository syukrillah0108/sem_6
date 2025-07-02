#define ENA 3
#define ENB 12

// Motor A - Maju/Mundur
#define IN1  5
#define IN2  7

// Motor B - Belok
#define IN3  9
#define IN4  11

int speed = 100; // Kecepatan motor
int torsiBelok = 180; // Kecepatan belok
int state_berhenti = 10000; // 10 detik

bool autoMode = false; // Mode otomatis

void setup_motor(){
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void motorMaju() {
    analogWrite(ENA, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
}

void motorMundur() {
    analogWrite(ENA, speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}

void belokKiri() {
    analogWrite(ENB, torsiBelok);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void belokKanan() {
    analogWrite(ENB, torsiBelok);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void lurus() {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void motorStop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

void read_line_sensors() {
    S1 = !digitalRead(PINSENSOR_KIRI);
    S2 = !digitalRead(PINSENSOR_TENGAH);
    S3 = !digitalRead(PINSENSOR_KANAN);
    if (!S1 && !S2 && !S3) { // 0 | 0 | 0
        Serial.println("bergerak maju");
        lurus();
        motorMaju();
    } else if (S1 && S2 && S3) { // 1 | 1 | 1
        Serial.println("bergerak maju");
        lurus();
        motorMaju();
    } else if (S1 && !S2 && !S3) { // 1 | 0 | 0
        Serial.println("belok kiri");
        belokKiri();
        motorMaju();
    } else if (S1 && S2 && !S3) { // 1 | 1 | 0
        Serial.println("belok kiri");
        belokKiri();
        motorMaju();
    }else if (!S1 && S2 && !S3) {  // 0 | 1 | 0
        Serial.println("bergerak maju");
        lurus();
        motorMaju();
    } else if (!S1 && S2 && S3) { // 0 | 1 | 1
        Serial.println("belok kanan");
        belokKanan();
        motorMaju();
    } else if (S1 && S2 && !S3) { // 0 | 0 | 1
        Serial.println("belok kanan");
        belokKanan();
        motorMaju();
    } else {
        Serial.println("Tidak ada sensor yang aktif, berhenti");
        lurus();
        motorStop();
    }
}
void line_following(void *param) {
    while (true){
        IrLoop();
        if (ir_data == R_MERAH_L1 || ir_data == R_MERAH_L2) {
            Serial.println("Lampu Merah, berhenti");
            lurus();
            motorStop();
        } else if (ir_data == R_KUNING_L1 || ir_data == R_KUNING_L2) {
            Serial.println("Lampu Kuning, bersiap-siap");
            lurus();
            motorMaju();
        } else if (ir_data == R_HIJAU_L1 || ir_data == R_HIJAU_L2) {
            Serial.println("Lampu Hijau, lanjutkan");
            read_line_sensors(); // Baca sensor garis
        } else if (ir_data == H1 || ir_data == H2) {
            Serial.println("Halte terdeteksi, berhenti selama 10 detik");
            lurus();
            motorStop();
            vTaskDelay(state_berhenti / portTICK_PERIOD_MS); // Berhenti selama 10 detik
            // memastikan mobil tidak di daerah IR Halte
            lurus();
            motorMaju();
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    
}