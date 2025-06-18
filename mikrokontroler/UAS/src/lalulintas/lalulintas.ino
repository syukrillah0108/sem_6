#include <WiFi.h>
#include <PubSubClient.h>

// Pin lampu lalu lintas
#define RED_PIN 3
#define YELLOW_PIN 2
#define GREEN_PIN 1

// MQTT & WiFi config
const char* ssid = "syukrillah-MEGABOOK-T14DA";
const char* password = "ec8k0SoA";
const char* mqtt_server = "10.42.0.1";
const char* mqtt_user = "user1";
const char* mqtt_password = "1234567890";


WiFiClient espClient;
PubSubClient client(espClient);

// Default delay (ms)
unsigned long redDelay = 5000;
unsigned long yellowDelay = 1000;
unsigned long greenDelay = 5000;

void sendState(const char* state) {
    client.publish("trafficlight/state1", state, true);
    Serial.print("Send state: ");
    Serial.println(state);
}

void callback(char* topic, byte* payload, unsigned int length) {
    String msg;
    for (unsigned int i = 0; i < length; i++) {
        msg += (char)payload[i];
    }
    Serial.print("Received [");
    Serial.print(topic);
    Serial.print("]: ");
    Serial.println(msg);

    // Topic: trafficlight/delay/red, /yellow, /green
    if (String(topic) == "trafficlight/delay/red") {
        redDelay = msg.toInt();
        Serial.print("Red delay updated: ");
        Serial.println(redDelay);
    } else if (String(topic) == "trafficlight/delay/yellow") {
        yellowDelay = msg.toInt();
        Serial.print("Yellow delay updated: ");
        Serial.println(yellowDelay);
    } else if (String(topic) == "trafficlight/delay/green") {
        greenDelay = msg.toInt();
        Serial.print("Green delay updated: ");
        Serial.println(greenDelay);
    }
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("TrafficLightClient", mqtt_user, mqtt_password)) {
            Serial.println("connected");
            client.subscribe("trafficlight/delay/red");
            client.subscribe("trafficlight/delay/yellow");
            client.subscribe("trafficlight/delay/green");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 2 seconds");
            delay(2000);
        }
    }
}

void setup_wifi() {
    delay(10);
    Serial.begin(115200);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("keniksi ke wifi.... \n");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void trafficLightTask(void *pvParameters) {
    (void) pvParameters;
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);

    while (1) {
        // Merah
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(YELLOW_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        sendState("RED");
        Serial.println("Lampu: MERAH");
        vTaskDelay(pdMS_TO_TICKS(redDelay));

        // Kuning
        digitalWrite(RED_PIN, LOW);
        digitalWrite(YELLOW_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        sendState("YELLOW");
        Serial.println("Lampu: KUNING");
        vTaskDelay(pdMS_TO_TICKS(yellowDelay));

        // Hijau
        digitalWrite(RED_PIN, LOW);
        digitalWrite(YELLOW_PIN, LOW);
        digitalWrite(GREEN_PIN, HIGH);
        sendState("GREEN");
        Serial.println("Lampu: HIJAU");
        vTaskDelay(pdMS_TO_TICKS(greenDelay));

        // Kuning (lagi)
        digitalWrite(RED_PIN, LOW);
        digitalWrite(YELLOW_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        sendState("YELLOW");
        Serial.println("Lampu: KUNING (lagi)");
        vTaskDelay(pdMS_TO_TICKS(yellowDelay));
    }
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);

    xTaskCreatePinnedToCore(
        trafficLightTask,
        "TrafficLight",
        2048,
        NULL,
        1,
        NULL,
        0
    );
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}