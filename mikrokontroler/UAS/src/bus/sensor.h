#include <IRremote.hpp>

#define S1 3
#define S2 5
#define S3 7
#define S4 9
#define S5 11

const int IR_RECEIVE_PIN = 1;

#define R_MERAH_L1   0x85080000
#define R_KUNING_L1  0x8D080000
#define R_HIJAU_L1   0x83080000

#define R_MERAH_L2   0x45080000
#define R_KUNING_L2  0x4D080000
#define R_HIJAU_L2   0x43080000

#define H1           0xC5080000
#define H2           0xCD080000
uint32_t ir_data;
String posisi_bus;
void setupSensor() {
    pinMode(S1, INPUT_PULLUP);
    pinMode(S2, INPUT_PULLUP);
    pinMode(S3, INPUT_PULLUP);
    pinMode(S4, INPUT_PULLUP);
    pinMode(S5, INPUT_PULLUP);
}


void IrBegin(){
    IrReceiver.begin(IR_RECEIVE_PIN);
}

void IrLoop(){
    if (IrReceiver.decode()) {
        ir_data = IrReceiver.decodedIRData.decodedRawData;
        Serial.print("Data diterima: 0x");
        Serial.println(ir_data, HEX);

        // Cek lampu lalu lintas
        if (ir_data == R_MERAH_L1) {
            posisi_bus = "L1-M";
        } else if (ir_data == R_KUNING_L1) {
            posisi_bus = "L1-K";
        } else if (ir_data == R_HIJAU_L1) {
            posisi_bus = "L1-H";

        } else if (ir_data == R_MERAH_L2) {
            posisi_bus = "L2-M";
        } else if (ir_data == R_KUNING_L2) {
            posisi_bus = "L2-K";
        } else if (ir_data == R_HIJAU_L2) {
            posisi_bus = "L2-H";

        // Cek halte
        } else if (ir_data == H1) {
            posisi_bus = "H1";
        } else if (ir_data == H2) {
            posisi_bus = "H2";
        } else {
            posisi_bus = "";
        }
        IrReceiver.resume();
    }
}