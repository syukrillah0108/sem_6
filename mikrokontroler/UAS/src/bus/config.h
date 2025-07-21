const char *ssid = "syukrillah-MEGABOOK-T14DA";
const char *password = "ec8k0SoA";

#define MQTT_SERVER "10.42.0.1"
#define MQTT_PORT 1883
#define MQTT_USERNAME "user1"
#define MQTT_PASSWORD "1234567890"

TaskHandle_t mqttTaskHandle = NULL;
TaskHandle_t lineFollowerTaskHandle = NULL;

const char* topicMode = "mode/mobil"; // manuall/auto
const char* topicKendali = "kendali/mobil";

const char* topicSpeed = "speed/mobil"; // Kecepatan motor
const char* topicTorsiBelok = "torsi/belok"; // Torsi belok
const char* topicStateHalte = "state/halte"; // State halte
const char* topicBelokSedikit = "belok/sedikit";
const char* topicBelokTajam = "belok/tajam";
const char* topicPosisiMobil = "posisi/mobil"; // Posisi mobil
const char* topicKeberangkatanMobil = "berangkat/mobil"; // Brangkat mobil

const char* topicSensor = "mobil/sensor";
String data_sensor;

void setlineFollowerTask(bool x);

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
            forward();
        } else if (msg == "MUNDUR") {
            Serial.println("Mundur");
            backward();
        } else if (msg == "KIRI") {
            Serial.println("Kiri");
            left();
        } else if (msg == "KANAN") {
            Serial.println("Kanan");
            right();
        } else if (msg == "BERHENTI") {
            Serial.println("Berhenti");
            stop();
        } else {
            Serial.println("Perintah tidak dikenali");
        }
    } else if (String(topic) == topicMode) {
        if (msg == "MANUAL") {
            Serial.println("Mode Manual");
            setlineFollowerTask(false);
        } else if (msg == "AUTO") {
            Serial.println("Mode Otomatis");
            setlineFollowerTask(true);
        } else {
            Serial.println("Mode tidak dikenali");
        }
    } else if (String(topic) == topicSpeed) {
        vMax = msg.toInt();
        Serial.print("Kecepatan diatur ke: ");
        Serial.println(vMax);
    } else if (String(topic) == topicBelokSedikit) {
        vSoft = msg.toInt();
        Serial.print("Kecepatan belok sedikit diatur ke: ");
        Serial.println(vSoft);
    } else if (String(topic) == topicBelokTajam) {
        vHard = msg.toInt();
        Serial.print("Kecepatan belok tajam diatur ke: ");
        Serial.println(vHard);
    } else if (String(topic) == topicStateHalte) {
        HalteState = msg.toInt();
        Serial.print("State halte diatur ke: ");
        Serial.println(HalteState);
    } else {
        Serial.println("Topik tidak dikenali");
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

void  reconnect() {
    while (!client.connected()) {
        Serial.print("Mencoba menghubungkan ke broker MQTT...");
        if (client.connect("BUSClient", MQTT_USERNAME, MQTT_PASSWORD)) {
            Serial.println("terhubung");
            client.subscribe(topicKendali);
            client.subscribe(topicMode);
            client.subscribe(topicSpeed);
            client.subscribe(topicBelokSedikit);
            client.subscribe(topicBelokTajam);
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

void kirim_sensor() {
    String pesan = String(b1) + "," + String(b2) + "," + String(b3) + "," + String(b4) + "," + String(b5);
    
    client.publish(topicSensor, pesan.c_str());
    client.publish(topicPosisiMobil, posisi_bus.c_str());
    client.publish(topicKeberangkatanMobil, String(Keberangkatan).c_str());
}

void setlineFollowerTask(bool x){
    if (x == true){
        xTaskCreatePinnedToCore(
            lineFollowerTask, "Line Follower Task",
            4096, NULL, 1,
            &lineFollowerTaskHandle, 0
        );
    }else if ((x == false) & (lineFollowerTaskHandle != NULL)){;
        vTaskDelete(lineFollowerTaskHandle);
        lineFollowerTaskHandle = NULL;
    }
}

void mqttClientTask(void *param) {
    while (1) {
        if (!client.connected()) {
            reconnect();
        }
        client.loop();
        vTaskDelay(30 / portTICK_PERIOD_MS);
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(30 / portTICK_PERIOD_MS);
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void publishDebug(void *param) {
    while (true){
        kirim_sensor();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}