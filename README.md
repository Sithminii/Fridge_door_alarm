# Fridge Door Alarm - ATmega328P Microcontroller Code

## Overview
The Fridge Door Alarm is a DIY project designed to prevent leaving the refrigerator door open for an extended period. This alarms you when your fridge door is left open for a long time or is not closed properly. This code is specifically written for the ATmega328P microcontroller, which is the brain behind the device's functionality.

<img src="[fridge_alarm.jpg](https://github.com/Sithminii/Fridge_door_alarm/blob/main/Prototype_Internal%20view.jpg)" alt="Fridge Door Alarm" width="20" height="10">


## Project Description
The Fridge Door Alarm is a smart solution that combines hardware and software to alert users when their fridge door is left open for too long. This code controls the ATmega328P microcontroller, which interacts with a hall effect sensor, buzzer,ESP01 wifi moddule and push buttons to manage the alarm system.

## Features
- Customizable alarm times: Users can select 1, 2, or 10 minutes for the alarm duration.
- Three-stage alarm system: The device triggers three alarms with user-defined intervals if the fridge door remains open.
- WhatsApp notifications: Sends alerts to the user's WhatsApp when the fridge door is left open. 
- Easy-to-use push buttons for setting alarm times.

## Hardware Requirements
Required components:
- ATmega328P microcontroller
- ESP01 WiFi module (for IoT purposes)
- Hall effect sensor
- Buzzer
- Push buttons (for alarm time selection)
- Necessary resistors and wiring components

## Usage
1. **Setting Alarm Time:** Press one of the three push buttons to set the alarm time to 1, 2, or 5 minutes.

2. **Receiving Alerts:** If the fridge door is left open beyond the set time, the alarm will trigger, and WhatsApp notifications will be sent.



