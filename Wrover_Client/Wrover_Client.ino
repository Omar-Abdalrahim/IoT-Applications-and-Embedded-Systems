#include "ESP8266WiFi.h"

// Replace with your network credentials
const char* ssid = "Mi 10T";
const char* password = "25111975";

// Replace with the IP address of the receiver (server)
const char* host = "192.168.197.172"; // Replace with actual IP of the receiver

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
}

void loop() {
  // Connect to the receiver (server)
  WiFiClient client;
  if (client.connect(host, 80)) {
    Serial.println("Connected to receiver!");

    // Send data
    client.println("Hello from Sender!");
    Serial.println("Data sent!");

    // Close connection
    client.stop();
  } else {
    Serial.println("Failed to connect to receiver!");
  }

  // Wait for a while before sending again
  delay(10000);
}
