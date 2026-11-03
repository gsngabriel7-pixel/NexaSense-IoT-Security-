# Arquitetura do Dispositivo — NexaSense

## 1. Visão geral

O protótipo NexaSense utiliza um ESP32 conectado a um sensor DHT22 para realizar medições de temperatura e umidade.

O microcontrolador executa um firmware desenvolvido em C++ (Arduino), responsável por inicializar o sensor, obter as medições e exibir os resultados por meio da comunicação serial.

## 2. Componentes

| Componente | Função |
|---|---|
| ESP32 | Processamento e execução do firmware |
| DHT22 | Medição de temperatura e umidade |
| GPIO15 | Recebimento dos dados do sensor |
| Serial | Exibição de informações de depuração |
| Wokwi | Ambiente de simulação do protótipo |

## 3. Fluxo de funcionamento

1. O ESP32 é inicializado.
2. O firmware configura o sensor DHT22.
3. O sensor fornece as medições ao ESP32 pelo GPIO15.
4. O firmware processa as informações.
5. Os resultados são apresentados no Serial Monitor.

## 4. Interfaces identificadas

- GPIO15: comunicação de dados com o sensor.
- 3V3 e GND: alimentação do sensor.
- Interface serial: saída de informações de depuração.

## 5. Limitações

A arquitetura documentada representa exclusivamente o protótipo simulado no Wokwi.

Interfaces físicas UART e JTAG, memória flash, conectividade Wi-Fi e comunicação com serviços externos ainda não foram verificadas em hardware real.
