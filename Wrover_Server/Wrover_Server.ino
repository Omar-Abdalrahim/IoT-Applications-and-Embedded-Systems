#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "Mi 10T";
const char* password = "25111975";

WiFiServer server(80); // TCP server on port 80

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
  Serial.print("Server IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available(); // Check for incoming clients
  if (client) {
    Serial.println("Client connected!");
    
    // Wait until the client sends some data
    while (client.connected()) {
      if (client.available()) {
        String data = client.readStringUntil('\n'); // Read the incoming data
        Serial.print("Received data: ");
        Serial.println(data); // Print the data to the Serial Monitor

        // Optionally send a response to the client
        client.println("Data received!");
      }
    }

    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
  }
}

