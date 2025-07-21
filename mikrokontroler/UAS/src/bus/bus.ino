#include <LineFollower.h>
#include <config.h>

void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    setupMotor();
    setupSensor();
    IrBegin();
    setup_wifi();
    setup_mqtt();
    // koenk ke wifi
    
    xTaskCreatePinnedToCore(
        mqttClientTask, "MQTT Client",
        4096, NULL, 1,
        &mqttTaskHandle, 0
        );
        
    xTaskCreatePinnedToCore(
        publishDebug, "Publish Debug",
        4096, NULL, 1,
        NULL, 0
        );
    
    //,setlineFollowerTask(true);
            /*
            */
}

void loop(){

}