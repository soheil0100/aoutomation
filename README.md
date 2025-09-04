# Arduino Temperature Control System

## Overview
This project is a temperature monitoring and controller device. The ambient temperature is measured through a temperature sensor and if it exceeds the maximum limit, the cooler relay is activated by Arduino and if the temperature decreases below the minimum limit, the heater relay is activated and the LEDs of each are also lit and the buzzer sounds. The maximum and minimum limits are set by two variable resistors.

## Features
- Temperature measurement using analog sensor.  
- Real-time display of current, upper, and lower temperatures on a **16x2 LCD**.  
- Automatic fan activation when temperature is above the upper limit.  
- Automatic heater activation when temperature is below the lower limit.  
- Buzzer alert when thresholds are reached.  
- Status indication using three LEDs (fan, heater, normal).  

## Requirements
- **Arduino Board** (Uno, Mega, or compatible).  
- **16x2 LCD Display** (connected via parallel pins).  
- **Temperature Sensor** (connected to analog pin).  
- **Fan and relay or driver circuit**.  
- **Heater module or simulated load**.  
- **Buzzer**.  
- **LEDs** for status indication.  

## Pin Configuration
- **LCD** → Pins 13, 12, 11, 10, 9, 8  
- **Temperature sensor** → A0  
- **Upper limit (potentiometer)** → A1  
- **Lower limit (potentiometer)** → A2  
- **Fan** → Pin 2  
- **Fan LED** → Pin 3  
- **Heater** → Pin 4  
- **Heater LED** → Pin 5  
- **Normal LED** → Pin 6  
- **Buzzer** → Pin 7  

## Installation
1. Clone this repository or download the `.ino` file.  
2. Open the file in **Arduino IDE**.  
3. Connect your Arduino board to your computer.  
4. Select the correct **board** and **port** in Arduino IDE.  
5. Upload the sketch to your Arduino.  

## Usage
- Set the desired upper and lower temperature limits using potentiometers.  
- The LCD will display the current temperature along with the configured limits.  
- The system will automatically:  
  - Turn on the **fan** if temperature exceeds the upper limit.  
  - Turn on the **heater** if temperature goes below the lower limit.  
  - Keep normal state between the limits.  
  - Activate the **buzzer** when thresholds are crossed.  

## License
This project is open-source and available under the MIT License.  

# aoutomation
