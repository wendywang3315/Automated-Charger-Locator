int microL_F = A12; //left and right microswitches at the front of the rover
int microR_F = A13;
int microL_S = A14; //left and right microswitches at the side of the rover
int microR_S = A15;

int ENA = A5;       //define DC motor pins for mobility
int ENB = A6;
int IN1 = 52;
int IN2 = 50;
int IN3 = 48 ;
int IN4 = 46;

int microRead_frontL = 0;
int microRead_frontR = 0;
int microRead_sideL = 0;
int microRead_sideR = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(microL_F, INPUT);   //setting pinMode for microswitches
  pinMode(microR_F, INPUT);
  pinMode(microL_S, INPUT);
  pinMode(microR_S, INPUT);
  pinMode(ENA, OUTPUT);       //setting pinMode for DC motors
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  microRead_frontL = analogRead(microL_F);
  microRead_frontR = analogRead(microR_F);
  microRead_sideL = analogRead(microL_S);
  microRead_sideR = analogRead(microR_S);
  Serial.print("Front Left:");
  Serial.print(microRead_frontL);
  Serial.print("   ");
  Serial.print("Front Right:");
  Serial.println(microRead_frontR);
  Serial.print("Side Left:");
  Serial.print(microRead_sideL);
  Serial.print("   ");
  Serial.print("Side Right:");
  Serial.println(microRead_sideR);
  if (Serial.available() > 0) {
    char state = Serial.read();
    while (state == 'S') {
      char state = Serial.read();
      microRead_frontL = analogRead(microL_F);
      microRead_frontR = analogRead(microR_F);
      microRead_sideL = analogRead(microL_S);
      microRead_sideR = analogRead(microR_S);
      Serial.print("Front Left:");
      Serial.print(microRead_frontL);
      Serial.print("   ");
      Serial.print("Front Right:");
      Serial.println(microRead_frontR);
      Serial.print("Side Left:");
      Serial.print(microRead_sideL);
      Serial.print("   ");
      Serial.print("Side Right:");
      Serial.println(microRead_sideR);
      if (microRead_frontL == 0 && microRead_frontR == 0 && microRead_sideL == 0 && microRead_sideR == 0) {
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        Serial.println("Motor forward");
        microRead_frontL = analogRead(microL_F);
        microRead_frontR = analogRead(microR_F);
        microRead_sideL = analogRead(microL_S);
        microRead_sideR = analogRead(microR_S);
        Serial.print("Front Left:");
        Serial.print(microRead_frontL);
        Serial.print("   ");
        Serial.print("Front Right:");
        Serial.println(microRead_frontR);
        Serial.print("Side Left:");
        Serial.print(microRead_sideL);
        Serial.print("   ");
        Serial.print("Side Right:");
        Serial.println(microRead_sideR);
        if (microRead_frontL == 0 && microRead_frontR != 0 && microRead_sideL == 0 && microRead_sideR == 0) {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          analogWrite(ENA, 255);
          analogWrite(ENB, 0);
          Serial.println("Motor right");
          microRead_frontL = analogRead(microL_F);
          microRead_frontR = analogRead(microR_F);
          microRead_sideL = analogRead(microL_S);
          microRead_sideR = analogRead(microR_S);
          Serial.print("Front Left:");
          Serial.print(microRead_frontL);
          Serial.print("   ");
          Serial.print("Front Right:");
          Serial.println(microRead_frontR);
          Serial.print("Side Left:");
          Serial.print(microRead_sideL);
          Serial.print("   ");
          Serial.print("Side Right:");
          Serial.println(microRead_sideR);
          if (microRead_frontL != 0) {
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            analogWrite(ENA, 0);
            analogWrite(ENB, 255);
            Serial.println("Motor left");
            if (microRead_sideL != 0 && microRead_sideR != 0) {
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, LOW);
              digitalWrite(IN4, LOW);
              Serial.println("Success");
            }
          }
        } else if (microRead_frontL != 0 && microRead_frontR == 0 && microRead_sideL == 0 && microRead_sideR == 0) {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          analogWrite(ENA, 0);
          analogWrite(ENB, 255);
        }
      } else if (microRead_frontL > 30) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 255);
        Serial.println("Motor left");
        delay(1750);
        microRead_frontL = analogRead(microL_F);
        microRead_frontR = analogRead(microR_F);
        microRead_sideL = analogRead(microL_S);
        microRead_sideR = analogRead(microR_S);
        Serial.print("Front Left:");
        Serial.print(microRead_frontL);
        Serial.print("   ");
        Serial.print("Front Right:");
        Serial.println(microRead_frontR);
        Serial.print("Side Left:");
        Serial.print(microRead_sideL);
        Serial.print("   ");
        Serial.print("Side Right:");
        Serial.println(microRead_sideR);
        if (microRead_sideL != 0 && microRead_sideR != 0) {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          Serial.println("STOP");
        }

        /*if (microRead_sideL != 0 && microRead_sideR != 0) {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          Serial.println("Success");
          }*/
      } else if (microRead_frontR > 30) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 255);
      } else if (microRead_sideR > 30 && microRead_sideL == 0){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 255);
        delay(500); 
      } else if (microRead_sideL > 30 && microRead_sideR == 0){
        analogWrite(ENA, 255);
        analogWrite(ENB, 0);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      } else if (microRead_sideL > 30 && microRead_sideR > 30) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        Serial.println("STOP");
      }
      while (state == 'K') {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        Serial.println("STOP");
      }
      delay(1000);
    }
    delay(1000);
  }
}

void turnDCfront() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnDCback() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnDCleft() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnDCright() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnDCstop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
