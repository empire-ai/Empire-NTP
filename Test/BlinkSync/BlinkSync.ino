/*
  Blink

  Based off the original Blink:
  Turns the RED LED on for one second, then off for one second, repeatedly.
  Changed to include sync for future NTP implementation

  This code has been adapted to fit DS Apollo line products. You can find more info about the products:
  https://www.digitalsputnik.com

  Use the board from: https://dl.espressif.com/dl/package_esp32_index.json
  ESP32 Wroom Module (default 4MB with spifffs)

  modified 24 Aug 2021
  by Kaspar Kallas

  This example code is in the public domain.

  Original example:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

// the number of the LED pin
int ledPin = 33;  // RED(33) LED

// TODO
// EmpNTP NTPmanager;
// Create EmpNTP.test() functionality using aUnit library
// Test are run in setup and other functions are never called (disable the xTaskCreatePinnedToCore())
// Test ideas:
//  1. Does server answer
//  2. is there a time difference
//  3. after second attempt is difference eq or better than before, is it within 3ms?
// Start WiFi

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // WiFi
  // client mode
  wifiMulti.addAP("network1", "dsputnik");
  // add another AP to the list, ESP will connect to the 1st one avaiable prefering by strength
  // wifiMulti.addAP("network2", "pwd2");
  Serial.println("Connecting Wifi...");
  if(wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
  // master mode:
  // WiFi.mode(WIFI_AP);
  // WiFi.mode(WIFI_AP_STA);
  // WiFi.softAP("Voyager-T001", "dsputnik");
  
  // TODOD
  // setup timesync and change the blinking led Green (25) if the lamp is synced
  // if running server use different color led, enable only one line
  // if(NTPmanager.sync("192.168.1.1",30,sessionHash[64])) ledPin = 25;
  // if(NTPmanager.server(NTPmanager.ControllerMode,sessionHash[64])) ledPin = 26;
  
  // setup analog output for the white chanel on PWM channel 0
  ledcSetup(0, 19000, 12);
  ledcAttachPin(ledPin, 0);
}

// the loop function runs over and over again forever
void loop() {
  if(millis()%2000>1000)  // loop over 2 seconds ON/OFF
  {
    ledcWrite(0, 64);     // max is 2048, remember how much current can Your USB support...
  } 
  else 
  {
    ledcWrite(0, 0);      // turn the LED off by making the voltage 0
  }
}
