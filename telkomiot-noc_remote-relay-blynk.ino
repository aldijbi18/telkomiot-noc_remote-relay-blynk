// Created by @aldijbi18
// Date : 03 October 2020

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define BLYNK_PRINT Serial
#define DHTTYPE DHT11
#define DHTPIN D4

DHT dht (DHTPIN, DHTTYPE);
int reboot;
float temp, hum;
char auth[] = "Blynk_auth";
char ssid[] = "WiFi_SSID";
char pass[] = "WiFi_Password";
BLYNK_WRITE(V1)
{
  reboot = param.asInt();
}
int relay = D2;
void setup() {
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  if (reboot == 1) {
    digitalWrite(relay, LOW);
    delay(200);
    digitalWrite(relay, HIGH);
    delay(2000);
  }
  kelembaban = dht.readHumidity();
  suhu = dht.readTemperature();
  Blynk.virtualWrite (V3, temp);
  Blynk.virtualWrite (V4, hum);
  Serial.print(hum);
  Serial.print(", ");
  Serial.println(hum);
  delay(250);
}