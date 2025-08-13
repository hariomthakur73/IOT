/*
  Coded by : HARIOM DANGI ECE DEPARTMENT (IGEC)
*/

#include <ESP8266WiFi.h>        // LIBRARY FOR ESP8266 WIFI AND  FOR ESP 32 IT IS <ESPWiFi.h>
#include <ESP8266HTTPClient.h>  // LIBRARY FOR SEND HTTP REQUEST FROM  ESP8266 TO WEB SERVER  AND  FOR ESP 32 IT IS <ESPHTTPClient.h>
#include <WiFiClient.h>         // Creates a TCP/IP client that can connect to servers like ThingSpeak or any web server
#include <ThingSpeak.h>         //It is the official ThingSpeak library that lets you send data to channels or read from channels on Thingspeak.com
//************************************************************************************************************************************
#define pot_pin D2  // DECLARE DIGITAL PINS FOR BUTTONS
#define pot_pin1 D3
#define pot_pin2 D4
#define pot_pin3 D5
//*******************************************************************************************
int pot_val = 0;  // SET BUTTON STATE 0
int pot_val1 = 0;
int pot_val2 = 0;
int pot_val3 = 0;
//*******************************************************************************************
const char* ssid = "Tenda_Repeater";  // set wifi for to esp to connect
const char* password = "Indore@123";
WiFiClient client;
//******************************************************************************************
unsigned long myChannelNumber = 3017940;         // channel number from thinsspeak
const char* myWriteAPIKey = "5RSYOT654A4QJBW1";  // WRITE API key from your channel to WRITE data TO THE CLOUD
//*****************************************************************************************************************************************************
void setup() {
  Serial.begin(115200);                    // Remember to match this value with the baud rate in your console
  WiFi.begin(ssid, password);              // WIFI STARTING PROCESS
  Serial.print("Connecting");              // READY TO CONNECT
  while (WiFi.status() != WL_CONNECTED) {  // CHECK IF WIFI CONNECTED OR NOT
    delay(500);
    Serial.print(".");
  }
  //********************************************************************************************************************************************
  Serial.println("\nConnected to the Wi-Fi Network: " + String(ssid) + "\n IP Address: ");
  Serial.print(WiFi.localIP());  // CREATE LOCAL IP ADDRESS FOR CLIENT
  Serial.println("");
  ThingSpeak.begin(client);  // CLIENT START
  //***********************************************************************************************************************************************
  pinMode(pot_pin, INPUT_PULLUP);  //SET ALL BUTTON AS HIGH/1
  pinMode(pot_pin1, INPUT_PULLUP);
  pinMode(pot_pin2, INPUT_PULLUP);
  pinMode(pot_pin3, INPUT_PULLUP);
}
//**************************************************************************************************************************************************
void loop() {
  //  pot_val = analogRead(pot_pin);
  (pot_val = digitalRead(pot_pin));  // CHECK BUTTON STATE AND STORE IT IN POT_VALUE
  Serial.println("--Sending Data to Cloud B1--");
  Serial.println(pot_val);
  ThingSpeak.setField(1, pot_val);  // WRITE POT_VALUE IN  CLOUD IN FIELD 1
  //************************************************************************************************************
  (pot_val1 = digitalRead(pot_pin1));
  Serial.println("--Sending Data to Cloud--B2");
  Serial.println(pot_val1);
  ThingSpeak.setField(2, pot_val1);
  //******************************************************************************************************************
  (pot_val2 = digitalRead(pot_pin2));
  Serial.println("--Sending Data to Cloud--B3");
  Serial.println(pot_val2);
  ThingSpeak.setField(3, pot_val2);
  //*************************************************************************************************************
  (pot_val3 = digitalRead(pot_pin3));
  Serial.println("--Sending Data to Cloud--B4");
  Serial.println(pot_val3);
  ThingSpeak.setField(4, pot_val3);
  //**************************************************************************************************************
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  //********************************************************************************************************************
  if (x == 200) {  // FOR CHECK DATA UPLOAD OR NOT
    Serial.println("✅ Data uploaded successfully to ThingSpeak");
  } else {
    Serial.print("❌ Problem uploading. HTTP error code: ");
    Serial.println(x);
  }
  //********************************************************************************************************************

  delay(16000);
}
