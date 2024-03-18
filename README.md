# Leanios-ot-api-cpp
Leanios REST and MQTT Client for Sensors, counters and energy meters. Connect your sensors easily with Leanios!
This is a cpp library that provides MQTT and REST API clients for sending data from 3 OT to a server. The library allows the client to choose which method to use or use both at the same time.
# installation of the needed libraries : 
# httpclient and Arduinojson
Open Arduino IDE.
Go to "Sketch" > "Include Library" > "Manage Libraries...".
Search for "HttpClient" and "ArduinoJson".
Click on each library and hit "Install".
Wait for the installation to complete.
Verify installation under "Sketch" > "Include Library".

This guide demonstrates how to use the Leanios OT API client library to interact with Leanios MES (Manufacturing Execution System) platform for posting various data readings. This readme is intended to help you understand and utilize the library effectively.

## Installation Leanios-ot-api-cpp

Ensure you have the leanios-ot-api-cpp library installed in your Arduino IDE. Follow the steps below to add the library to your Arduino IDE:

Download the LeanIOS-OT-API-CPP library as a zip file .
Open the Arduino IDE.
Go to "Sketch" > "Include Library" > "Add Leanios-ot-api-cpp.ZIP Library".
Select the ZIP file you created and click "Open".
Wait for the installation to complete.
Verify the installation under "Sketch" > "Include Library".

## Usage

To use the Leanios OT API library in your Arduino sketch, follow the example code provided below:

#include <ArduinoJson.h>
#include <LeaniosRestclient.h> // Include the LeaniosRestclient header file

// WiFi credentials
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

// Leanios API credentials
String api_key = "your_api_key";
String api_password = "your_api_password";
String subdomain = "your_subdomain";

// Initialize LeaniosRestclient object with credentials
Leanios::OtApi::LeaniosRestclient restClient(subdomain, api_key, api_password);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Your data sending code here
}

void loop() {
  // Your loop code here
}
#Data_Sending

# Send Sensor Data

restClient.send_sensor_datapoint(
uuid: 'the serial numbe of uuid', # [required]in here, you put the uuid of the sensor
machine_id: id number of the machine, # [optional] in here, you put the machine id number
sensor_id : id number of the machine, # [optional] in here , you put the sensor id number
sensor_name: 'the sensor name', # [required] in here, you put the sensor name
sensor_value: value of the sensor # [required] in here, you put the sensor value
);
# Send Energy Data

restClient.send_energy_datapoint(
uuid: 'the serial numbe of uuid', # [required]in here, you put the uuid of the sensor
machine_id: id number of the machine, # [optional] in here, you put the machine id number
sensor_id : id number of the machine, # [optional] in here , you put the sensor id number
value: 'value of the ot_energy, # [required] in here, you put the sensor name
name: 'name of the ot_energy' # [required] in here, you put the sensor value
unit: 'the unit of the ot_energy' # [required] in here, you put the unit used with the value of the ot_energy
);
# Send Count Data

restClient.send_count_datapoint(
uuid: 'the serial numbe of uuid', # [required]in here, you put the uuid of the sensor
machine_id: id number of the machine, # [optional] in here, you put the machine id number
sensor_id : id number of the machine, # [optional] in here , you put the sensor id number
counter_type: "type of parts", # [required] in here, you put the type of the parts (good/bad/etc..)
count: value of the count # [required] in here, you put the count value
);
Note: You must either provide machine_id or sensor_id for each data sending function.

==> This guide should help you integrate the Leanios OT API library into your Arduino projects effectively.
This readme provides an overview of the library, its installation process, and usage examples for sending different types of data to the Leanios MES platform using the Leanios OT API library.
