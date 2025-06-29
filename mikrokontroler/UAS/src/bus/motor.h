#define ENA 14
#define ENB 32

// Motor A - Maju/Mundur
#define IN1  27
#define IN2  26

// Motor B - Belok
#define IN3  25
#define IN4  33

int speed = 100; // Kecepatan motor
int torsiBelok = 180; // Kecepatan belok

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

void line_following() {
    baca_sensor();
    if (S1 && S2 && S3) {
        Serial.println("Semua sensor aktif, bergerak maju");
        lurus();
        motorMaju();
    } else if (S1 && !S2 && !S3) {
        Serial.println("Sensor kiri aktif, belok kiri");
        belokKiri();
        motorMaju();
    } else if (!S1 && !S2 && S3) {
        Serial.println("Sensor kanan aktif, belok kanan");
        belokKanan();
        motorMaju();
    } else if (!S1 && S2 && !S3) {
        Serial.println("Sensor tengah aktif, lurus");
        lurus();
        motorMaju();
    } else if (!S1 && !S2 && !S3) {
        Serial.println("Tidak ada sensor yang aktif, berhenti");
        lurus();
        motorStop();
    } else {
        Serial.println("Tidak ada sensor yang aktif, berhenti");
        lurus();
        motorStop();
    }
    delay(500);
}