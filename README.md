# Smart Medication Dispenser

## Overview
A smart medication dispenser integrating with Google Calendar to send reminders and dispense medication automatically at scheduled times. This project uses NodeMCU (ESP8266), a servo motor, and a buzzer for functionality.

## Features
- **Google Calendar Integration**: Syncs with Google Calendar events.
- **Automated Dispensing**: Dispenses medication as scheduled.
- **Reminders**: Audible buzzer and LED indicators.

## Hardware Requirements
- NodeMCU (ESP8266)
- Servo motor
- Buzzer
- LED
- Jumper wires
- Medication container

## Setup Instructions
1. **Calendar Setup**: Create and share a public calendar in Google Calendar.
2. **Event Scheduling**: Schedule medication events.
3. **Dispenser Configuration**: Enter the calendar link on the dispenser’s web interface.
4. **Dispensing Process**: The dispenser activates at the scheduled time, dispensing medication and triggering reminders.

## How to Use
1. **Open Web Interface**: Connect to NodeMCU’s WiFi and navigate to its IP address.
2. **Enter Calendar Link**: Input the Google Calendar link.
3. **Set Servo Position**: Use the slider to set the servo position.

## Repository Contents
- **`main_code.ino`**: Arduino code for NodeMCU.
- **`index.html`**: Web interface for configuration and control.

## License
This project is licensed under the MIT License.

For detailed instructions and code, refer to the respective files in the repository.
