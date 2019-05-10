#include "UbidotsESPMQTT.h"
#include <Wire.h>


/****************************************
  Define Constants and Instances
****************************************/
#define Addr 0x44
#define TOKEN "BBFF-fEk7qnwFMJ4Dg1xDUiBj1peaGDqz5T" // Your Ubidots TOKEN
#define WIFINAME "abhishek" // Your SSID
#define WIFIPASS "abhishek" // Your Wifi Pass
#define MQTTCLIENTNAME "9cfg3f86" // Your MQTT Client Name, it must be unique so we recommend to choose a random ASCCI name

Ubidots client(TOKEN, MQTTCLIENTNAME);

/****************************************
  Auxiliar Functions
****************************************/
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/****************************************
  Main Functions
****************************************/
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
   // Initialise I2C communication as MASTER
  Wire.begin(4,5);
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    client.reconnect();
  }
   unsigned int data[6];
  
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Send measurement command
  Wire.write(0x2C);
  Wire.write(0x06);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(500);

  // Request 6 bytes of data
  Wire.requestFrom(Addr, 6);

  // Read 6 bytes of data
  // cTemp msb, cTemp lsb, cTemp crc, humidity msb, humidity lsb, humidity crc
  if (Wire.available() == 6)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    data[2] = Wire.read();
    data[3] = Wire.read();
    data[4] = Wire.read();
    data[5] = Wire.read();
  }

  // Convert the data
  float cTemp = ((((data[0] * 256.0) + data[1]) * 175) / 65535.0) - 45;
  float fTemp = (cTemp * 1.8) + 32;
  float humidity = ((((data[3] * 256.0) + data[4]) * 100) / 65535.0);

  // Output data to serial monitor
  Serial.print("Relative Humidity : ");
  Serial.print(humidity);
  Serial.println(" %RH");
  Serial.print("Temperature in Celsius : ");
  Serial.print(cTemp);
  Serial.println(" C");
  Serial.print("Temperature in Fahrenheit : ");
  Serial.print(fTemp);
  Serial.println(" F");
  delay(500);
  client.add("temperature", cTemp);
   delay(1000);
  Serial.println("my cal calculated temp");
  client.ubidotsPublish("control");
  client.loop();
}
