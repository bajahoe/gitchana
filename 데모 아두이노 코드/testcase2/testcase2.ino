#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 7); 
// 심정지시의 동작
int heartValue=70;
int count=15;
void setup() {
  BTSerial.begin(115200);
  Serial.begin(115200);
}
void loop() {
  char a[10];
  sprintf(a,"%d",heartValue);
  BTSerial.print(a);
  Serial.println(a);
  if(heartValue==0)
    delay(20000);
  if(count==5){
    if(heartValue!=0){
      heartValue-=10;
      }
      count++;
    }
    count--;
    delay(1000);
}     
