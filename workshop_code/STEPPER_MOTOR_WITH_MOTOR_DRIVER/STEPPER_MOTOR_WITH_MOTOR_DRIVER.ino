// defines pins numbers
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int enA = 12;
int enB = 7;

void setup() {
  // Sets the two pins as Outputs
  pinMode(in2,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  Serial.begin(9600);
}

void loop(){
   for(int x=0;x<200;x++){
    digitalWrite(enA,LOW);
    digitalWrite(enB,HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delayMicroseconds(5000);
    digitalWrite(enA,HIGH);
    digitalWrite(enB,LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delayMicroseconds(5000);
    digitalWrite(enA,LOW);
    digitalWrite(enB,HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delayMicroseconds(5000);
    digitalWrite(enA,HIGH);
    digitalWrite(enB,LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delayMicroseconds(5000);
    Serial.println(x);
   }
    //delay(1000);
    
}
