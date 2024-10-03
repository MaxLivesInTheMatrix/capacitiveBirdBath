# Capacitive Touch Activated Bird Bath
# Overview
This project is a capacitive touch-activated bird bath that uses an Arduino to control a water pump. When the capacitive sensor detects a significant change in capacitance, indicating that a bird is touching the sensor or nearby water, it activates the pump to start the fountain.
# Key Features
* Capacitive Sensor Input: Detects when a bird interacts with the bird bath.
* Water Pump Control: Automatically turns the pump on/off based on sensor readings.
* Moving Average Filter: A rolling average is used to smooth the sensor readings, reducing noise and ensuring stable pump activation.

# How It Works:
Capacitive Sensor Reading: The sensor measures the capacitance near the bath, which changes when a bird touches or is near the bath.

* Moving Average Filter: The rolling average is computed to smooth out any noise in the sensor data. The buffer stores the last 50 readings, and the average is updated every time the sensor reads new data.

# Pump Activation:
If the moving average exceeds the threshold (set to 50), the pump is activated (pin 7 is set HIGH).
If the average falls below the threshold, the pump is deactivated (pin 7 is set LOW).
Looping: The program continuously reads from the capacitive sensor, updates the moving average, and controls the pump in real time.
