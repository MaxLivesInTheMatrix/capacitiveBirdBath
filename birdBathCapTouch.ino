// The code for the capacitive touch activated bird bath
// Max Sorin
#include <CapacitiveSensor.h>
#define ROLLING_AVG_SAMPLE 50 // This is the array buffer size
CapacitiveSensor capSensor = CapacitiveSensor(4, 2); // Pin 4 sends electrical energy, pin 2 recieves electrical energy
// Thresholds for turning on and off the pump
int threshold  = 50; // The arduino threshold for enabling and disabling the pump
long currSum = 0; // This must be a long or else it will overflow and give negative values and unexpected performance
float mvgAvg = 0;
int arr[ROLLING_AVG_SAMPLE] = {0}; // Initialize an array of 100 with all zeroes

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT); // Output pin to pump

}

void loop() {
  // put your main code here, to run repeatedly:
  long sensorValue = capSensor.capacitiveSensor(30);

  //Serial.println(sensorValue);
  Serial.println(mvgAvg); // Debug value for moving average

  // Moving Average calculation
  static int index = 0;
  currSum -= arr[index];
  currSum += sensorValue;
  arr[index] = sensorValue;
  index += 1;

  mvgAvg = currSum / (float)ROLLING_AVG_SAMPLE;

  if (index >= ROLLING_AVG_SAMPLE)
  {
    index = 0; // Keeps our circular buffer circular
  }

  if (mvgAvg > threshold)
  {
    digitalWrite(7, HIGH); // Enable the pump
  }
  else
  {
      digitalWrite(7, LOW); // Disable the pump
  }

  delay(10);
}
