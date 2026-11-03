# Análise de Comunicação e Protocolos — NexaSense

## 1. Objetivo

Verificar os mecanismos de comunicação utilizados pelo protótipo NexaSense e identificar possíveis pontos de atenção relacionados à segurança das informações transmitidas.

## 2. Comunicação identificada

O firmware atual utiliza comunicação serial com velocidade de 115200 baud para apresentar mensagens de inicialização, temperatura, umidade e informações de depuração.

## 3. Protocolos de rede

Durante a inspeção do código-fonte, não foram identificadas implementações de:

- Wi-Fi;
- HTTP ou HTTPS;
- MQTT;
- TCP ou UDP em nível de aplicação;
- Comunicação com servidores externos.

## 4. Análise de segurança

Como o protótipo não possui comunicação de rede implementada, não foi possível avaliar autenticação de rede, criptografia de tráfego, integridade de mensagens ou segurança de protocolos.

A comunicação serial observada foi documentada separadamente como um ponto de exposição de informações.

## 5. Limitações

A análise foi baseada no firmware atual e na simulação do Wokwi.

Não foram realizadas capturas de pacotes com Wireshark, pois não existe tráfego de rede do dispositivo para analisar nesta versão.

## 6. Conclusão

O protótipo atual utiliza comunicação serial para apresentar as leituras do sensor. A conectividade de rede ainda não foi implementada.

Uma futura versão do NexaSense deverá ser avaliada quanto à autenticação, confidencialidade e integridade das comunicações.
