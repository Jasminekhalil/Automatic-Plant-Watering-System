#define SensorReadDelay 86400000  // How often the moisture will be checked
#define FullyWetReading 347 // Value when sensor is fully wet 
#define FullyDryReading 865 // Value when sensor is fully dry
#define CutOffMoisture 50 // Percentage when moisture is cut off
#define PumpWateringTime 600 // How long pump is turned on when the plant needs water

int pumpPin = 2; 
int sensorPin = A0;

void setup(){
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);
}

// Funtion for getting the moisture percentage of the plant and deciding whether water should be pumped in
void waterPlant(int sensorVal, int outPin, int wateringTime){
  sensorVal = constrain(sensorVal, FullyWetReading, FullyDryReading);
  int moisturePercent = map(sensorVal, FullyWetReading, FullyDryReading, 100, 0);
  if moisturePercent < CutOffMoisture{
    digitalWrite(outPin, LOW);
    delay(wateringTime);
    digitalWrite(outPin, HIGH);
  }
}

void loop(){
  int sensorPinVal = analogRead(sensorPin);
  waterPlant(sensorPinVal, pumpPin, PumpWateringTime);
  delay(SensorReadDelay);
}