#include <Stepper.h>

#define STEPS 2048         // Adım motoru dönme adım sayısı
#define motorPin1 8        // Adım motoru sürücüsünün bağlı olduğu pin 1
#define motorPin2 9        // Adım motoru sürücüsünün bağlı olduğu pin 2
#define motorPin3 10       // Adım motoru sürücüsünün bağlı olduğu pin 3
#define motorPin4 11       // Adım motoru sürücüsünün bağlı olduğu pin 4
#define buttonPin 2        // Butonun bağlı olduğu pin

Stepper myStepper(STEPS, motorPin1, motorPin2, motorPin3, motorPin4);
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Butona basıldığında, kapıyı kapatmak için motoru geriye döndür
    myStepper.setSpeed(50);  // Motor hızını ayarla (dönüş hızı)
    myStepper.step(-STEPS);  // Adım motorunu geriye döndür
    delay(1000);             // Kısa bir bekleme süresi ekle
  } else {
    // Buton serbest bırakıldığında, kapıyı açmak için motoru ileri döndür
    myStepper.setSpeed(50);  // Motor hızını ayarla (dönüş hızı)
    myStepper.step(STEPS);   // Adım motorunu ileri döndür
    delay(1000);             // Kısa bir bekleme süresi ekle
  }
}