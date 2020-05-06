#include <SoftwareSerial.h>
#define heartPin A1
SoftwareSerial BTSerial(4, 7); 

void setup() {
  BTSerial.begin(115200);
  Serial.begin(115200);
}
void loop() {
  int heartValue = 60000/analogRead(heartPin);
  char a[10];
  sprintf(a,"%d",heartValue);
  BTSerial.print(a);
  Serial.println(a);
  delay(1000);
}     
