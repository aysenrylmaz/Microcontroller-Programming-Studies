const int ledPins[] = {2, 3, 4, 5, 6, 7, 8}; // LED pinleri
const int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]); // LED sayısı
const int num1 = 3; // İlk sayı
const int num2 = 4; // İkinci sayı
int result; // Sonuç

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT); // LED pinlerini çıkış olarak ayarla
  }
  result = (num1 + num2) * (num1 + num2); // İki sayının toplamının ikinci kuvvetini hesapla
}

void loop() {
  displayResult(); // Sonucu LED dizisiyle göster
}

void displayResult() {
  for (int i = 0; i < numLEDs; i++) {
    if (result & (1 << i)) { // İlgili bit 1 ise, LED'i yak
      digitalWrite(ledPins[i], HIGH);
    } else { // İlgili bit 0 ise, LED'i söndür
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(1000); // 1 saniye bekle
}