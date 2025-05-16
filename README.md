# ESP8266-AirPurifier-Remote-Control
This project remotely control an air purifier using a NodeMCU ESP8266 board, a relay module, and Postman  via HTTP GET requests.

## ESP8266-AirPurifier-Control
This project allows to control an air purifier fan remotely using an ESP8266 

## Features
- Controls air purifier fan via Wifi
- Simple endpoints for ON/OFF control

## Hardware Required,
| Component             | Quantity |
|----------------------|----------|
| ESP8266 (NodeMCU)     | 1        |
| Relay module (5V)    | 1        |
| Air purifier   | 1 |
| HLK-PM01 (AC to 5V power supply)   | 1        |
| 24V DC Adapter (power to air purifier)    | 1        |

## Circuit Wiring / Power and Control Diagram
![Air Purifier Circuit Diagram]([https://github.com/Spun-amy/ESP8266-Airpurifier-Remote-Control/blob/main/airpurifier_circuit_diagram.jpg?raw=true](https://github.com/Spun-amy/ESP8266-AirPurifier-Remote-Control/blob/4092c680e1efc7f6317afc4910c977c7ccf8bf8f/Airpurifier%20control%20circuit%20diagram.jpg) 

## How to Use 
1. Installation and Setup.
2. Upload the code in the Arduino IDE.
3. Connect components as shown in the diagram
4. Plug in 220V AC - relay will power on.
5. Get the IP Address
6. Use Postman to send GET requests (on/off).

## API Endpoints,
| Endpoint        | Method | Description             |
|----------------|--------|-------------------------|
| /            | GET    | Check if device is running |
| /on          | GET    | Turn the fan ON         |
| /off         | GET    | Turn the fan OFF        |
