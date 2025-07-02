#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 5;
// H1
#define H1           0x10A3
/*
// H2
#define H2           0x10B3
*/

// ---------------------- Setup --------------------------
void setup() {
    Serial.begin(115200);
    IrSender.begin(IR_SEND_PIN);
}

// ---------------------- Loop --------------------------
void loop() {
    IrSender.sendNEC(H1, 32);
    delay(1000); // Kirim sinyal setiap 1 detik
}
