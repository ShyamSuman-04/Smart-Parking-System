#include<Servo.h>
Servo servo;

#define trigPin A0
#define echoPin A1
#define trigPin1 A4
#define echoPin1 A5
#define trigPin2 A2
#define echoPin2 A3
int buzzer=2;
int g1=3;
int r1=4;
int g2=5;
int r2=6;
long duration, distance;
long duration1, distance1;
long duration2,distance2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  servo.attach(9);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration*0.017;
  delay(1000);

  if(distance<5){
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1,LOW);
    duration1 = pulseIn(echoPin1, HIGH); 
    distance1 = duration1*0.017;
    delayMicroseconds(20);
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2,LOW);
    duration2 = pulseIn(echoPin2, HIGH); 
    distance2 = duration2*0.017;
    delay(100);
    Serial.println("Start");
    Serial.println(distance);
    Serial.println(distance1);
    Serial.println(distance2);
    Serial.println("Stop");

    if(distance1>5 || distance2>5){
      digitalWrite(buzzer,HIGH);
      delay(200);
      digitalWrite(buzzer,LOW);

      for(int i=1; i<=90;i++){
        servo.write(i);
        delay(20);
      }
      delay(100);

      digitalWrite(buzzer,HIGH);
      delay(200);
      digitalWrite(buzzer,LOW);

      for(int i=0; i>=-90;i--){
        servo.write(i);
        delay(20);
      }
    if (distance1<10){
        digitalWrite(r1,HIGH);
      }
    else{
        digitalWrite(g1,HIGH);
      }
    if (distance2<10){
        digitalWrite(r2,HIGH);
      }
    else{
        digitalWrite(g2,HIGH);
      }
      delay(100);
    }
    else{
      //Serial.print("NO SPACE FOR PARKING");
    }

  }
  delay(100);

}
