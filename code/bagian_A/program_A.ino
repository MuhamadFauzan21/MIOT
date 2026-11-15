
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <BH1750.h>
#include <ThingSpeak.h>

// Pengaturan Wi-Fi
const char* ssid = "NAMA_WIFI";
const char* password = "PASSWORD_WIFI";

// Pengaturan ThingSpeak
unsigned long channelID = 3563994;
const char* writeAPIKey = "API_KEY_THINGSPEAK";

WiFiClient client;
BH1750 lightMeter;

// Interval reconnect Wi-Fi
unsigned long previousReconnect = 0;
const unsigned long reconnectInterval = 5000;

// Interval pengiriman ThingSpeak
unsigned long previousSend = 0;
const unsigned long sendInterval = 30000;

void setup() {
  Serial.begin(9600);

  // Menghubungkan sensor BH1750
  Wire.begin(D2, D1);

  if (lightMeter.begin()) {
    Serial.println("BH1750 berhasil terhubung");
  } else {
    Serial.println("BH1750 gagal terhubung");
  }

  // Memulai koneksi Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Memulai koneksi Wi-Fi...");

  // Menghubungkan ThingSpeak
  ThingSpeak.begin(client);
}

void reconnectWiFi() {
  if (WiFi.status() != WL_CONNECTED) {

    unsigned long currentMillis = millis();

    if (currentMillis - previousReconnect >= reconnectInterval) {
      previousReconnect = currentMillis;

      Serial.println("Wi-Fi terputus. Mencoba reconnect...");

      WiFi.disconnect();
      WiFi.begin(ssid, password);
    }

  } else {
    // Wi-Fi sudah terhubung
  }
}

void loop() {

  // Memeriksa dan mencoba reconnect Wi-Fi
  reconnectWiFi();

  // Membaca intensitas cahaya
  float lux = lightMeter.readLightLevel();

  Serial.print("Intensitas Cahaya: ");
  Serial.print(lux);
  Serial.println(" lux");

  unsigned long currentMillis = millis();

  // Mengirim data setiap 30 detik
  if (currentMillis - previousSend >= sendInterval) {

    previousSend = currentMillis;

    if (WiFi.status() == WL_CONNECTED && lux >= 0) {

      ThingSpeak.setField(1, lux);
      ThingSpeak.setField(2, lux);

      int status = ThingSpeak.writeFields(
        channelID, writeAPIKey
      );

      if (status == 200) {
        Serial.println("Data berhasil dikirim ke ThingSpeak!");
      } else {
        Serial.print("Gagal mengirim data. Kode: ");
        Serial.println(status);
      }

    } else {
      Serial.println("Wi-Fi terputus atau pembacaan sensor gagal.");
    }
  }

  delay(100);
}

