//microswitch has to connect to analog
//NC: normally closed; when switch being pressed, value is 1023
//NO: normally oepn: when switch not pressed, value is 1023

int micro = A0;     //Connect NO/NC on microswtich to A2 depends on what we want
int buttonRead = 0;
int stepPin1 = 2;
int stepPin2 = 3;
int stepPin3 = 4;
int stepPin4 = 5;
int dirPin1 = A1;
int dirPin2 = A2;
int holdStepper;

void setup() {
  // put your setup code here, to run once:
  pinMode(micro, INPUT);
  Serial.begin(9600);
  pinMode(stepPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead = analogRead(micro);   
  Serial.println(buttonRead);     //print values from microswitch
  if (buttonRead != 0){
    turnStepper();
  }
  delay(1000);
}

void turnStepper() {
  digitalWrite(stepPin4, LOW);
  digitalWrite(stepPin3, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(stepPin1, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  holdStepper = 1;

  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 50; x++) {
    digitalWrite(stepPin4, LOW);
    digitalWrite(stepPin1, HIGH);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin3, HIGH);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin3, LOW);
    digitalWrite(stepPin2, HIGH);
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin2, LOW);
    digitalWrite(stepPin4, HIGH);
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    delayMicroseconds(2000);
  }
  delay(1000); // One second delay

}
