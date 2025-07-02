#include <IRremote.hpp>

const int IR_RECEIVE_PIN = D1;

#define R_MERAH_L1   0x85080000
#define R_KUNING_L1  0x8D080000
#define R_HIJAU_L1   0x83080000

#define R_MERAH_L2   0x45080000
#define R_KUNING_L2  0x4D080000
#define R_HIJAU_L2   0x43080000

#define H1           0xC5080000
#define H2           0xCD080000

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t data = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Data diterima: 0x");
    Serial.println(data, HEX);

    // Cek lampu lalu lintas
    if (data == R_MERAH_L1) {
      Serial.println("Lampu 1 Merah");
    } else if (data == R_KUNING_L1) {
      Serial.println("Lampu 1 Kuning");
    } else if (data == R_HIJAU_L1) {
      Serial.println("Lampu 1 Hijau");

    } else if (data == R_MERAH_L2) {
      Serial.println("Lampu 2 Merah");
    } else if (data == R_KUNING_L2) {
      Serial.println("Lampu 2 Kuning");
    } else if (data == R_HIJAU_L2) {
      Serial.println("Lampu 2 Hijau");

    // Cek halte
    } else if (data == H1) {
      Serial.println("Halte 1 Aktif");
    } else if (data == H2) {
      Serial.println("Halte 2 Aktif");
    } else {
      Serial.println("Data tidak dikenali");
    }

    IrReceiver.resume(); // Siap terima lagi
  }
}
