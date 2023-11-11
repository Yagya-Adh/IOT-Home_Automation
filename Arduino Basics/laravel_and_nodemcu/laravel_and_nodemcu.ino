#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const char* serverUrl = "http://yourlaravelapp.com/api/data"; // Change this URL

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Create your JSON data to send
    String jsonPayload = "{\"data\": \"your_data_here\"}";

    int httpResponseCode = http.POST(jsonPayload);
    if (httpResponseCode > 0) {
      Serial.println("HTTP Response Code: " + String(httpResponseCode));
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.println("HTTP Request failed.");
    }

    http.end();
    delay(5000); // Delay before sending the next request
  }
}
