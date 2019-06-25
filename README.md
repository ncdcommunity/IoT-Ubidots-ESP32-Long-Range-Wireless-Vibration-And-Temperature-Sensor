Vibration is truly a to and fro movement—or oscillation—of machines and components in motorized gadgets. Vibration in the industrial system may be a symptom, or motive, of a hassle, or it can be associated with everyday operation. For instance, oscillating sanders and vibratory tumblers depend upon vibration to feature. Internal combustion engines and tools drive, then again, revel in a sure amount of unavoidable vibration. Vibration can imply a hassle and if left unchecked can cause harm or expedited deterioration. Vibration can be resulting from one or extra factors at any given time, the maximum not unusual being an imbalance, misalignment, put on, and looseness.This damage can be minimize by analyzing Temperature and Vibration Data on Ubidots  using esp32 and NCD wireless vibration and temperature sensor.
![alt tag](https://github.com/mjScientech/https-github.com-mjScientech-ESP32-AND-SI7021/blob/master/Vibration-Temp-NO-Zigmo-600x400.png)
# IoT Long Range Wireless Vibration And Temperature Sensor
IoT Long Range Wireless Vibration And Temperature Sensor is battery operated and wireless, meaning that current or communication wires need not be pulled to get it up and operating. It tracks the vibration information of your machine constantly and captures and operate hours at full resolution together with other temperature parameters. This information is then transferred for ongoing diagnosis of the health of your machine to Ubidots safe cloud in real time. It is best suited for industrial devices such as engines, fans, pumps and compressors to rotate and reciprocate.
In this we are using NCD’s Long Range IoT Industrial wireless vibration and temperature sensor, boasting up to a 2 Mile range using a wireless mesh networking architecture. Incorporating a precision 16-bit vibration and temperature sensor, this device transmits highly accurate vibration and temperature data at user-defined intervals.

![alt tag](https://github.com/mjScientech/https-github.com-mjScientech-ESP32-AND-SI7021/blob/master/Zigmo_1.png)
# Long Range Wireless Mesh Modem with USB Interface
Your computer can speaks to a ZB ZigBee Network using a Coordinator.  Think of the Coordinator as the interface to a ZB ZigBee Network.  NCD ZigBee Coordinators are equipped with a USB Interface.  USB Coordinators mount as a Serial Port on your computer, and you will develop software that sends Serial commands at 115.2K Baud.  Only ONE Coordinator should be installed within a wireless ZB ZigBee Network.  Two types of Coordinators are available.  AT and API.  Normally, AT coordinators are used.  AT coordinators use Terminal-like AT commands to speak to a ZB ZigBee Network.  They are easier to use than an API coordinator.  An API coordinator uses a string of carefully chosen bytes and checksums to communicate data to a ZigBee networking.  API coordinators are harder to use, but can communicate and switch between devices much faster.  This page will introduce you to AT coordinators.  You can choose between AT and API firmware at checkout.
![alt tag](https://github.com/mjScientech/ESP32-AND-SI7021/blob/master/ESP32_1.png)
# ESP-32
The ESP32 makes it easy to use the Arduino IDE and the Arduino Wire Language for IoT applications. This ESp32 IoT Module combines Wi-Fi, Bluetooth, and Bluetooth BLE for a variety of diverse applications. This module comes fully-equipped with 2 CPU cores that can be controlled and powered individually, and with an adjustable clock frequency of 80 MHz to 240 MHz. This ESP32 IoT WiFi BLE Module with Integrated USB is designed to fit in all ncd.io IoT products.

Monitor sensors and control relays, FETs, PWM controllers, solenoids, valves, motors and much more from anywhere in the world using a web page or a dedicated server.

We manufactured our own version of the ESP32 to fit into NCD IoT devices, offering more expansion options than any other device in the world! Integrated USB port allows easy programming of the ESP32. The ESP32 IoT WiFi BLE Module is an incredible platform for IoT application development. This ESP32 IoT WiFi BLE Module can be programmed using Arduino IDE.

Hardware :
- [ESP-32](https://store.ncd.io/product/esp32-iot-wifi-ble-module-with-integrated-usb/)
- [IoT Long Range Wireless Vibration And Temperature Sensor](https://store.ncd.io/product/iot-long-range-wireless-vibration-and-temperature-sensor/)
- [I2C Cable](https://store.ncd.io/product/i2c-cable/)
- [PARTICLE ELECTRON OR PHOTON COMPATIBLE I2C SHIELD](https://shop.controleverything.com/products/i2c-breakout-for-particle-electron-or-particle-photon)
- [Long Range Wireless Mesh Modem with USB Interface](https://store.ncd.io/product/zigbee-coordinator-long-range-wireless-mesh-modem-with-usb-interface/)

Software Used:
- Arduino IDE
- [Ubidot](https://ubidots.com/)

Library Used:
- PubSubClient Library
- Wire.h

# Arduino Client for MQTT
This library provides a client for doing simple publish/subscribe messaging with a server that supports MQTT

For more information about MQTT, visit [mqtt.org](http://mqtt.org/).
## Download
The latest version of the library can be downloaded from [GitHub](https://github.com/knolleary/pubsubclient/releases/tag/v2.7)
## Documentation
The library comes with a number of example sketches. See File > Examples > PubSubClient within the Arduino application.
Full [API Documentation](https://pubsubclient.knolleary.net/api.html).
## Compatible Hardware
The library uses the Arduino Ethernet Client api for interacting with the underlying network hardware. This means it Just Works with a growing number of boards and shields, including:

- Arduino Ethernet
- Arduino Ethernet Shield
- Arduino YUN – use the included YunClient in place of EthernetClient, and be sure to do a Bridge.begin() first
- Arduino WiFi Shield - if you want to send packets greater than 90 bytes with this shield, enable the [MQTT_MAX_TRANSFER_SIZE]  (https://pubsubclient.knolleary.net/api.html#configoptions) option in   PubSubClient.h.
- Sparkfun WiFly Shield – when used with [this](https://github.com/dpslwk/WiFly) library
- Intel Galileo/Edison
- ESP8266
- ESP32
The library cannot currently be used with hardware based on the ENC28J60 chip – such as the Nanode or the Nuelectronics Ethernet Shield. For those, there is an alternative library available.

# Wire Library
  The Wire library allows you to communicate with I2C devices, often also called "2 wire" or "TWI" (Two Wire Interface),can download  from [Wire.h](https://github.com/PaulStoffregen/Wire)
## Basic Usage
- Wire.begin()
  Begin using Wire in master mode, where you will initiate and control data transfers. This is the most common use when interfacing with   most I2C peripheral chips.

- Wire.begin(address)
  Begin using Wire in slave mode, where you will respond at "address" when other I2C masters chips initiate communication.
  
 ## Transmitting
 - Wire.beginTransmission(address)
   Start a new transmission to a device at "address". Master mode is used.

- Wire.write(data)
  Send data. In master mode, beginTransmission must be called first.

- Wire.endTransmission()
  In master mode, this ends the transmission and causes all buffered data to be sent.
  
## Receiving
- Wire.requestFrom(address, count)
  Read "count" bytes from a device at "address". Master mode is used.

- Wire.available()
  Retuns the number of bytes available by calling receive.

- Wire.read()
  Receive 1 byte.

# Steps to send data to labview vibration and temperature platform using IoT Long Range Wireless Vibration And Temperature Sensor and  Long Range Wireless Mesh Modem with USB Interface-

- First, we need a Labview utility application which is [ncd.io Wireless Vibration and Temperature Sensor.exe](https://github.com/ncdcommunity/Industrial-IoT-Vibration-Temperature-Sensor) file on which data can be viewed.

- This Labview software will work with ncd.io wireless Vibration Temperature sesnor only

- To use this UI, you will need to install following drivers Install run time engine from here [64bit](http://www.ni.com/download/labview-run-time-engine-2017/6821/en/)

- [32 bit](http://www.ni.com/download/labview-run-time-engine-2017/6822/en/)

- Install [NI Visa Driver](http://www.ni.com/download/ni-visa-run-time-engine/6647/en/)

- Install [LabVIEW Run-Time Engine]( http://www.ni.com/download/labview-run-time-engine-2017-sp1/7191/en/) and [NI-Serial Runtime]  (http://www.ni.com/download/ni-serial-17.0/6613/en/)

- [Getting started guide for this product.](https://ncd.io/long-range-iot-wireless-vibration-sensor-getting-started/)

##  Uploading the code  to ESP32 using Arduino IDE:
- **Download and include the PubSubClient Library and Wire.h Library.**
- **You must assign your unique Ubidots TOKEN, MQTTCLIENTNAME, SSID (WiFi Name) and Password of the available network.**
- **Compile and upload the  [Ncd__vibration_and_temperature.ino](https://github.com/mjScientech/https-github.com-mjScientech-ESP32-AND-SI7021/blob/master/Ncd__vibration_and_temperature.ino) code.**
- **To verify the connectivity of the device and the data sent, open the serial monitor.If no response is seen, try unplugging your ESP32 and then plugging it again. Make sure the baud rate of the Serial monitor is set to the same one specified in your code 115200.**

## Serial monitor output.
![alt tag](https://github.com/mjScientech/https-github.com-mjScientech-ESP32-AND-SI7021/blob/master/vibration%20serial.JPG)

## Making the Ubidot work:
- **Create the account on [Ubidot](https://ubidots.com/).**
- **Go to my profile and note down the token key which is a unique key for every account and paste it to your ESP32 code before uploading.**
- **Add a new device to your ubidot dashboard name esp32.**
  
![alt tag](https://github.com/mjScientech/Esp32-And-SHT30/blob/master/device234.JPG)

                       Click on devices and select devices in ubidot.

![alt tag](https://github.com/mjScientech/ESP32-AND-SI7021/blob/master/Device.JPG)

     Now you should see the published data in your Ubidots account, inside the device called "ESP32".

- **Inside device create new variable name sensor in which your temperature reading will be shown.**
![alt tag](https://github.com/mjScientech/ESP32-AND-SI7021/blob/master/variable.JPG)
                  
         
![alt tag](https://github.com/mjScientech/https-github.com-mjScientech-ESP32-AND-SI7021/blob/master/variableout.JPG)

     Now you are able to view the Temperature and other sensors data which was previously viewed in serial monitor.This
     happened because the value of  different sensor readings  is passed as a string and store in
     variable and publish to variable inside  device esp32. 
- **Create dashboard in ubidots**
![alt tag](https://github.com/mjScientech/https-github.com-mjScientech-ESP32-AND-SI7021/blob/master/dashboard1.JPG)
       
          Go to data select dashboard and inside dashboard create different widgets and add new widget 
          to your dashboard screen.
# OUTPUT
- **Now as the temperature/vibration  increases and decreases new data available inside the various variable.**
![alt tag](https://github.com/mjScientech/ESP32-AND-Long-range-temperature-and-vibration-sensor/blob/master/outputncd%20vibration.PNG)

