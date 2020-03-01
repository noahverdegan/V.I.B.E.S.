// Relay pin is controlled with D8. The active wire is connected to Normally Closed and common
int relay = 4;
volatile byte relayState = LOW;

// PIR Motion Sensor is connected to D2.
int moistPin = A0;

unsigned long StartTime = millis();

void setup() {
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.begin(9600);
}

void loop() {
  int moistVal = analogRead(moistPin);
  moistVal = map(moistVal-297, 274, 0, 0, 100);
  Serial.print("moist val: ");
  Serial.println(moistVal);
  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = CurrentTime - StartTime;

  if(moistVal < 50 && ElapsedTime > 30000){
    digitalWrite(relay, HIGH);
    delay(1000);
    digitalWrite(relay, LOW);
    StartTime = millis();
  } else{
    digitalWrite(relay, LOW);
  }
  delay(500);
}
