#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

int IncomingValue;
char IncomingText;
int LED = 6;
bool ON = false;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (mySerial.available()){
    IncomingValue = mySerial.parseInt();
    Serial.println(IncomingValue);
    IncomingText = mySerial.read();
    switch (IncomingText)
    {
      case 'A':
        Serial.println("Slider");
        analogWrite(LED, IncomingValue);
        break;

      case 'B':
         Serial.println("Switch");
         if(ON == true)
         {
            digitalWrite(LED, LOW);
            ON = false;
         }
         else
         {
            digitalWrite(LED, HIGH);
            ON = true;
         }
         break;

      case 'C':
        Serial.println("On/Off");
        digitalWrite(LED, IncomingValue);
        break;

      default:
      break;
    }
  }
}
