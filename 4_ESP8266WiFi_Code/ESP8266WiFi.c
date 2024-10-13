#include <ESP8266WiFi.h>           // Include the ESP8266 WiFi library
#include "SSD1306Spi.h"           // Include the SSD1306 OLED display library

// Create an instance of the SSD1306 display using specified pins
SSD1306Spi display(D0, D2, D8);

// Initialize a string variable to store incoming data
String i;

// Create a WiFi server that listens on port 80
WiFiServer server(80);

void setup() {
    i = "";                       // Initialize the string to be empty
    Serial.begin(9600);          // Start serial communication at 9600 baud rate
    display.init();              // Initialize the OLED display
    WiFi.disconnect();           // Disconnect from any existing WiFi connection
    delay(3000);                 // Wait for 3 seconds
    // Connect to the specified WiFi network with SSID and password
    WiFi.begin("SDM", "Satyam12345"); 
    Serial.println("Connecting to wifi");
    
    // Wait until connected to the WiFi network
    while ((!(WiFi.status() == WL_CONNECTED))) {
        delay(300);               // Wait 300 ms before checking again
        Serial.print("...");      // Print dots to indicate connection progress
    }
    
    Serial.println("I am Connected");           // Print confirmation message
    Serial.println((WiFi.localIP()));            // Print local IP address assigned by the router
    server.begin();                              // Start the WiFi server
}

void loop() {
    display.clear();                             // Clear the display
    WiFiClient client = server.available();      // Check for incoming clients
    if (!client) { return; }                     // If no client is connected, exit the loop
    
    while (!client.available()) { delay(1); }   // Wait until the client sends data
    
    // Read the incoming data until a carriage return is received
    i = (client.readStringUntil('\r'));        
    // Remove the first 5 characters from the string
    i.remove(0, 5);
    // Remove the last 9 characters from the string
    i.remove(i.length() - 9, 9);
    
    display.setTextAlignment(TEXT_ALIGN_LEFT);   // Set text alignment to left
    display.setFont(ArialMT_Plain_16);           // Set the font for display
    display.drawString(0, 0, i);                  // Draw the string on the display at position (0, 0)
    display.display();                             // Update the display with the new content
    delay(2000);                                   // Wait for 2 seconds before repeating
}

