#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "PRINCE";
const char *password = "senyumdulu";

int LED1 = D0;
int LED2 = D2;
int LED3 = D4;

ESP8266WebServer server(80);

String webpage;

void setup()
{
  Serial.begin(9600);
  delay(10);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("Access Point SSID: ");
  Serial.println(WiFi.softAPSSID());

  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());

  webpage += "<h1>Web Control ESP8266</h1>";
  webpage += "<h2>Nama Ahmad Rian</h2>";
  webpage += "<p>LED 1: ";
  webpage += "<a href=\"LED1ON\"\"><button>ON</button></a>&nbsp;<a href=\"LED1OFF\"\"><button>OFF</button></a></p><br></a>";
  webpage += "<p>LED 2: ";
  webpage += "<a href=\"LED2ON\"\"><button>ON</button></a>&nbsp;<a href=\"LED2OFF\"\"><button>OFF</button></a></p><br></a>";
  webpage += "<p>LED 3: ";
  webpage += "<a href=\"LED3ON\"\"><button>ON</button></a>&nbsp;<a href=\"LED3OFF\"\"><button>OFF</button></a></p><br></a>";

  server.on("/", []()
            { server.send(200, "text/html", webpage); });

  server.on("/LED1ON", []()
            {
    digitalWrite(LED1, HIGH);
    server.send(200, "text/html", webpage);
    delay(1000); });

  server.on("/LED1OFF", []()
            {
    digitalWrite(LED1, LOW);
    server.send(200, "text/html", webpage);
    delay(1000); });
  server.on("/LED2ON", []()
            {
    digitalWrite(LED2, HIGH);
    server.send(200, "text/html", webpage);
    delay(1000); });
  server.on("/LED2OFF", []()
            {
    digitalWrite(LED2, LOW);
    server.send(200, "text/html", webpage);
    delay(1000); });
  server.on("/LED3ON", []()
            {
    digitalWrite(LED3, HIGH);
    server.send(200, "text/html", webpage);
    delay(1000); });
  server.on("/LED3OFF", []()
            {
    digitalWrite(LED3, LOW);
    server.send(200, "text/html", webpage);
    delay(1000); });
  server.onNotFound([]()
                    { server.send(404, "text/html", "<h1>404 Not Found</h1>"); });
  server.begin();
  Serial.println("Webserver dijalankan");
}
void loop()
{
  server.handleClient();
}
