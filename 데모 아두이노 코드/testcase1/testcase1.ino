#include <SoftwareSerial.h>
#define heartPin A0
SoftwareSerial BTSerial(4, 7); 
int sensorPin = 1; //Analog 0 번에 센서핀 연결
int redPin = 3;
int greenPin = 5;
//int bluePin = 5;


void setup() {
  BTSerial.begin(115200);
  Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  //pinMode(bluePin, OUTPUT); 

}
void loop() {
  //전압의 변화값을 센서핀으로 부터 읽음
  int reading = analogRead(sensorPin);  
  
  //전압값을 읽음, 센서에 공급되는 전압이 5V면 읽은값x5.0 이고 3.3V 이면 3.3을 곱해준다
  float voltage = reading * 5.0;
  voltage /= 1024.0; 

  //전압값(mV)으로 온도 구함 (섭씨) , 시리얼 모니터 출력
  int temperatureC = (voltage - 0.5) * 100 +5 ;
  //Serial.print(temperatureC);
  //Serial.println(" C");
  char a[10];
  sprintf(a,"%d",temperatureC);
  
  
  int heartValue = 60000/analogRead(heartPin);
  char b[10];
  sprintf(b,"%d",heartValue);
  char result[10] = {0,};  
  strcat(result, a);
  strcat(result, " ");
  strcat(result, b);
  BTSerial.print(result);
  Serial.println(result);
  //Serial.println(" BPM");
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
