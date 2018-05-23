#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FirebaseArduino.h>

#include "config.h"

void setup() {
   Serial.begin(115200);
  
  // on demande la connexion au WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  // on attend d'etre connecte au WiFi avant de continuer
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // on affiche l'adresse IP qui nous a ete attribuee
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  // on definit ce qui doit etre fait lorsque la route /bonjour est appelee
  // ici on va juste repondre avec un "hello !"

  initSensor();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(void){
  Serial.println(String(readTemperature()));
  Serial.println(String(readHumidity()));

  // set value
  Firebase.setFloat("temperature", readTemperature());
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /temperature failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  // update value
  Firebase.setFloat("humidity", readHumidity());
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /humdity failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

}

