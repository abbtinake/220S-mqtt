#include "EspMQTTClient.h"
//Install libraries PubSubClient and EspMQTTClient
const byte RightMotorTol = 5; //14
const byte RightMotorTur = 0; // 12

int throttle = 0;
int turning = 0;



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
  Serial.begin(9600);
  
  pinMode(RightMotorTur, OUTPUT);
  digitalWrite(RightMotorTur, HIGH);
  }


void loop () {
    digitalWrite(RightMotorTur, HIGH);
    analogWrite(RightMotorTol, nospeed);
    delay(2000);
    analogWrite(RightMotorTol, minspeed);
    delay(2000);
    analogWrite(RightMotorTol, maxspeed);
    delay(2000);
    analogWrite(RightMotorTol, minspeed);
    delay(2000);
    analogWrite(RightMotorTol, nospeed);
    delay(2000);
    }



void onConnectionEstablished()
{
  client.subscribe("tindra/turning", [] (const String &payload)
  {
    Serial.println(payload);
    payload.toInt();
    turning = payload;
  });

  client.subscribe("tindra/throttle", [] (const String &payload)
  {
    payload.toInt();
    Serial.println(payload);
    throttle = payload;
  });
  
}

