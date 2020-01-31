int pingTime;
int distance;
#define EnA 3
#define EnB 10
#define In1 4
#define In2 5
#define In3 6
#define In4 7
void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);  //trigPin
  pinMode(9,INPUT); //echoPin
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(EnA,255);
  analogWrite(EnB,255);
  digitalWrite(12,LOW);
  delayMicroseconds(5);
  digitalWrite(12,HIGH);
  delayMicroseconds(10);
  digitalWrite(12,LOW);
  pingTime = pulseIn(9,HIGH);
  distance = pingTime*0.034/2;
  if (distance <= 5){
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    analogWrite(EnA,255);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH);
    analogWrite(EnB,255);
  }
  else{
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    analogWrite(EnA,255);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH);
    analogWrite(EnB,255);
  }
  delay(1000);
}
