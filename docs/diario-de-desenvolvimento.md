# Diário de Desenvolvimento — NexaSense IoT Security

## Etapa 1 — Montagem e validação funcional do protótipo

**Objetivo:** desenvolver e validar uma representação funcional do dispositivo IoT NexaSense.

### Ambiente utilizado
- Plataforma: Wokwi.
- Microcontrolador: ESP32.
- Linguagem: C++ (Arduino).
- Sensor: DHT22.
- Biblioteca: DHT sensor library for ESPx.

### Montagem
O sensor DHT22 foi conectado ao ESP32 utilizando:
- VCC: alimentação de 3,3 V.
- DATA: GPIO15.
- GND: aterramento.
- NC: sem conexão.

### Testes realizados
Foi desenvolvido um firmware para inicializar o sensor e realizar leituras periódicas de temperatura e umidade.

### Resultados
- Temperatura simulada: 24 °C.
- Umidade simulada: 40%.
- Intervalo entre leituras: 2 segundos.
- Comunicação entre ESP32 e DHT22: funcional na simulação.

### Evidências
- `evidence/circuito_esp32_dht22.png`
- `evidence/serial_monitor_leituras.png`

### Limitações
Os testes foram realizados exclusivamente em ambiente simulado. Não foram realizados testes físicos em uma placa ESP32 real.

### Status
Etapa concluída — protótipo funcional validado no Wokwi.
