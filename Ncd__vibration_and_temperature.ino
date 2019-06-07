///this code is written and tested for ncd.io IoT Long Range Wireless Vibration Temperature with arduino due
///sensor data structure can be found here https://store.ncd.io/product/long-range-iot-wireless-vibration-temperature-sensor/
/// sensor can be found here https://ncd.io/long-range-iot-wireless-vibration-sensor-product-manual/

#include <HardwareSerial.h>
//HardwareSerial Serial1(1); // use uart2
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#define WIFISSID "xyz" // Put your WifiSSID here
#define PASSWORD "xyz" // Put your wifi password here
#define TOKEN "xyz" // Put your Ubidots' TOKEN
#define MQTT_CLIENT_NAME "xyz" // MQTT client Name, please enter your own 8-12 alphanumeric character ASCII string; 
//it should be a random and unique ascii string and different from all other devices

/****************************************
   Define Constants
 ****************************************/
#define VARIABLE_LABEL "sensor"// Assing the variable label
#define VARIABLE_LABEL1 "AdcValue"
#define VARIABLE_LABEL2 "Battery"
#define VARIABLE_LABEL3 "RMS_X"
#define VARIABLE_LABEL4 "RMS_Y"
#define DEVICE_LABEL "esp32" // Assig the device label
uint8_t data[54];
int k = 10;
int i;
char mqttBroker[]  = "industrial.api.ubidots.com";
char payload[100];
char topic[150];
char topic2[150];
char topic3[150];
char topic4[150];
char topic5[150];
// Space to store values to send
char str_sensor[10];
char str_sensorbat[10];
char str_sensorAdc[10];
char  str_sensorRmsx[10];
char  str_sensorRmsy[10];
/****************************************
   Auxiliar Functions
 ****************************************/
WiFiClient ubidots;
PubSubClient client(ubidots);

