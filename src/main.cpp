#include <Arduino.h>
#include "BluetoothSerial.h" 
#define LED 2

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;


void setup() {
  Serial.begin(115200); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32_LED_Control"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED, OUTPUT);//Specify that LED pin is output
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED, LOW);
delay(1000);
digitalWrite(LED, HIGH);
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED, LOW);
delay(1000);
digitalWrite(LED, HIGH);
 }
void loop() {
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49)
        {
        digitalWrite(LED, HIGH);
        ESP_BT.println("LED turned ON");
        }
        
    if (incoming == 48)
        {
        digitalWrite(LED, LOW);
        ESP_BT.println("LED turned OFF");
        }     
  }
  delay(20);
}