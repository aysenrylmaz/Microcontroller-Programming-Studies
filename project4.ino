#include <dht11.h>

#define DHT11PIN_1 2     // DHT11 sensörlerinin bağlı olduğu pinler
#define DHT11PIN_2 3
#define ANALOG_PIN A0  // Analog sensörlerin bağlı olduğu pin
#define GAS_PIN A1     // Gaz sensörünün bağlı olduğu pin

#define DHT11TYPE DHT11  

dht11 dht_1(DHTPIN_1, DHTTYPE);
dht11 dht_2(DHTPIN_2, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Akıllı Ev Sistemi Başlatılıyor...");
  dht_1.begin();
  dht_2.begin();
}

void loop() {
  delay(2000);  // 2 saniye bekleyelim

  // İlk DHT11 sensöründen sıcaklık ve nem verilerini okuyalım
  float humidity_1 = dht_1.readHumidity();
  float temperature_1 = dht_1.readTemperature();

  // İkinci DHT11 sensöründen sıcaklık ve nem verilerini okuyalım
  float humidity_2 = dht_2.readHumidity();
  float temperature_2 = dht_2.readTemperature();

  // Analog sensörden veriyi okuyalım (örneğin LDR)
  int lightIntensity = analogRead(ANALOG_PIN);

  // Gaz sensöründen veriyi okuyalım
  int gasValue = analogRead(GAS_PIN);

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

  Serial.print("Gaz Değeri: ");
  Serial.println(gasValue);
}
