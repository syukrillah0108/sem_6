#define ENA 40
#define ENB 17

// Motor A
#define IN1  38
#define IN2  36

// Motor B
#define IN3  34
#define IN4  21

uint8_t vMax   = 255;  // full speed
uint8_t vSoft  = 150;  // speed untuk tikungan ringan
uint8_t vHard  = 50;  // speed untuk tikungan tajam

void setupMotor(){
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void forward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, vMax);
    analogWrite(ENB, vMax);
}
void backward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, vMax);
    analogWrite(ENB, vMax);
}
void left() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, vMax);
    analogWrite(ENB, vMax);
}
void right() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, vMax);
    analogWrite(ENB, vMax);
}
void stop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}