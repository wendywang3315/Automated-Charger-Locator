//#include <SoftwareSerial.h>
//button + LED
//int button = 3;
//int buttonRead = 0;
int holdKey = 0;
int holdStepper = 0;

//stepper
int stepPin1 = 2;
int stepPin2 = 3;
int stepPin3 = 4;
int stepPin4 = 5;
int dirPin1 = A1;
int dirPin2 = A2;
int DIRPIN1 = A3;
int DIRPIN2 = A4;
int STEPPIN1 = 8;
int STEPPIN2 = 9;
int STEPPIN3 = 10;
int STEPPIN4 = 11;

//software serial
//Pin 6 (RX) Sensor Uno  Pin 1 (TX) Rover Uno
//Pin 5 (TX) Sensor Uno  Pin 0 (RX) Rover Uno.

//SoftwareSerial mySerial(2, 3); // RX | TX


void setup() {
  //pinMode(13, OUTPUT); //debug to led 13
  //pinMode(button, INPUT);

  // Sets the two pins as Outputs
  pinMode(stepPin1, OUTPUT);
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
  ///pinMode(2, INPUT);
  //pinMode(3, OUTPUT);
  Serial.begin(9600);
  //mySerial.begin(9600);
  //pinMode(1, INPUT);
  //pinMode(0, OUTPUT);
}

void loop() {
  // Read from Software Serial and send to Arduino Serial Monitor
  /**if (mySerial.available()) {
    Serial.write(mySerial.read());
    }*/
  // Keep reading from Arduino Serial Monitor and send to Software Serial

  /*buttonRead = digitalRead(button);
    Serial.println(buttonRead);
    Serial.println("IN LOOP");
    Serial.println(button);
    if (buttonRead == HIGH && holdKey == 0) {
    holdKey = 1;
    Serial.println("IN IF");
    digitalWrite(13, HIGH);*/
  //if (Serial.available()) {
  //delay(2000);
  //char readval = Serial.write('S');
  //Serial.println(readval);
  //if (readval == 'S') {
  turnStepper();
  //delay(2000);
  //mySerial.write('S');
  //}
  //}
//}
/*else if (buttonRead == HIGH  && holdKey == 1) {
  holdKey = 0;
  Serial.println(buttonRead);
  Serial.println("IN ELSE");
  //digitalWrite(13, LOW);
  holdStepper = 0;
  }*/
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
