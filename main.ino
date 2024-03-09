#include <Servo.h>
#include  <ESP8266WiFi.h>
#include "PageIndex.h"
#include <ESP8266WebServer.h>


#define STATION_IF      0x00
ESP8266WebServer server(80);

extern "C" {
#include "user_interface.h"
#include "wpa2_enterprise.h"
#include "c_types.h"
}

char ssid[] = "IITJ_WLAN";
char username[] = "b23ch1025";
char identity[] = "b23ch1025";
char password[] = "badpyn-mEqwoj-cukpi6";

Servo myservo;

void handleRoot() {
 String s = MAIN_page; 
 server.send(200, "text/html", s); 
}

void handleServo(){
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();
  myservo.write(pos);   
  delay(15);
  Serial.print("Servo Angle:");
  Serial.println(pos);
  server.send(200, "text/plane","");
}

void setup() {

  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  delay(1000);
  Serial.setDebugOutput(true);
  Serial.printf("SDK version: %s\n", system_get_sdk_version());
  Serial.printf("Free Heap: %4d\n",ESP.getFreeHeap());
  myservo.attach(2);

   wifi_set_opmode(STATION_MODE);

  struct station_config wifi_config;

  memset(&wifi_config, 0, sizeof(wifi_config));
  strcpy((char*)wifi_config.ssid, ssid);
  strcpy((char*)wifi_config.password, "router RADIUS password");
  

  wifi_station_set_wpa2_enterprise_auth(1);

  wifi_station_clear_cert_key();
  wifi_station_clear_enterprise_ca_cert();
  wifi_station_clear_enterprise_identity();
  wifi_station_clear_enterprise_username();
  wifi_station_clear_enterprise_password();
  wifi_station_clear_enterprise_new_password();

  wifi_station_set_enterprise_identity((uint8*)identity, strlen(identity));
  wifi_station_set_enterprise_username((uint8_t *)username, strlen(username));                
  wifi_station_set_enterprise_password((uint8_t *)password, strlen(password));
  
wifi_station_set_config(&wifi_config);
wifi_station_connect();

  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.print(".");
    Serial.print(wifi_station_get_connect_status());
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/",handleRoot);  
  server.on("/setPOS",handleServo); 
  server.begin();  
  Serial.println("HTTP server started");
}

void loop() {
   server.handleClient();
} 
