#include "EspMQTTClient.h"
//Install libraries PubSubClient and EspMQTTClient


void onConnectionEstablished();


//Nya sättet!
EspMQTTClient client(
 "ABBgym_2.4",           // Wifi ssid
  "mittwifiarsabra",           // Wifi password
  "aedes-broker.cloud.mustini.se",  // MQTT broker ip
  "tindra2",            // MQTT username
  "",       // MQTT password
  "",          // Client name
  9696            // MQTT broker port
);
 

void setup() {

Serial.begin(115200);
}



void onConnectionEstablished()
{
  client.subscribe("tindra/direction", [] (const String &payload)
  {
    Serial.log(payload);
    payload.toInt();
  });

  client.subscribe("tindra/distance", [] (const String &payload)
  {
    Serial.log(payload);
    payload.toInt();
  });
  
}