#ifndef LEANIOS_REST_CLIENT_H
#define LEANIOS_REST_CLIENT_H

#include <ArduinoJson.h>  // Include ArduinoJson library for JSON handling
#include <HTTPClient.h>   // Include HTTPClient library for making HTTP requests

namespace Leanios {
    namespace OtApi {

class LeaniosRestclient {
private:
    String subdomain;
    String api_key;
    String api_password;
    String base_url;

public:
    // Constructor
    LeaniosRestclient(const String& subdomain, const String& api_key, const String& api_password);

    // Method to post data
    int post_data(const String& path, const String& json_data);

    // Post data sensor
    int send_sensor_datapoint(const String& id_value, const String& t_value, const int& v_value) ;

    // Post data counter
    int send_count_datapoint(const String& uuid, const int& machine_id, const String& counter_type, const float& count, const int& sensor_id);

    // Post data energy
    int send_energy_datapoint(const String& uuid, const String& name, const int& machine_id, const String& unit, const int& value, const int& sensor_id);
};

    }
}

#endif
