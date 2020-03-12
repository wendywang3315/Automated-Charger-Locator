#define trig 4
#define echo 5

int pingTime;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delay(5);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  pingTime = pulseIn(echo, HIGH);
  distance = pingTime*0.034/2;
  Serial.println(pingTime);
  delay(1000);
}
