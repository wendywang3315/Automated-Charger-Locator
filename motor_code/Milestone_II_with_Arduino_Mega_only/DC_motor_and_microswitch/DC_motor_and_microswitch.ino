int microL_F = A12; //left and right microswitches at the front of the rover
int microR_F = A13;
int microL_S = A14; //left and right microswitches at the side of the rover
int microR_S = A15;

int ENA = A4;       //define DC motor pins for mobility
int ENB = A5;
int IN1 = 52;
int IN2 = 50;
int IN3 = 48;
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
  if (Serial.available()){
    char state = Serial.read();
    if (state == 'S'){
      if (microRead_frontL == 0 && microRead_frontR == 0 && microRead_sideL == 0 && microRead_sideR == 0){
        turnDCfront();
      }else if(microRead_frontL == 0 && microRead_frontR != 0 && microRead_sideL == 0 && microRead_sideR == 0){
        turnDCright();
      }else if(microRead_frontL != 0){
        turnDCleft();
        if (microRead_sideL != 0 && microRead_sideR != 0){
          
        }
      }
    }
  }
}

void turnDCfront(){
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnDCback(){
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnDCleft(){
  analogWrite(ENA, 255);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnDCright(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnDCstop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
