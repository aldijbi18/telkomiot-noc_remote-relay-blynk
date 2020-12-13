#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define BLYNK_PRINT Serial
#define DHTTYPE DHT11
#define DHTPIN D4

DHT dht (DHTPIN, DHTTYPE);
int reboot;
float suhu, kelembaban;
char auth[] = "blynk_auth";
char ssid[] = "SSID";
char pass[] = "Password";
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
  Blynk.virtualWrite (V3, suhu);
  Blynk.virtualWrite (V4, kelembaban);
  Serial.print(suhu);
  Serial.print(", ");
  Serial.println(kelembaban);
  delay(250);
}
