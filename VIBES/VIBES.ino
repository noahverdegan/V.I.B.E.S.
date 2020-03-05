// Relay pin is controlled with D8. The active wire is connected to Normally Closed and common
int relay = 4;
volatile byte relayState = HIGH;

// PIR Motion Sensor is connected to D2.
int moistPin = A0;

unsigned long StartTime = millis();

void setup() {
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
}

void loop() {
  int moistVal = analogRead(moistPin);
  moistVal = map(moistVal-297, 274, 0, 0, 100);
  Serial.print("Moisture : ");
  Serial.print(moistVal);
  Serial.println("%");

  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = CurrentTime - StartTime;
  Serial.print("Elapsed Time: ");
  Serial.println(ElapsedTime);

  if(moistVal < 50 && ElapsedTime > 30000){
    watering();
    StartTime = millis();
  } else{
    Serial.println("Relay set to HIGH");
    digitalWrite(relay, HIGH);
  }
  delay(500);
}

void watering() {
    Serial.print("Watering");
    digitalWrite(relay, LOW);
    delay(2000);
    digitalWrite(relay, HIGH);
    delay(30000);
    digitalWrite(relay, LOW);
    delay(2000);
    digitalWrite(relay, HIGH);
}
