#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

#define ANALOG_PIN A0   // Nem sensörünün bağlı olduğu analog pin
#define SOIL_MOISTURE_THRESHOLD 500 // Toprak nem eşiği
#define SOIL_MOISTURE_PUMP_PIN 2    // Toprak nemlendirici için kontrol pini
#define SPEAKER_PIN 3    // Hoparlörün bağlı olduğu dijital pin

DFRobotDFPlayerMini mp3;

void setup() {
  Serial.begin(9600);
  pinMode(SOIL_MOISTURE_PUMP_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  
  if (!mp3.begin(Serial1)) {
    Serial.println(F("MP3 modülü bulunamadı!"));
    while (true);
  }

  mp3.volume(20); // Ses seviyesi (0-30 arası)
  mp3.loopAll(false); // Parçaların tekrar oynatılmasını engelle
}

void loop() {
  int soilMoisture = analogRead(ANALOG_PIN);

  if (soilMoisture < SOIL_MOISTURE_THRESHOLD) {
    // Toprak nem seviyesi eşiğin altındaysa, toprak nemlendiriciyi çalıştır
    digitalWrite(SOIL_MOISTURE_PUMP_PIN, HIGH);
    playMusic();
  } else {
    digitalWrite(SOIL_MOISTURE_PUMP_PIN, LOW);
  }
}

void playMusic() {
  // Müzik çalma işlevi
  mp3.playMp3Folder(1); // Müzik çalma
  delay(5000); // Müzik çalma süresi (milisaniye cinsinden)
}