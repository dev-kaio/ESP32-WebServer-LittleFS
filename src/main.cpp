#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>

const char *ssid = "Kaiolito";
const char *password = "12345678";

WebServer server(80);

const int ledBuiltIn = 2;
const int ledPin16 = 16;
const int ledPin17 = 17;

void handleRoot() {
  File file = LittleFS.open("/index.html", "r");
  if (!file) {
    server.send(404, "text/plain", "Arquivo index.html não encontrado");
    return;
  }
  server.streamFile(file, "text/html");
  file.close();
}

void setup() {
  Serial.begin(9600);

  // Configura pinos dos LEDs
  pinMode(ledBuiltIn, OUTPUT);
  pinMode(ledPin16, OUTPUT);
  pinMode(ledPin17, OUTPUT);
  digitalWrite(ledBuiltIn, LOW);
  digitalWrite(ledPin16, LOW);
  digitalWrite(ledPin17, LOW);

  // Inicia o Wi-Fi em modo AP (ponto de acesso)
  WiFi.softAP(ssid, password);
  Serial.println("WiFi Iniciado");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  // Monta o sistema de arquivos
  if (!LittleFS.begin()) {
    Serial.println("Erro ao montar LittleFS");
    return;
  }

  // Rota principal (serve index.html)
  server.on("/", HTTP_GET, handleRoot);

  // Rotas para controle dos LEDs
  server.on("/2/on", HTTP_GET, []() {
    digitalWrite(ledBuiltIn, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/2/off", HTTP_GET, []() {
    digitalWrite(ledBuiltIn, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/16/on", HTTP_GET, []() {
    digitalWrite(ledPin16, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/16/off", HTTP_GET, []() {
    digitalWrite(ledPin16, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/17/on", HTTP_GET, []() {
    digitalWrite(ledPin17, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.on("/17/off", HTTP_GET, []() {
    digitalWrite(ledPin17, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
  });

  // Inicia o servidor
  server.begin();
  Serial.println("Servidor iniciado.");
}

void loop() {
  server.handleClient();
}
