#include <dht11.h>

#define DHTPIN_1 2     // DHT11 sensörlerinin bağlı olduğu pinler
#define DHTPIN_2 3
#define ANALOG_PIN A0  // Analog sensörlerin bağlı olduğu pin

#define DHTTYPE DHT11   // DHT tipi 

dht DHT_1;
dht DHT_2;

void setup() {
  Serial.begin(9600);
  Serial.println("Akıllı Ev Sistemi Başlatılıyor...");
}

void loop() {
  delay(2000);  // 2 saniye bekleyelim

  // İlk DHT11 sensöründen sıcaklık ve nem verilerini okuyalım
  int16_t humidity_1 = DHT_1.readHumidity();
  int16_t temperature_1 = DHT_1.readTemperature();

  // İkinci DHT11 sensöründen sıcaklık ve nem verilerini okuyalım
  int16_t humidity_2 = DHT_2.readHumidity();
  int16_t temperature_2 = DHT_2.readTemperature();

  // Analog sensörden veriyi okuyalım (örneğin LDR)
  int lightIntensity = analogRead(ANALOG_PIN);

  // Verileri seri monitöre yazdıralım
  Serial.println("Sensör 1:");
  Serial.print("Sıcaklık: ");
  Serial.print(temperature_1);
  Serial.print(" °C\t");
  Serial.print("Nem: ");
  Serial.print(humidity_1);
  Serial.println(" %");

  Serial.println("Sensör 2:");
  Serial.print("Sıcaklık: ");
  Serial.print(temperature_2);
  Serial.print(" °C\t");
  Serial.print("Nem: ");
  Serial.print(humidity_2);
  Serial.println(" %");

  Serial.print("Işık Şiddeti: ");
  Serial.println(lightIntensity);
}