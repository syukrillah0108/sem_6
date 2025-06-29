bool S1, S2, S3 = false;

// Sensor Line
#define PINSENSOR_KIRI   4
#define PINSENSOR_TENGAH 16
#define PINSENSOR_KANAN  17

void setup_sensor() {
    pinMode(PINSENSOR_KIRI, INPUT);
    pinMode(PINSENSOR_TENGAH, INPUT);
    pinMode(PINSENSOR_KANAN, INPUT);
}

void baca_sensor() {
    S1 = !digitalRead(PINSENSOR_KIRI);
    S2 = !digitalRead(PINSENSOR_TENGAH);
    S3 = !digitalRead(PINSENSOR_KANAN);

    Serial.print("Sensor Kiri: ");
    Serial.print(S1);
    Serial.print(" | Sensor Tengah: ");
    Serial.print(S2);
    Serial.print(" | Sensor Kanan: ");
    Serial.println(S3);
}

void kirim_sensor() {
    String pesan = String(S1) + "," + String(S2) + "," + String(S3);
    Serial.print("Kirim Sensor: ");
    Serial.println(pesan);

    /*
    if (client.publish(topicSensor, pesan.c_str())) {
        Serial.println("Data sensor terkirim");
    } else {
        Serial.println("Gagal mengirim data sensor");
    }
    */
}