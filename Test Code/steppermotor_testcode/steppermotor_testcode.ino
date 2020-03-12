#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper = Stepper(stepsPerRevolution, 9,8,7,6);

void setup(){
  myStepper.setSpeed(100);
  Serial.begin(9600);
}

void loop(){
  myStepper.step(200);
  Serial.println("inloop");
  delay(2000);
  myStepper.step(-200);
  delay(2000);
}
