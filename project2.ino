#include <dht11.h>    //Humidty and Temperature Sensor Library definition
#define DHT11PIN 5
dht11 DHT11;

#include <LiquidCrystal.h>     //LCD Screen Library definition
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

#include <Servo.h>   //Servo Motor Library definition
int servoPin=4;
int servoPos1=0;
int servoPos2=360;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  myServo.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println();

int chk = DHT11.read(DHT11PIN);
lcd.setCursor(0,0);
lcd.print("Hum: ");
lcd.print((float)DHT11.humidity, 2);
lcd.setCursor(0,1);
lcd.print("Temp: ");
lcd.print((float)DHT11.temperature, 2);
delay(2000);

if((float)DHT11.humidity>80)
{
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Cooler worked");
myServo.write(servoPos1);
delay(500);
myServo.write(servoPos2);
delay(500);
}


}
