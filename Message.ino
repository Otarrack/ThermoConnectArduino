#include <Adafruit_Sensor.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <string.h>

char inputbuffer[6] = { '\0' };
char outputbuffer[20] = { '\0' }; 

static DHT dht(DHT_PIN, DHT_TYPE);
void initSensor()
{
    dht.begin();
}

float readTemperature()
{
    return dht.readTemperature();
}

float readHumidity()
{
    return dht.readHumidity();
}

void sendMessage() {
    float temperature = readTemperature();
    float humidity = readHumidity();
 
}

//bool readMessage(int messageId, char *payload)
//{
//    float temperature = readTemperature();
//    float humidity = readHumidity();
//    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
//    JsonObject &root = jsonBuffer.createObject();
//    root["deviceId"] = DEVICE_ID;
//    root["messageId"] = messageId;
//    bool temperatureAlert = false;
//
//    
//    root.printTo(payload, MESSAGE_MAX_LEN);
//    return temperatureAlert;
//}
//
//void parseTwinMessage(char *message)
//{
//    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
//    JsonObject &root = jsonBuffer.parseObject(message);
//    if (!root.success())
//    {
//        Serial.printf("Parse %s failed.\r\n", message);
//        return;
//    }
//}

