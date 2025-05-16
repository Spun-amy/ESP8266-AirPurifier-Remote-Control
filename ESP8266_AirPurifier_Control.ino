#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wi-Fi Setting
const char* ssid = "Asp";
const char* password = "spspsp";

// Webserver on port 80 
ESP8266WebServer server(80);

// GPIO4 pin connected to relay controlling the air purifier fan (D2 on Esp8266 NodeMCU)
const int relayPin = 4; 

void setup() {
  Serial.begin(115200);

  // Set relay active HIGH for initially 
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Fan ON (active HIGH)

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n Connected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define HTTP routes
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "ESP8266 Air Purifier Fan Contraoller");
  });

  server.on("/on", HTTP_GET, []() {
    digitalWrite(relayPin, HIGH);  // Turn relay On for 
    server.send(200, "text/plain", "Air purifier fan is ON");
    Serial.println("Fan turned ON");
  });

  server.on("/off", HTTP_GET, []() {
    digitalWrite(relayPin, LOW);   // Relay OFF
    server.send(200, "text/plain", "Air purifier fan is OFF");
    Serial.println("Fan turned OFF");
  });

  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();
}
