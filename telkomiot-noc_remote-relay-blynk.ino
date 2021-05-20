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
char auth[] = "blynk_auth";
char ssid[] = "wifi_ssid";
char pass[] = "wifi_password";
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
  hum = dht.readTemperature();
  temp = dht.readHumidity();
  Blynk.virtualWrite (V2, temp);
  Blynk.virtualWrite (V3, hum);
  Serial.print(temp);
  Serial.print("°C, ");
  Serial.print(hum);
  Serial.println(" %");
  delay(250);
}
