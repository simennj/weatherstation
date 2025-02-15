/* Weather station
 * @author: Nikhil André Luthra - Bouvet Norge
 * @web: weather.labben.org
 * @web: bouvet.no / nikhil.luthra.no
 * Lesson 05 - Connect to WiFi and read weather data
 */
#include <ESP8266WiFi.h> 
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  

//Oppgave: inkluder ArduinoJson biblioteket fra Benoît Blanchon

WiFiClient client;
char* host = "weather.labben.org";
const int httpPort = 80;

void setup() {
  Serial.begin(115200);
  Serial.println("Running setup");
  
  WiFiManager wifiManager;
  wifiManager.autoConnect("WeatherStation");

  Serial.println("Connected to WiFi");
}


void doRequest(String location){
      if (!client.connect(host, httpPort)) {
        Serial.println("doRequest failed"); 
      }else{
          String url = "/api/yr/?location=" + location;
          
          Serial.print("requesting URL: ");
          Serial.print(host);
          Serial.println(url);
         
          client.print(String("GET ") + url + " HTTP/1.0\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP8266YrClient\r\n" +
               "Content-Type: application/json\r\n" + 
               "Connection: close\r\n\r\n");

         // Sjekker om HTTP status vi fikk tilbake var 200OK eller ei.
          char status[32];
          client.readBytesUntil('\r', status, sizeof(status));
          char * statusCode;
          strtok(status, " ");
          statusCode = strtok(NULL, " ");
          if (strcmp(statusCode, "200") != 0) {
            Serial.print(F("Unexpected response: "));
            Serial.println(status);
            return;
          }
        
          // Hopper over HTTP Headers i responsen.
          char endOfHeaders[] = "\r\n\r\n";
          if (!client.find(endOfHeaders)) {
            Serial.println(F("Invalid response"));
            return;
          }

         //Oppgave: Opprett DynamicJsonDocument med størrelse på 250bytes.
         
         
         
         //Oppgave: kall deserializeJson med jsonDocument og client som argument.
         
        
         //Oppgave: forsikkre deg om at jsonDocument inneholder "status"
          if(!jsonDocument.containsKey(?????)) {
            Serial.println("parseObject() failed");
          }else{

            //Oppgave: les og skriv ut resultatet fra jsonDocument. 
            // Se på http://weather.labben.org/api/yr/?location=Norge/Oslo/Oslo/Oslo/ for å se hvilken data du får i retur.
            
            
            

           }
        
      }
}

void loop() {
  //Oppgave: kall doRequest med lokasjon som String argument. 
  /*
   * Lokasjonstreng får du ved å finne et sted på yr.no og kopiere siste del av URL. 
   * For Oslo ser det slik ut: Norge/Oslo/Oslo/Oslo (fra URLen: https://www.yr.no/sted/Norge/Oslo/Oslo/Oslo/)
   */
  
  
  delay(10000); //Bruk fornuftig delay her. Været oppdaterer seg ikke SÅ ofte. 
                //Yr forventer at man cacher resultatet man henter fra dem i minst 20 minutter, men det er håndtert på endepunktet vi går via.
}
