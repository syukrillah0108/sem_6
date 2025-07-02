#include <IR.h>
#include <sensor.h>
#include <motor.h>
#include <config.h>
void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    setup_motor();
    setup_sensor();
    IrBegin();
    setup_wifi();
    setup_mqtt();
    // koenk ke wifi
    
    /*
    xTaskCreatePinnedToCore(
        mqttClientTask, "MQTT Client",
        4096, NULL, 1,
        &mqttTaskHandle, 0
    );
    
    xTaskCreatePinnedToCore(
        publishDebug, "Publish Debug",
        4096, NULL, 1,
        NULL, 1
    );
    */
}

void loop(){
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    vTaskDelay(50 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);

}