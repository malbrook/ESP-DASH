/*
* ESP-DASH V2
* Made by Ayush Sharma
* Github URL: https://github.com/ayushsharma82/ESP-DASH
* Support Me: https://www.patreon.com/asrocks5
*
* - Version Changelog - 
* V1.0.0 - 11 Nov. 2017 - Library was Born
* V1.0.1 - 13 Nov. 2017 - Fixed Empty SPIFFS Issue
* V1.0.2 - 13 Nov. 2017 - Improvements on SPIFFS Issue
* V1.0.3 - 24 Dec. 2017 - Pushing to Library Manager
*
* = Library Rewritten! =
* V2.0.0 - 25 Jan 2019 - Wohoo! A breakthrough in performance and capabilities!
*/


// This Example is a Demo of the using  the slidercard with the gauge to display the values from moving the slider
// Slider only updates the values when the button is released. 


#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPDash.h>

AsyncWebServer server(80);

const char* ssid     = ""; // Your WiFi SSID
const char* password = ""; // Your WiFi Password


int newValue;

// callback to receive the new value from the slider
void sldCallback(const char* id, int thevalue){
  newValue = thevalue;
  Serial.println("Slider changed on Dash, ID - " + String(id) + "-" + String(newValue));
  //update gauge from slider
  ESPDash.updateGaugeChart("gauge1", newValue);
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    // Initiate ESPDash and attach your Async webserver instance
    ESPDash.init(server);   
    
    // add event handlers
    ESPDash.attachButtonClick(btnCallback);
    ESPDash.attachSliderChanged(sldCallback);

    
    // Add Respective Cards
    // valid values for direction are 
    // bottom to top 0
    // top to bottom 1
    // left to right 2
    // right to left 3 
    ESPDash.addSliderCard("slid1", "Slider 1",3);
    // add a number card to display the slider value
    ESPDash.addNumberCard("num1", "Number Card", 0);
    // add a gauge to display the slider value
    ESPDash.addGaugeChart("gauge1", "Gauge 1", 0);
    server.begin();
}

void loop() {
    // update number card on a cyclic timer this is not synchronised with the slider changes
    ESPDash.updateNumberCard("num1", newValue);
    delay(3000);
}
