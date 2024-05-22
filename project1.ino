int sensePin=0;
int temperaturePin=1;
int ledPin=9;
int servoPin=10;
void setup() {
  // put your setup code here, to run once:
analogReference(DEFAULT);
pinMode(ledPin,OUTPUT);
pinMode(servoPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(sensePin));
delay(500);
Serial.println(analogRead(temperaturePin));
delay(500);

int valLed=analogRead(sensePin);
int valTemp=analogRead(temperaturePin);

valLed= constrain(valLed,3,30);
int ledLevel=map(valLed,3,30,15,0);

analogWrite(ledPin,ledLevel);

if(valLed>30 & valTemp>500)
digitalWrite(servoPin,HIGH);
else digitalWrite(servoPin,LOW);


//if(val<400) digitalWrite(ledPin,HIGH);
//else digitalWrite(ledPin,LOW);

}
