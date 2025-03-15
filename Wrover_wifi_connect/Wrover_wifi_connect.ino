#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your network credentials
const char* ssid = "Mi 10T";
const char* password = "25111975";

void setup() {
  // Start serial communication at a baud rate of 9600
  Serial.begin(115200);
  
  // Wait for 2 seconds (2000 milliseconds)
  delay(1000);
  
  // Print a message after the delay
  Serial.println("Wrover Connected");

  WiFi.begin(ssid, password);
  Serial.println("Connecting to Wi-Fi...");
  
  // Wait for the connection to succeed
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
 
  
 // Wait for 2 seconds (2000 milliseconds)
  delay(1000);
  
  // Print a message after the delay
  Serial.println("This message is printed after 1 seconds!");
}