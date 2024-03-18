#include "leanios-ot-api-cpp.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

using namespace Leanios::OtApi;

LeaniosRestclient::LeaniosRestclient(const String& subdomain, const String& api_key, const String& api_password)
    : subdomain(subdomain), api_key(api_key), api_password(api_password) {
    base_url = "https://" + api_key + ":" + api_password + "@" + subdomain + ".leanios.com/api/v1";
}

int LeaniosRestclient::post_data(const String& path, const String& json_data) {
    HTTPClient http;
    http.begin(base_url + path); // Initialize the URL

    http.addHeader("Content-Type", "application/json"); // Specify content-type header

    int httpResponseCode = http.POST(json_data); // Send the request
    http.end(); // Close connection

    return httpResponseCode; // Return HTTPresponse code
}

int LeaniosRestclient::send_sensor_datapoint(const String& id_value, const String& t_value, const int& v_value) {
    String path = "/ot/sensor"; // Assuming "/api/v1" is the base URL
    StaticJsonDocument<200> doc;

    // Create JSON object
    doc["id"] = id_value;
    doc["t"] = t_value;
    doc["v"] = v_value;
 // Example value

    String output;
    serializeJson(doc, output); // Serialize JSON to string

    return post_data(path, output); // Post the data
}


int LeaniosRestclient::send_count_datapoint(const String& uuid, const int& machine_id, const String& counter_type, const float& count, const int& sensor_id){
    String path = "/ot/counter";
    StaticJsonDocument<200> doc;

    // Create JSON object
    doc["uuid"] = uuid;
    doc["machine_id"] = machine_id;
    doc["counter_type"] = counter_type;
    doc["count"] = count;
    doc["sensor_id"] = sensor_id;

    String output;
    serializeJson(doc, output); // Serialize JSON to string

    return post_data(path, output); // Post the data
}

int LeaniosRestclient::send_energy_datapoint(const String& uuid, const String& name, const int& machine_id, const String& unit, const int& value, const int& sensor_id) {
    String path = "/ot/energy";
    StaticJsonDocument<200> doc;

    // Create JSON object
    doc["uuid"] = uuid;
    doc["name"] = name;
    doc["machine_id"] = machine_id;
    doc["unit"] = unit;
    doc["value"] = value;
    doc["sensor_id"] = sensor_id;

    String output;
    serializeJson(doc, output); // Serialize JSON to string

    return post_data(path, output); // Post the data
}
