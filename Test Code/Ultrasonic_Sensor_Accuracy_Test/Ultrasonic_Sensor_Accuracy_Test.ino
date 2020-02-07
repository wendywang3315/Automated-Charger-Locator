int pingTime;
int distance;
int pingTime2;
int distance2;
#define trigPin 12
#define echoPin 9
#define trigPin2 11
#define echoPin2 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH);
  distance = pingTime*0.34/2;
  Serial.print("Distance is");
  Serial.println(distance);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pingTime2 = pulseIn(echoPin2, HIGH);
  distance2 = pingTime2*0.34/2;
  Serial.print("Distance2 is");
  Serial.println(distance2);
  delay(2000); 
}
