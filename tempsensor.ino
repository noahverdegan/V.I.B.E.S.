int ThermistorPin = A0;
int LightPin = A1;
int WaterPin = A2;
int Vo;
float R1 = 10000; // value of R1 on board
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor

void setup() {
  Serial.begin(9600);
}

float temp_in_Farenheit(float R1, int ThermistorPin) {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; //convert Kelvin to Celcius
  T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
  return T;
}

void loop() {
  T = temp_in_Farenheit(R1, ThermistorPin); //convert Celcius to Farenheit

  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" F");

  float light = analogRead(LightPin);
  Serial.print("Light: ");
  Serial.println(light);
  
  float water = analogRead(WaterPin);
  Serial.print("Water: ");
  Serial.println(water);

  delay(500);
}
