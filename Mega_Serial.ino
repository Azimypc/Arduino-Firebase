/*
Pamir Software IT Solution
Mohammad Azimi

in this case Arduino Mage Connect to ESP8266 and ESP8266 Read Data from Firebase
and send via serial Commication to Arduino Mega.
hier my Arduino mega is connectet to a Realy with 16 channel
*/



#include <Wire.h>


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 


void setup() {
  Serial.begin(115200);   // Start serial communication with the PC
  Serial1.begin(115200);
  pinMode(39, OUTPUT); //1
  pinMode(38, OUTPUT); //2
  pinMode(41, OUTPUT); //3
  pinMode(40, OUTPUT); //4
  pinMode(43, OUTPUT); //5
  pinMode(42, OUTPUT); //6
  pinMode(45, OUTPUT); //7 
  pinMode(44, OUTPUT); //8
  pinMode(47, OUTPUT); //9    
  pinMode(46, OUTPUT); //10 
  pinMode(49, OUTPUT); //11
  pinMode(48, OUTPUT); //12
  pinMode(51, OUTPUT); //13
  pinMode(50, OUTPUT); //12
  pinMode(53, OUTPUT); //15
  pinMode(52, OUTPUT); //16         

}
void loop() {
  // Check if data is available from the ESP8266
  if (Serial1.available()) {
    String message = Serial1.readStringUntil('\n'); 

  Serial.println(message); // Print the received message to the Serial Monitor

if(message.toInt() == 1){
    digitalWrite(39, HIGH);
}
if(message.toInt() == 2){
    digitalWrite(39, LOW);
}

if(message.toInt() == 3){
    digitalWrite(38, HIGH);
}
if(message.toInt() == 4){
    digitalWrite(38, LOW);
}
  

  if(message.toInt() == 5){
    digitalWrite(41, HIGH);
}
if(message.toInt() == 6){
    digitalWrite(41, LOW);
}
  

  if(message.toInt() == 7){
    digitalWrite(40, HIGH);
}
if(message.toInt() == 8){
    digitalWrite(40, LOW);
}
  

if(message.toInt() == 9){
    digitalWrite(43, HIGH);
}
if(message.toInt() == 10){
    digitalWrite(43, LOW);
}
  

  if(message.toInt() == 11){
    digitalWrite(42, HIGH);
}
if(message.toInt() == 12){
    digitalWrite(42, LOW);
}
  

  if(message.toInt() == 13){
    digitalWrite(45, HIGH);
}
if(message.toInt() == 14){
    digitalWrite(45, LOW);
}
  

  if(message.toInt() == 15){
    digitalWrite(44, HIGH);
}
if(message.toInt() == 16){
    digitalWrite(44, LOW);
}
  

  if(message.toInt() == 17){
    digitalWrite(47, HIGH);
}
if(message.toInt() == 18){
    digitalWrite(47, LOW);
}
  


  if(message.toInt() == 19){
    digitalWrite(46, HIGH);
}
if(message.toInt() == 20){
    digitalWrite(46, LOW);
}
  

if(message.toInt() == 21){
    digitalWrite(49, HIGH);
}
if(message.toInt() == 22){
    digitalWrite(49, LOW);
}
  
  if(message.toInt() == 23){
    digitalWrite(48, HIGH);
}
if(message.toInt() == 24){
    digitalWrite(48, LOW);
}
  
  if(message.toInt() == 25){
    digitalWrite(51, HIGH);
}
if(message.toInt() == 26){
    digitalWrite(51, LOW);
}
  

  if(message.toInt() == 27){
    digitalWrite(50, HIGH);
}
if(message.toInt() == 28){
    digitalWrite(50, LOW);
}
  

  if(message.toInt() == 29){
    digitalWrite(52, HIGH);
}
if(message.toInt() == 30){
    digitalWrite(52, LOW);
}

  if(message.toInt() == 31){
    digitalWrite(53, HIGH);
}
if(message.toInt() == 32){
    digitalWrite(53, LOW);
}
  

  if(message.toInt() == 33){
    digitalWrite(51, HIGH);
}
if(message.toInt() == 34){
    digitalWrite(51, LOW);
}
  }
  // Example of sending data back to ESP8266 (optional)
  Serial1.println(); 
  delay(100); // Wait for a second
}