void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  String message(p);
  Serial.write(payload, length);
  Serial.println(topic);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");

    // Attemp to connect
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Connected");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}
void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFISSID, PASSWORD);
  // Assign the pin as INPUT
  Serial1.begin(115200, SERIAL_8N1, 16, 17); // pins 16 rx2, 17 tx2, 19200 bps, 8 bits no parity 1 stop bit​
  Serial.begin(9600);
  Serial.println("ncd.io IoT ESP32 Vibration Temperature sensor");

  Serial.println();
  Serial.print("Wait for WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqttBroker, 1883);
  client.setCallback(callback);

}
void loop() {
  if (!client.connected()) {
    reconnect();
  }


  data[0] = Serial1.read();
  delay(k);
  if (data[0] == 0x7E)
  {
    while (!Serial1.available());
    for ( i = 1; i < 54; i++)
    {
      data[i] = Serial1.read();
      delay(1);
    }
    if (data[15] == 0x7F) /////// to check if the recive data is correct
    {
      if (data[22] == 0x08) //////// make sure the sensor type is correct
      {
        int16_t rms_x = ((uint16_t)(((data[24]) << 16) + ((data[25]) << 8) + (data[26])) / 100);
        int16_t rms_y = ((uint16_t)(((data[27]) << 16) + ((data[28]) << 8) + (data[29])) / 100);
        int16_t rms_z = ((uint16_t)(((data[30]) << 16) + ((data[31]) << 8) + (data[32])) / 100);

        int16_t max_x = ((uint16_t)(((data[33]) << 16) + ((data[34]) << 8) + (data[35])) / 100);
        int16_t max_y = ((uint16_t)(((data[36]) << 16) + ((data[37]) << 8) + (data[38])) / 100);
        int16_t max_z = ((uint16_t)(((data[39]) << 16) + ((data[40]) << 8) + (data[41])) / 100);

        int16_t min_x = ((uint16_t)(((data[42]) << 16) + ((data[43]) << 8) + (data[44])) / 100);
        int16_t min_y = ((uint16_t)(((data[45]) << 16) + ((data[46]) << 8) + (data[47])) / 100);
        int16_t min_z = ((uint16_t)(((data[48]) << 16) + ((data[49]) << 8) + (data[50])) / 100);


        int cTemp = ((((data[51]) * 256) + data[52]));
        float battery = ((data[18] * 256) + data[19]);
        float voltage = 0.00322 * battery;
        Serial.print("Sensor Number  ");
        Serial.println(data[16]);
        Serial.print("Sensor Type  ");
        Serial.println(data[22]);
        Serial.print("Firmware Version  ");
        Serial.println(data[17]);
        Serial.print("Temperature in Celsius :");
        Serial.print(cTemp);
        Serial.println(" C");

        Serial.print("RMS vibration in X-axis :");
        Serial.print(rms_x);
        Serial.println(" mg");
        Serial.print("RMS vibration in Y-axis :");
        Serial.print(rms_y);
        Serial.println(" mg");
        Serial.print("RMS vibration in Z-axis :");
        Serial.print(rms_z);
        Serial.println(" mg");

        Serial.print("Min vibration in X-axis :");
        Serial.print(min_x);
        Serial.println(" mg");
        Serial.print("Min vibration in Y-axis :");
        Serial.print(min_y);
        Serial.println(" mg");
        Serial.print("Min vibration in Z-axis :");
        Serial.print(min_z);
        Serial.println(" mg");

        Serial.print("ADC value:");
        Serial.println(battery);
        Serial.print("Battery Voltage:");
        Serial.print(voltage);
        Serial.println("\n");
        if (voltage < 1)
        {
          Serial.println("Time to Replace The Battery");
        }
        dtostrf(cTemp, 4, 2, str_sensor);
        dtostrf(battery, 4, 2, str_sensorAdc);
        dtostrf(voltage, 4, 2, str_sensorbat);
        dtostrf(rms_x, 4, 2, str_sensorRmsx);
        dtostrf(rms_y, 4, 2, str_sensorRmsy);
      }
    }
    else
    {
      for ( i = 0; i < 54; i++)
      {
        Serial.print(data[i]);
        Serial.print(" , ");
        delay(1);
      }
    }
  }
    sprintf(topic, "%s", ""); // Cleans the topic content
    sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);

    sprintf(payload, "%s", ""); // Cleans the payload content
    sprintf(payload, "{\"%s\":", VARIABLE_LABEL); // Adds the variable label   
    sprintf(payload, "%s {\"value\": %s", payload, str_sensor); // Adds the value
    sprintf(payload, "%s } }", payload); // Closes the dictionary brackets
    client.publish(topic, payload);
    
    sprintf(topic2, "%s", ""); // Cleans the topic content
    sprintf(topic2, "%s%s", "/v1.6/devices/", DEVICE_LABEL);

    sprintf(payload, "%s", ""); // Cleans the payload content
    sprintf(payload, "{\"%s\":", VARIABLE_LABEL1); // Adds the variable label   
    sprintf(payload, "%s {\"value\": %s", payload, str_sensorAdc); // Adds the value
    sprintf(payload, "%s } }", payload); // Closes the dictionary brackets
    
    client.publish(topic2, payload);
    sprintf(topic3, "%s", ""); // Cleans the topic content
    sprintf(topic3, "%s%s", "/v1.6/devices/", DEVICE_LABEL);

    sprintf(payload, "%s", ""); // Cleans the payload content
    sprintf(payload, "{\"%s\":", VARIABLE_LABEL2); // Adds the variable label   
    sprintf(payload, "%s {\"value\": %s", payload,  str_sensorbat); // Adds the value
    sprintf(payload, "%s } }", payload); // Closes the dictionary brackets
    
    client.publish(topic3, payload);
    sprintf(topic4, "%s", ""); // Cleans the topic content
    sprintf(topic4, "%s%s", "/v1.6/devices/", DEVICE_LABEL);

    sprintf(payload, "%s", ""); // Cleans the payload content
    sprintf(payload, "{\"%s\":", VARIABLE_LABEL3); // Adds the variable label   
    sprintf(payload, "%s {\"value\": %s", payload,  str_sensorRmsx); // Adds the value
    sprintf(payload, "%s } }", payload); // Closes the dictionary brackets
    
    client.publish(topic4, payload);
     sprintf(topic5, "%s", ""); // Cleans the topic content
    sprintf(topic5, "%s%s", "/v1.6/devices/", DEVICE_LABEL);

    sprintf(payload, "%s", ""); // Cleans the payload content
    sprintf(payload, "{\"%s\":", VARIABLE_LABEL4); // Adds the variable label   
    sprintf(payload, "%s {\"value\": %s", payload,  str_sensorRmsy); // Adds the value
    sprintf(payload, "%s } }", payload); // Closes the dictionary brackets
    
    client.publish(topic5, payload);
    client.loop();
    delay(1000);
}
