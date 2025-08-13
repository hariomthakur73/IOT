/*
  Coded by : HARIOM DANGI ECE DEPARTMENT (IGEC)
*/
#include <ESP8266WiFi.h>        // LIBRARY FOR ESP8266 WIFI AND  FOR ESP 32 IT IS <ESPWiFi.h>  
#include <ESP8266HTTPClient.h>  // LIBRARY FOR SEND HTTP REQUEST FROM  ESP8266 TO WEB SERVER  AND  FOR ESP 32 IT IS <ESPHTTPClient.h>
#include <WiFiClient.h>        // Creates a TCP/IP client that can connect to servers like ThingSpeak or any web server
#include <ThingSpeak.h>        //It is the official ThingSpeak library that lets you send data to channels or read from channels on Thingspeak.com
//****************************************************************************
#define led D2  // DECLARE DIGITAL PINS FOR LED 
#define led1 D3 
#define led2 D4
#define led3 D5
//*****************************************************************************
const char* ssid = "Tenda_Repeater"; // set wifi for to esp to connect   
const char* password = "Indore@123";
WiFiClient client;
//*****************************************************************************
unsigned long myChannelNumber = 3017940;  // channel number from thinsspeak 
const char* myReadAPIKey = "EEEPK3FG2XHRD2GF"; // read api key from your channel to read data from it 
//*****************************************************************************
int myFeildNumber = 1;  //  define the field numbers from a ThingSpeak channel that your ESP8266 will read data from.
int myFeildNumber1 = 2;
int myFeildNumber2 = 3;
int myFeildNumber3 = 4;
//******************************************************************************
void setup() {
  Serial.begin(115200);  // Remember to match this value with the baud rate in your console
  pinMode(led, OUTPUT);  // setup led as a output 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
//*******************************************************************************
  WiFi.begin(ssid, password);  // WIFI STARTING PROCESS
  Serial.print("Connecting to : " + String(ssid));
  while (WiFi.status() != WL_CONNECTED) { // CHECK IF WIFI CONNECTED OR NOT 
    delay(500);
    Serial.print(".");
  }
//******************************************************************************
  Serial.println("\nConnected to WiFi network: " + String(ssid));
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // CREATE LOCAL IP ADDRESS FOR CLIENT 
  ThingSpeak.begin(client); // CLIENT START 
}
//*******************************************************************************
void loop() {
  Serial.println("--Getting Data from cloud --B1");
  long data_in = ThingSpeak.readLongField(myChannelNumber, myFeildNumber, myReadAPIKey);
  Serial.println(data_in);
//****************************************************************************************************
  Serial.println("--Getting Data from cloud--B2");
  long data_in1 = ThingSpeak.readLongField(myChannelNumber, myFeildNumber1, myReadAPIKey);
  Serial.println(data_in1);
//*****************************************************************************************************
  Serial.println("--Getting Data from cloud--B3");
  long data_in2 = ThingSpeak.readLongField(myChannelNumber, myFeildNumber2, myReadAPIKey);
  Serial.println(data_in2);
//*****************************************************************************************************
  Serial.println("--Getting Data from cloud--B4");
  long data_in3 = ThingSpeak.readLongField(myChannelNumber, myFeildNumber3, myReadAPIKey);
  Serial.println(data_in3);
  //*****************************************************************************************************************************************************
  if (data_in == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  //*******************************************************************************************************************************************************
  if (data_in1 == 1) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  //*****************************************************************************************************************************************************
  if (data_in2 == 1) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
  //***************************************************************************************************************************************************
  if (data_in3 == 1) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
  //*****************************************************************************************************************************************************
Serial.println("DATA RECEVIED");
delay(7000);
  /*
   /*  for (int i = 0; i <= 4; i++) {

      digitalWrite(led[i], HIGH);
    }
    for (int i = 4; i >= 0; i++) {

      digitalWrite(led[i], LOW);
    }*/
}
