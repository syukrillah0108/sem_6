#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// ---------------------- Konfigurasi -------------------------
const char* ssid = "syukrillah-MEGABOOK-T14DA";
const char* password = "ec8k0SoA";
const char* mqtt_server = "10.42.0.1";
const char* mqtt_user = "user1";
const char* mqtt_password = "1234567890";

const char* device_id = "tl1";

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
unsigned long phaseStartTime = 0;
unsigned long phaseDuration = redDelay;
unsigned long lastMQTTSend = 0;

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
  client.publish("trafficlight/state1", buffer, true);
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

  if (String(topic) == "trafficlight/config/delay") {
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
    if (client.connect("TrafficLightClient", mqtt_user, mqtt_password)) {
      Serial.println("berhasil.");
      client.subscribe("trafficlight/config/delay");
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

// ---------------------- Setup --------------------------
void setup() {
  Serial.begin(115200);
  setup_wifi();

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // Set kondisi awal lampu (RED)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  currentColor = "RED";
  previousColor = "";
  phaseStartTime = millis();
  phaseDuration = redDelay;
}

// ---------------------- Loop --------------------------
void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  unsigned long now = millis();
  unsigned long elapsed = now - phaseStartTime;

  // Hitung countdown
  unsigned long countdown = (phaseDuration > elapsed) ? (phaseDuration - elapsed) / 1000 : 0;

  // Kirim JSON per detik
  if (now - lastMQTTSend >= 1000) {
    lastMQTTSend = now;
    sendStateJSON(countdown);
  }

  // Jika waktunya habis, ganti lampu
  if (elapsed >= phaseDuration) {
    phaseStartTime = now;

    if (currentColor == "RED") {
      currentColor = "YELLOW";
      previousColor = "RED";
      phaseDuration = yellowDelay;
      digitalWrite(RED_PIN, LOW);
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);

    } else if (currentColor == "YELLOW" && previousColor == "RED") {
      currentColor = "GREEN";
      previousColor = "YELLOW";
      phaseDuration = greenDelay;
      digitalWrite(RED_PIN, LOW);
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);

    } else if (currentColor == "GREEN") {
      currentColor = "YELLOW";
      previousColor = "GREEN";
      phaseDuration = yellowDelay;
      digitalWrite(RED_PIN, LOW);
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);

    } else if (currentColor == "YELLOW" && previousColor == "GREEN") {
      currentColor = "RED";
      previousColor = "YELLOW";
      phaseDuration = redDelay;
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
    }
  }
}
