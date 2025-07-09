#include <IRremote.hpp>

const int IR_SEND_PIN = 3;
// H1
#define H1           0x10A3
// H2
#define H2           0x10B3
/*
*/

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    IrSender.begin(IR_SEND_PIN);
}

void loop() {
    IrSender.sendNEC(H2, 32);
    digitalWrite(LED_BUILTIN, HIGH); // Nyalakan LED sebagai indikator
    delay(500); // Tunggu setengah detik
    digitalWrite(LED_BUILTIN, LOW); // Matikan LED
    delay(500); // Kirim sinyal setiap 1 detik
}
