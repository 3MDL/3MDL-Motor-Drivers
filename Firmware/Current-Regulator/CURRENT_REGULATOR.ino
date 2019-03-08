void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(A0, LOW);
  digitalWrite(13, LOW);
  if (analogRead(A1) > analogRead(A2)){
    digitalWrite(A0, LOW);
    digitalWrite(13, LOW);
  } else {
    digitalWrite(A0, HIGH);
    digitalWrite(13, HIGH);
  }
}
