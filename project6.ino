#include <Stepper.h>

#define STEPS 2048         // Adım motoru dönme adım sayısı
#define motorPin1 8        // Adım motoru sürücüsünün bağlı olduğu pin 1
#define motorPin2 9        // Adım motoru sürücüsünün bağlı olduğu pin 2
#define motorPin3 10       // Adım motoru sürücüsünün bağlı olduğu pin 3
#define motorPin4 11       // Adım motoru sürücüsünün bağlı olduğu pin 4
#define sensorPin A0       // Işık sensörünün bağlı olduğu analog pin
#define threshold 500      // Perdeyi açmak veya kapatmak için eşik değeri

Stepper myStepper(STEPS, motorPin1, motorPin2, motorPin3, motorPin4);

void setup() {
  pinMode(sensorPin, INPUT);
}

void loop() {
  int lightLevel = analogRead(sensorPin); // Işık seviyesini oku

  if (lightLevel < threshold) {
    // Işık seviyesi eşik değerinin altındaysa, perdeyi kapat
    myStepper.setSpeed(50);  // Motor hızını ayarla (dönüş hızı)
    myStepper.step(-STEPS);  // Adım motorunu geriye döndür
    delay(1000);             // Kısa bir bekleme süresi ekle
  } else {
    // Işık seviyesi eşik değerinin üstündeyse, perdeyi aç
    myStepper.setSpeed(50);  // Motor hızını ayarla (dönüş hızı)
    myStepper.step(STEPS);   // Adım motorunu ileri döndür
    delay(1000);             // Kısa bir bekleme süresi ekle
  }
}