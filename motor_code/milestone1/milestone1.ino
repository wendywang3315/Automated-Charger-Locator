#include <PID_v1.h>

int holdKey = 0;
int holdStepper = 0;

int stepPin1 = 2;   //define stepper motor pin for insertion mechanism
int stepPin2 = 3;
int stepPin3 = 4;
int stepPin4 = 5;
int dirPin1 = A1;
int dirPin2 = A2;
int DIRPIN1 = A8;
int DIRPIN2 = A9;
int STEPPIN1 = 8;
int STEPPIN2 = 9;
int STEPPIN3 = 10;
int STEPPIN4 = 11;
int ENA = A5;       //define DC motor pins for mobility
int ENB = A6;
int IN1 = 52;
int IN2 = 50;
int IN3 = 48;
int IN4 = 46;


void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin1, OUTPUT); //setting pinMode for stepper motors for insertion mechanism
  pinMode(stepPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(DIRPIN1, OUTPUT);
  pinMode(DIRPIN2, OUTPUT);
  pinMode(STEPPIN1, OUTPUT);
  pinMode(STEPPIN2, OUTPUT);
  pinMode(STEPPIN3, OUTPUT);
  pinMode(STEPPIN4, OUTPUT);
  pinMode(ENA, OUTPUT);     //setting pinMode for DC motors for mobility
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  /*pinMode(1, INPUT);
  pinMode(0, OUTPUT);*/
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char readval = Serial.read();
    Serial.println(readval);
    if (readval == 'W'){
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }else if(readval == 'S'){
      analogWrite(ENA, 255);
      analogWrite(ENB, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }else if(readval == 'D'){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 255);
    }else if(readval == 'A'){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 255);
      analogWrite(ENB, 0);
    }else if(readval == 'K'){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }else if(readval == 'I'){
      turnStepper();
    }else if(readval == 'N'){
      stopStepper();
    }
  }
}

void turnDC(){
}

void stopStepper(){
  digitalWrite(stepPin4, LOW);
  digitalWrite(stepPin3, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(stepPin1, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(DIRPIN1, LOW);
  digitalWrite(DIRPIN2, LOW);
  digitalWrite(STEPPIN1, LOW);
  digitalWrite(STEPPIN2, LOW);
  digitalWrite(STEPPIN3, LOW);
  digitalWrite(STEPPIN4, LOW);
  holdStepper = 1;
}

void turnStepper() {
  digitalWrite(stepPin4, LOW);
  digitalWrite(stepPin3, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(stepPin1, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(DIRPIN1, LOW);
  digitalWrite(DIRPIN2, LOW);
  digitalWrite(STEPPIN1, LOW);
  digitalWrite(STEPPIN2, LOW);
  digitalWrite(STEPPIN3, LOW);
  digitalWrite(STEPPIN4, LOW);
  holdStepper = 1;

  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 50; x++) {
    digitalWrite(stepPin4, LOW);
    digitalWrite(stepPin1, HIGH);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    digitalWrite(STEPPIN4, LOW);
    digitalWrite(STEPPIN1, HIGH);
    digitalWrite(DIRPIN1, HIGH);
    digitalWrite(DIRPIN2, LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin3, HIGH);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    digitalWrite(STEPPIN1, LOW);
    digitalWrite(STEPPIN3, HIGH);
    digitalWrite(DIRPIN1, LOW);
    digitalWrite(DIRPIN2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin2, HIGH);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    digitalWrite(STEPPIN3, LOW);
    digitalWrite(STEPPIN2, HIGH);
    digitalWrite(DIRPIN1, HIGH);
    digitalWrite(DIRPIN2, LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin4, HIGH);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    digitalWrite(STEPPIN2, LOW);
    digitalWrite(STEPPIN4, HIGH);
    digitalWrite(DIRPIN1, LOW);
    digitalWrite(DIRPIN2, HIGH);
    delayMicroseconds(2000);
  }
  delay(1000); // One second delay
}
