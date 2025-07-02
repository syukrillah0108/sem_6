#include <IRremote.hpp>

const int IR_SEND_PIN = 4;

void setup() {
  Serial.begin(115200);
  IrSender.begin(IR_SEND_PIN); 
}

void loop() {
  if (IrReceiver.decode()) {
    // Cetak kode IR singkat
    Serial.print("Kode IR diterima: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    // Tampilkan pesan berdasarkan tombol remote
    switch (IrReceiver.decodedIRData.command) {
      case 0x10:
        Serial.println("Pesan: Tombol POWER ditekan");
        break;
      case 0x11:
        Serial.println("Pesan: Tombol VOLUME UP ditekan");
        break;
      case 0x12:
        Serial.println("Pesan: Tombol VOLUME DOWN ditekan");
        break;
      case 0x20:
        Serial.println("Pesan: Tombol NEXT ditekan");
        break;
      case 0x21:
        Serial.println("Pesan: Tombol PREVIOUS ditekan");
        break;
      default:
        Serial.println("Pesan: Tombol tidak dikenali");
        break;
    }

    IrReceiver.resume();  // Siap menerima sinyal selanjutnya
  }
}
