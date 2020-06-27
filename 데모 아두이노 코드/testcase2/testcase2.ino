#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 7); 
// 심정지시의 동작
int heartValue=70;
int count=15;
 //Analog 0 번에 센서핀 연결
int redPin = 3;
int greenPin = 5;

void setup() {
  BTSerial.begin(115200);
  Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
void loop() {
  char a[10];
  sprintf(a,"%d",heartValue);
  char b[10] = "36 ";
  strcat(b, a);
  BTSerial.print(b);
  Serial.println(b);
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
    if(heartValue>60 && heartValue<100)
    setColor(0, 255, 0); // Normal, 촑
  else if (heartValue<=5)
    setColor(255, 0, 0); // Emer, 빩
  else
    setColor(255, 127, 0); // Warn, 좡

}


void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  //analogWrite(bluePin, blue); 
}
