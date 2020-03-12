#include <LiquidCrystal.h>    //LCD display library
#include <SoftwareSerial.h>   //Software Serial library

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);   //LCD display pin assignment

int trig_front = 4;   //ultrasonic sensor facing the front
int echo_front = 5;
int trig_side = 3;    //ultrasonic sensor facing the side
int echo_side = 2;

int pingTime_front;   //pingTime of front ultrasonic sensor
int pingTime_side;    //pingTime of side ultrasonic sensor
int distance_front;   //distance to the front
int distance_side;    //distance to the side

SoftwareSerial mySerial(7,6); //RX | TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin(16,2);
  //lcd.print("Hello World");
  pinMode(trig_front, OUTPUT);    //assign trig to output and echo to input
  pinMode(trig_side, OUTPUT); 
  pinMode(echo_front, INPUT);
  pinMode(echo_side, INPUT);
  pinMode(6, OUTPUT);   //Transmitting signal to motor uno
  pinMode(7, INPUT);    //Receiving signal to motor uno
  Serial.println("Hello World!");
  mySerial.write("S");
}

void loop() {
  // put your main code here, to run repeatedly:
  int front_distance = ultrasonic();
  if (front_distance < 30 && mySerial.available() > 0){
    mySerial.write("S");
    lcd.setCursor(0,1);
    lcd.print("MOVE MOTOR");
  }
  delay(1000);
}

int ultrasonic(){
  digitalWrite(trig_front, LOW);
  delay(5);
  digitalWrite(trig_front, HIGH);
  delay(10);
  digitalWrite(trig_front, LOW);
  pingTime_front = pulseIn(echo_front, HIGH);
  distance_front = pingTime_front * 0.34 / 2;
  Serial.println(distance_front);
  return distance_front;
}
