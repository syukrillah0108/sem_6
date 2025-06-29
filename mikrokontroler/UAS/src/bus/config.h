#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "syukrillah-MEGABOOK-T14DA";
const char *password = "ec8k0SoA";

#define MQTT_SERVER "10.42.0.1"
#define MQTT_PORT 1883
#define MQTT_USERNAME "user1"
#define MQTT_PASSWORD "1234567890"

WiFiClient espClient;
PubSubClient client(espClient);

const char* topicMode = "mode/mobil"; // manuall/auto
const char* topicKendali = "kendali/mobil";

const char* topicSpeed = "speed/mobil"; // Kecepatan motor
const char* topicTorsiBelok = "torsi/belok"; // Torsi belok

const char* topicSensor = "mobil/sensor";

void callback(char* topic, byte* payload, unsigned int length) {
    String msg;
    for (int i = 0; i < length; i++) {
        msg += (char)payload[i];
    }

    Serial.print("Pesan masuk [");
    Serial.print(topic);
    Serial.print("]: ");
    Serial.println(msg);

    if (String(topic) == topicKendali) {
        if (msg == "MAJU") {
            Serial.println("Maju");
            motorMaju();
        } else if (msg == "MUNDUR") {
            Serial.println("Mundur");
            motorMundur();
        } else if (msg == "KIRI") {
            Serial.println("Kiri");
            belokKiri();
        } else if (msg == "KANAN") {
            Serial.println("Kanan");
            belokKanan();
        } else if (msg == "BERHENTI") {
            Serial.println("Berhenti");
            motorStop();
        } else if (msg == "LURUS") {
            Serial.println("Lurus");
            lurus();
        } else {
            Serial.println("Perintah tidak dikenali");
        }
    } else if (String(topic) == topicMode) {
        if (msg == "MANUAL") {
            Serial.println("Mode Manual");
            // Tambahkan logika untuk mode manual jika diperlukan
        } else if (msg == "AUTO") {
            Serial.println("Mode Otomatis");
            // Tambahkan logika untuk mode otomatis jika diperlukan
        } else {
            Serial.println("Mode tidak dikenali");
        }
    } else if (String(topic) == topicSpeed) {
        speed = msg.toInt();
        Serial.print("Kecepatan diatur ke: ");
        Serial.println(speed);
    } else if (String(topic) == topicTorsiBelok) {
        torsiBelok = msg.toInt();
        Serial.print("Torsi belok diatur ke: ");
        Serial.println(torsiBelok);
    }
}

void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Menghubungkan ke ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi terhubung");
    Serial.print("Alamat IP: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Mencoba menghubungkan ke broker MQTT...");
        
        if (client.connect("ESP32Client", MQTT_USERNAME, MQTT_PASSWORD)) {
            Serial.println("terhubung");
            client.subscribe(topicKendali);
            client.subscribe(topicMode);
            client.subscribe(topicSpeed);
            client.subscribe(topicTorsiBelok);
        } else {
            Serial.print("Gagal, rc=");
            Serial.print(client.state());
            Serial.println(" mencoba lagi dalam 5 detik");
            delay(1000);
        }
    }
}

void setup_mqtt() {
    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);
    reconnect();
}