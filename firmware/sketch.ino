#include "DHTesp.h"

#define DHT_PIN 15

DHTesp dhtSensor;

void setup() {
  Serial.begin(115200);

  Serial.println("================================");
  Serial.println("NexaSense - IoT Security Lab");
  Serial.println("Inicializando dispositivo...");
  Serial.println("================================");

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  Serial.println("[INFO] Sensor DHT22 configurado.");
  Serial.println("[INFO] Sistema iniciado.");
}

void loop() {
  TempAndHumidity dados = dhtSensor.getTempAndHumidity();

  if (isnan(dados.temperature) || isnan(dados.humidity)) {
    Serial.println("[ERRO] Falha na leitura do sensor!");
  } else {
    Serial.print("[DADOS] Temperatura: ");
    Serial.print(dados.temperature);
    Serial.println(" C");

    Serial.print("[DADOS] Umidade: ");
    Serial.print(dados.humidity);
    Serial.println(" %");
  }

  Serial.println("[DEBUG] Leitura finalizada.");
  Serial.println("--------------------------------");

  delay(2000);
}
