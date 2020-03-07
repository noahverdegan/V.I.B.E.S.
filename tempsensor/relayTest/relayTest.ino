// Relay pin is controlled with D8. The active wire is connected to Normally Closed and common
int relay = 4;
volatile byte relayState = LOW;

// PIR Motion Sensor is connected to D2.
int moistPin = A0;


void setup() {
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
}

void loop() {
  int timing = 60000;
  int moistVal = analogRead(moistPin);
  moistVal = map(moistVal-297, 274, 0, 0, 100);
  Serial.print("moist val: ");
  Serial.println(moistVal);

  if(moistVal < 10){
    digitalWrite(relay, LOW);
    delay(1000);
    digitalWrite(relay, HIGH);
    timing = 86400000;
  } else{
    digitalWrite(relay, HIGH);
  }
  delay(timing);
}
