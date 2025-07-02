bool S1, S2, S3 = false;

// Sensor Line
#define PINSENSOR_KIRI   6
#define PINSENSOR_TENGAH 4
#define PINSENSOR_KANAN  2

void setup_sensor() {
    pinMode(PINSENSOR_KIRI, INPUT);
    pinMode(PINSENSOR_TENGAH, INPUT);
    pinMode(PINSENSOR_KANAN, INPUT);
}