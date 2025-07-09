// === PIN SETUP ===
#define S1 1
#define S2 2
#define S3 4
#define S4 6
#define S5 8

#define ENA 3
#define ENB 12

// Motor A
#define IN1  5
#define IN2  7

// Motor B
#define IN3  9
#define IN4  11

// PID constants
float Kp = 25;
float Kd = 15;
float Ki = 0;

int baseSpeed = 150;
int maxSpeed = 255;

int lastError = 0;
int integral = 0;

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int sensors[5];
  sensors[0] = digitalRead(S1);
  sensors[1] = digitalRead(S2);
  sensors[2] = digitalRead(S3);
  sensors[3] = digitalRead(S4);
  sensors[4] = digitalRead(S5);

  // Hitam = 1, Putih = 0
  int position = 0;
  int activeCount = 0;
  for (int i = 0; i < 5; i++) {
    if (sensors[i]) {
      position += (i - 2) * 100; // -200, -100, 0, 100, 200
      activeCount++;
    }
  }
  int error = 0;
  if (activeCount > 0) {
    error = position / activeCount;
  } else {
    // Jika tidak ada garis, gunakan error sebelumnya
    error = lastError;
  }

  // PID
  integral += error;
  int derivative = error - lastError;
  int correction = Kp * error + Kd * derivative + Ki * integral;
  correction /= 100; // Sesuaikan skala

  int leftSpeed = constrain(baseSpeed + correction, 0, maxSpeed);
  int rightSpeed = constrain(baseSpeed - correction, 0, maxSpeed);

  setMotor(leftSpeed, rightSpeed);

  lastError = error;
  delay(10); // Smooth response
}

void setMotor(int left, int right) {
  // Motor kiri (A)
  if (left >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    left = -left;
  }
  analogWrite(ENA, left);

  // Motor kanan (B)
  if (right >= 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    right = -right;
  }
  analogWrite(ENB, right);
}
