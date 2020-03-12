#include <LiquidCrystal.h>

LiquidCrystal lcd(A10, A11, A12, A13, A14, A15);

int trig_front = 4;   //ultrasonic sensor facing the front
int echo_front = 5;
int trig_side = 3;    //ultrasonic sensor facing the side
int echo_side = 2;
int S0 = 6;           //Colour sensor pin assignment
int S1 = 7;
int S2 = 8;
int S3 = 9;
int OUT = 10;
int microL = A6;      //left and right microswitches pin assignment
int microR = A7;

int stepPin1 = 30;   //define first stepper motor pin for insertion mechanism
int stepPin2 = 32;
int stepPin3 = 34;
int stepPin4 = 36;
int dirPin1 = A0;
int dirPin2 = A1;
int STEPPIN1 = 31;  //define second stepper motor pin for insertion mechanism
int STEPPIN2 = 33;
int STEPPIN3 = 35;
int STEPPIN4 = 37;
int DIRPIN1 = A8;
int DIRPIN2 = A9;
int ENA = A4;       //define DC motor pins for mobility
int ENB = A5;
int IN1 = 52;
int IN2 = 50;
int IN3 = 48;
int IN4 = 46;

int pingTime;         //pingTime of the ultrasonice sensor
int distance;         //distance obtained by analyzing pingTime
int frontval;         //stores distance to the front
int sideval;          //stores distance to the side

int redFrequency;     //stores frequency read by the photodiodes
int greenFrequency;
int blueFrequency;
char colour;          //stores 'B' if black is detected;
//stores 'W' if white is detected;
//stores 'P' if wood/port is detected;

int buttonRead;       //stores value read from microswitch
char touchstate;      //stores 'Y' if being pressed
//stores 'N' if not being pressed
char left_state;      //stores the touch state of the microswitch on the left
char right_state;     //stores the touch state of the microswitch on the right

int holdKey;          //used to set Stepper Motor status
int holdStepper;

char turn_direction;  //stores turn direction for the DC motor

int state = 1;        //setting up state 

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // put your setup code here, to run once:
  //sensor pinMode setup
  pinMode(trig_front, OUTPUT);    //ultrasonic sensor pinMode setup
  pinMode(trig_side, OUTPUT);     //assign trig to output and echo to input
  pinMode(echo_front, INPUT);
  pinMode(echo_side, INPUT);

  pinMode(S0, OUTPUT);            //Colour sensor pinMode setup
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  digitalWrite(S0, HIGH);         //setting frequency scaling to 20%
  digitalWrite(S1, HIGH);

  pinMode(microL, INPUT);         //microswitch pinMode setup
  pinMode(microR, INPUT);

  //motor pinMode setup
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
}

void loop() {
  // put your main code here, to run repeatedly:
  frontval = ultrasonic(trig_front, echo_front);
  Serial.println(frontval);
  if (state == 1){        //Initial State
    frontval = ultrasonic(trig_front, echo_front);        //Front ultrasonic sensor detecting whether there's object in the front
    Serial.println(frontval);
    if (frontval <= 10000){
      state ++;
      Serial.println("state = 2");
    }else{
      turnDC('A');
      delay(1430);
      turnDC('K');
      turnDC('W');
      sideval = ultrasonic(trig_side, echo_side);
      if (sideval <= 1000){
        turnDC('K');
        turnDC('D');
        delay(1430);
        turnDC('K');
        state ++;
      }
    }
  }
}

//The following function will obtain value from the ultrasonic sensor
int ultrasonic(int trig, int echo) {
  digitalWrite(trig, LOW);
  delay(5);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  pingTime = pulseIn(echo, HIGH);
  distance = pingTime * 0.34 / 2;
  return pingTime;
}

//The following function will obtain value from colour sensor
char coloursensor() {
  digitalWrite(S2, LOW);    //setting RED(R) filtered photodiodes to be read
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(OUT, LOW);   //reading the output frequency

  digitalWrite(S2, HIGH);   //setting GREEN(G) filtered photodiodes to be read
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(OUT, LOW); //reading the output frequency

  digitalWrite(S2, LOW);    //setting BLUE(B) filtered photodiodes to be read
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(OUT, LOW);  //reading the output frequency
  if (redFrequency < 10) {
    colour = 'W';
  } else if (redFrequency > 10) {
    colour = 'B';
  } else if (redFrequency > 30) {
    colour = 'P';
  }
  return colour;
}

//The following function will obtain and analyze value from microswitch
char microswitch(int micro) {
  buttonRead = analogRead(micro);
  if (buttonRead == 1023) {
    touchstate = 'Y';
  } else {
    touchstate = 'N';
  }
  return touchstate;
}

//The following function will turn the DC motors
void turnDC(char turn_direction) {
  if (turn_direction == 'W') {     //if 'W' is stored, the rover will move forward
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (turn_direction == 'S') { //if 'S' is stored, the rover will move backward
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else if (turn_direction == 'D') { //if 'D' is stored, the rover will turn right
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 255);
  } else if (turn_direction == 'A') { //if 'A' is stored, the rover will turn left
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 255);
    analogWrite(ENB, 0);
  } else if (turn_direction == 'K') { //if 'K' is stored, the rover will stop moving
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

//The following function will turn the stepper motorI
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

  for (int x = 0; x < 50; x++) {  //with step angle = 1.8 degree, the stepper will turn 90 degree
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

void turnOppositeStepper() {
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

  for (int x = 0; x < 50; x++) {  //with step angle = 1.8 degree, the stepper will turn 90 degree
    digitalWrite(stepPin4, LOW);
    digitalWrite(stepPin1, HIGH);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    digitalWrite(STEPPIN4, LOW);
    digitalWrite(STEPPIN1, HIGH);
    digitalWrite(DIRPIN1, LOW);
    digitalWrite(DIRPIN2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin3, HIGH);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    digitalWrite(STEPPIN1, LOW);
    digitalWrite(STEPPIN3, HIGH);
    digitalWrite(DIRPIN1, HIGH);
    digitalWrite(DIRPIN2, LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin2, HIGH);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    digitalWrite(STEPPIN3, LOW);
    digitalWrite(STEPPIN2, HIGH);
    digitalWrite(DIRPIN1, LOW);
    digitalWrite(DIRPIN2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin4, HIGH);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    digitalWrite(STEPPIN2, LOW);
    digitalWrite(STEPPIN4, HIGH);
    digitalWrite(DIRPIN1, HIGH);
    digitalWrite(DIRPIN2, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); // One second delay
}


void stopStepper(){   //this function will turn off the stepper motor
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
