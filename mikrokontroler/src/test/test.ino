uint64_t test = 0x123456789ABCDEF0;
int64_t test2 = 0x123456789ABCDEF0;
int32_t test3 = 0x123456789ABCDEF0; 
//int16_t test3 = 0x1234ABC;
int8_t test4 = 0x12;

void setup(){
    Serial.begin(115200);

}

void loop(){
    Serial.println(test);
    Serial.println(test4);
    delay(1000);
}