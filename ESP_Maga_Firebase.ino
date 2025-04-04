/*
Pamir Software IT Solution
Mohammad Azimi
*/

#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <Wire.h>
#endif
#include <Firebase_ESP_Client.h>


//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "Your WIFI"
#define WIFI_PASSWORD "Your Password"

// Insert Firebase project API Key
#define API_KEY "AIzaSyCWf2EYQDUoxDSqSPSHLXkJs8r7LgqibF0"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://temp-9b830-default-rtdb.firebaseio.com/"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
bool signupOK = false;

void setup() {

  Serial.begin(115200);
  Serial1.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
    pinMode(LedPin, OUTPUT);
    pinMode(LedPins, OUTPUT);
     pinMode(LedPinss, OUTPUT);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {

  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 100 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
       if (Firebase.RTDB.getInt(&fbdo, "/LivingRoom/Lamp")) {
      if (fbdo.dataType() == "int") {
        intValue = fbdo.intData();
      
       if (Serial.available()) {
       String receivedMessage = Serial.readStringUntil('\n');
       Serial.println(intValue);
       //Serial.println(receivedMessage);
  }

      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }


  }
}
