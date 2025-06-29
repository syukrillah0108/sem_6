#include <sensor.h>
#include <motor.h>
#include <config.h>

void setup(){
    Serial.begin(9600);
    setup_sensor();
    setup_wifi();
    setup_mqtt();
}

void loop(){
    client.loop();
    delay(100);
}