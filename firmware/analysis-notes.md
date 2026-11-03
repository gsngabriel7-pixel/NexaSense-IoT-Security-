# Análise Inicial do Firmware — NexaSense

## Objetivo

Realizar uma inspeção inicial do código-fonte do firmware utilizado no protótipo NexaSense, identificando funcionalidades implementadas e possíveis pontos de atenção relacionados à segurança.

## 1. Comunicação serial

O firmware utiliza `Serial.begin(115200)` para inicializar a comunicação serial.

As mensagens exibidas incluem informações de inicialização, estado do sensor, temperatura e umidade.

**Ponto de atenção:** caso a interface serial esteja acessível fisicamente em um dispositivo real, essas informações poderão ser observadas por alguém com acesso à interface.

## 2. Autenticação e controle de acesso

Não foi identificada implementação de autenticação ou controle de acesso no código analisado.

Essa funcionalidade não está presente no escopo atual do firmware.

## 3. Criptografia e comunicação de rede

Não foram identificadas implementações de criptografia, conexão Wi-Fi ou protocolos de comunicação de rede.

Portanto, não é possível avaliar a segurança de uma comunicação de rede com base somente neste firmware.

## 4. Atualização de firmware

Não foi identificado mecanismo de atualização OTA (Over-The-Air).

A segurança do processo de atualização ainda precisa ser investigada caso essa funcionalidade faça parte do produto real.

## 5. Tratamento de erros

O firmware verifica se os valores de temperatura e umidade são válidos utilizando `isnan()`.

Quando ocorre uma falha na leitura, uma mensagem de erro é exibida no Serial Monitor.

## 6. Pontos que exigem investigação

- Exposição de informações pela interface serial.
- Possibilidade de acesso físico não autorizado às interfaces de depuração.
- Ausência de autenticação no firmware atual.
- Ausência de mecanismos de comunicação segura no protótipo.
- Ausência de mecanismo de atualização OTA.

## 7. Limitações da análise

A análise foi realizada por inspeção do código-fonte de um protótipo simulado no Wokwi.

Não foram realizados testes em hardware físico, análise de memória flash, inspeção de interfaces UART/JTAG ou testes de comunicação de rede.

## Conclusão

A inspeção inicial identificou funcionalidades básicas de leitura do sensor e depuração serial. Também identificou recursos de segurança que não estão implementados no firmware atual.

Esses pontos serão aprofundados nas próximas etapas, sem presumir a existência de vulnerabilidades não demonstradas.
