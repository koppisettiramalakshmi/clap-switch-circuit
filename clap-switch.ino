const int soundSensor = 2;
const int outputPin = 13;

bool deviceState = false;
unsigned long lastClapTime = 0;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(outputPin, OUTPUT);

  digitalWrite(outputPin, LOW);

  Serial.begin(9600);
}

void loop() {
  int soundDetected = digitalRead(soundSensor);

  if (soundDetected == HIGH) {

    if (millis() - lastClapTime > 500) {

      deviceState = !deviceState;

      digitalWrite(outputPin, deviceState ? HIGH : LOW);

      Serial.println(deviceState ? "Device ON" : "Device OFF");

      lastClapTime = millis();
    }
  }
}