#define trigPin 2
#define echoPin_1 3
#define echoPin_2 9
#define echoPin_3 5
#define echoPin_4 6                                                                                                                                                                                                                                                                                                                                  
int pingTime_1;
int pingTime_2;
int pingTime_3;
int pingTime_4;
int distance_1;
int distance_2;
int distance_3;
int distance_4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(echoPin_2, INPUT);
  pinMode(echoPin_3, INPUT);
  pinMode(echoPin_4, INPUT);
}


void loop() {
  if (Serial.available()>0){
     char input = Serial.read();
     while (input == 'e'){
       digitalWrite(trigPin, LOW);
       delayMicroseconds(5);
       digitalWrite(trigPin, HIGH); 
       delayMicroseconds(10);
       digitalWrite(trigPin,LOW);
       pingTime_1 = pulseIn(echoPin_1,HIGH);
       digitalWrite(trigPin, LOW);
       delayMicroseconds(5);
       digitalWrite(trigPin, HIGH); 
       delayMicroseconds(10);
       digitalWrite(trigPin,LOW);
       pingTime_2 = pulseIn(echoPin_2,HIGH);
       digitalWrite(trigPin, LOW);
       delayMicroseconds(5);
       digitalWrite(trigPin, HIGH); 
       delayMicroseconds(10);
       digitalWrite(trigPin,LOW);
       pingTime_3 = pulseIn(echoPin_3,HIGH);
       digitalWrite(trigPin, LOW);
       delayMicroseconds(5);
       digitalWrite(trigPin, HIGH); 
       delayMicroseconds(10);
       digitalWrite(trigPin,LOW);
       pingTime_4 = pulseIn(echoPin_4,HIGH);
       distance_1 = pingTime_1*0.034/2;
       distance_2 = pingTime_2*0.034/2;
       distance_3 = pingTime_3*0.034/2;
       distance_4 = pingTime_4*0.034/2;
       Serial.print(millis());
       Serial.print("_");
       Serial.print(distance_1);
       Serial.print("_");
       Serial.print(distance_2);
       Serial.print("_");
       Serial.print(distance_3);
       Serial.print("_");
       Serial.println(distance_4);
     }
  }
}
