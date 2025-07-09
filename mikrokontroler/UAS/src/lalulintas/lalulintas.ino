#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <IRremote.hpp>

const int IR_SEND_PIN = 5;
/*
// L1
#define R_MERAH   0x10A1
#define R_KUNING  0x10B1
#define R_HIJAU   0x10C1
*/
// L2
#define R_MERAH   0x10A2
#define R_KUNING  0x10B2
#define R_HIJAU   0x10C2

// ---------------------- Konfigurasi -------------------------
const char* ssid = "syukrillah-MEGABOOK-T14DA";
const char* password = "ec8k0SoA";
const char* mqtt_server = "10.42.0.1";
const char* mqtt_user = "user1";
const char* mqtt_password = "1234567890";

// ---------------------- MQTT Topic sub and Pub ----------------
const char* delay_topic = "trafficlight/config/delay2";
const char* state_topic = "trafficlight/state2";
const char* client_topic = "TrafficClient2";

const char* device_id = "tl2";

#define RED_PIN 3
#define YELLOW_PIN 2
#define GREEN_PIN 1

unsigned long redDelay = 5000;     // 5 detik
unsigned long yellowDelay = 1000;  // 1 detik
unsigned long greenDelay = 5000;   // 5 detik

// ---------------------- Objek WiFi & MQTT ---------------------
WiFiClient espClient;
PubSubClient client(espClient);

// ---------------------- Variabel Waktu & Warna ----------------
String currentColor = "RED";
String previousColor = "";

// ---------------------- Fungsi MQTT --------------------------
void sendStateJSON(unsigned long countdown) {
  StaticJsonDocument<256> doc;
  doc["id_device"] = device_id;
  doc["warna_lampu"] = currentColor;
  doc["waktu"] = countdown;

  char buffer[256];
  serializeJson(doc, buffer);
  Serial.print("[MQTT] Kirim JSON: ");
  Serial.println(buffer);
  client.publish(state_topic, buffer, true);
}

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  Serial.print("[MQTT] Terima [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(msg);

  if (String(topic) == delay_topic) {
    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, msg);
    
    if (error) {
      Serial.print("Gagal parsing JSON: ");
      Serial.println(error.c_str());
      return;
    }

    // Ambil nilai dari JSON dan konversi ke millisecond
    if (doc.containsKey("merah")) {
      redDelay = doc["merah"].as<unsigned long>() * 1000;
      Serial.print("Red delay: ");
      Serial.println(redDelay);
    }

    if (doc.containsKey("kuning")) {
      yellowDelay = doc["kuning"].as<unsigned long>() * 1000;
      Serial.print("Yellow delay: ");
      Serial.println(yellowDelay);
    }

    if (doc.containsKey("hijau")) {
      greenDelay = doc["hijau"].as<unsigned long>() * 1000;
      Serial.print("Green delay: ");
      Serial.println(greenDelay);
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("[MQTT] Menghubungkan...");
    if (client.connect(client_topic, mqtt_user, mqtt_password)) {
      Serial.println("berhasil.");
      client.subscribe(delay_topic);
    } else {
      Serial.print("gagal, rc=");
      Serial.print(client.state());
      Serial.println(" coba lagi dalam 2 detik.");
      delay(2000);
    }
  }
}

// ---------------------- Setup WiFi --------------------------
void setup_wifi() {
  delay(10);
  Serial.begin(115200);
  Serial.print("Menghubungkan WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi terhubung.");
  Serial.print("IP ESP32: ");
  Serial.println(WiFi.localIP());
}

// ---------------------- Task Lampu Lalulintas --------------------------
void trafficLightTask(void *pvParameters) {
  while (1) {
    // RED
    currentColor = "RED";
    previousColor = "";
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    for (int i = redDelay / 1000; i > 0; i--) {
      sendStateJSON(i);
      IrSender.sendNEC(R_MERAH, 32);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }

    // YELLOW setelah RED
    currentColor = "YELLOW";
    previousColor = "RED";
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    for (int i = yellowDelay / 1000; i > 0; i--) {
      sendStateJSON(i);
      IrSender.sendNEC(R_KUNING, 32);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }

    // GREEN
    currentColor = "GREEN";
    previousColor = "YELLOW";
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    for (int i = greenDelay / 1000; i > 0; i--) {
      sendStateJSON(i);
      IrSender.sendNEC(R_HIJAU, 32);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }

    // YELLOW setelah GREEN
    currentColor = "YELLOW";
    previousColor = "GREEN";
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    for (int i = yellowDelay / 1000; i > 0; i--) {
      sendStateJSON(i);
      IrSender.sendNEC(R_KUNING, 32);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }
}

// ---------------------- Setup --------------------------
void setup() {
  Serial.begin(115200);
  setup_wifi();
  IrSender.begin(IR_SEND_PIN);

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // Buat task di core 1
  xTaskCreatePinnedToCore(
    trafficLightTask,   // Fungsi task
    "TrafficLightTask", // Nama task
    4096,               // Stack size
    NULL,               // Parameter
    1,                  // Prioritas
    NULL,               // Handle
    0                   // Core 0
  );
}

// ---------------------- Loop --------------------------
void loop() {
  if (!client.connected()) reconnect();
  client.loop();
  vTaskDelay(pdMS_TO_TICKS(1000));
}
