#include "EspMQTTClient.h"
#include <Servo.h>
//Install libraries PubSubClient and EspMQTTClient
const byte RightMotorTol = 5; //14
const byte RightMotorTur = 0; // 12

Servo Servot;
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

  Servot.attach(D8);
  
  pinMode(RightMotorTur, OUTPUT);
  digitalWrite(RightMotorTur, HIGH);
  }


void loop () {
  client.loop();
  }



void onConnectionEstablished(){
  client.subscribe("tindra/turning", [] (const String &payload)
  {
    Serial.println(payload);
    if(payload == "LEFT"){
      Servot.write(90);
      digitalWrite(RightMotorTur, HIGH);
      } else if(payload == "RIGHT"){
      Servot.write(0);
      digitalWrite(RightMotorTur, HIGH);
    }else if(payload == "FORWARD"){
      Servot.write(45);
      digitalWrite(RightMotorTur, HIGH);
    }else if(payload == "BACKWARD"){
      Servot.write(45);
      digitalWrite(RightMotorTur, LOW);
  }});

  client.subscribe("tindra/throttle", [] (const String &payload)
  {
    payload.toInt();
    Serial.println(payload);
    throttle = payload.toInt()*10;
    analogWrite(RightMotorTol, throttle);
  });
  
}