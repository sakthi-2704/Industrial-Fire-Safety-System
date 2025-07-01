const int flameSensorPin = 2;
const int smokeSensorPin = A0;
const int buzzerPin = 9;
const int ledPin = 13;

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int flameStatus = digitalRead(flameSensorPin);
  int smokeValue = analogRead(smokeSensorPin);

  Serial.print("Flame: ");
  Serial.print(flameStatus == 0 ? "DETECTED" : "SAFE");
  Serial.print(" | Smoke: ");
  Serial.println(smokeValue);

  if (flameStatus == 0 || smokeValue > 300) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
