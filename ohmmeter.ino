int analogPin = 0;
int raw = 0;
float Vin = 4.99;
float Vout = 0;
float R1 = 9660;  // Ohm of resistor 1.
float R2 = 0;
float buffer = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  raw = analogRead(analogPin);
  
  if (raw) {
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R2 = R1 * buffer;

    Serial.print("Vout: ");
    Serial.println(Vout, 3); // Display Vout with 3 decimal places
    
    Serial.print("R2: ");
    printWithUnit(R2);
    
    delay(1000);
  }
}

void printWithUnit(float value) {
  if (value >= 1000000) {
    Serial.print(value / 1000000.0, 2);
    Serial.println(" MOhm");
  } else if (value >= 1000) {
    Serial.print(value / 1000.0, 2);
    Serial.println(" kOhm");
  } else {
    Serial.print(value, 2);
    Serial.println(" Ohm");
  }
}
