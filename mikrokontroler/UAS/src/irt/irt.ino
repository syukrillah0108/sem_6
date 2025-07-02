#include <IRremote.hpp>

const int IR_SEND_PIN = D1;

// Kode IR sama dengan penerima
#define R_MERAH_L1   0x10A1
#define R_KUNING_L1  0x10B1
#define R_HIJAU_L1   0x10C1

#define R_MERAH_L2   0x10A2
#define R_KUNING_L2  0x10B2
#define R_HIJAU_L2   0x10C2

#define H1           0x10A3
#define H2           0x10B3

void setup() {
  Serial.begin(115200);
  IrSender.begin(IR_SEND_PIN);
}

void loop() {
  // Contoh kirim semua data IR berurutan
  static int step = 0;

  switch (step) {
    case 0:
      IrSender.sendNEC(R_MERAH_L1, 32);
      Serial.println("Kirim: Lampu 1 Merah");
      break;
    case 1:
      IrSender.sendNEC(R_KUNING_L1, 32);
      Serial.println("Kirim: Lampu 1 Kuning");
      break;
    case 2:
      IrSender.sendNEC(R_HIJAU_L1, 32);
      Serial.println("Kirim: Lampu 1 Hijau");
      break;
    case 3:
      IrSender.sendNEC(R_MERAH_L2, 32);
      Serial.println("Kirim: Lampu 2 Merah");
      break;
    case 4:
      IrSender.sendNEC(R_KUNING_L2, 32);
      Serial.println("Kirim: Lampu 2 Kuning");
      break;
    case 5:
      IrSender.sendNEC(R_HIJAU_L2, 32);
      Serial.println("Kirim: Lampu 2 Hijau");
      break;
    case 6:
      IrSender.sendNEC(H1, 32);
      Serial.println("Kirim: Halte 1 Aktif");
      break;
    case 7:
      IrSender.sendNEC(H2, 32);
      Serial.println("Kirim: Halte 2 Aktif");
      break;
  }

  step = (step + 1) % 8; // Ulangi siklus
  delay(3000);
}
