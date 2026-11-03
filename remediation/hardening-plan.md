# Plano de Mitigação e Hardening — NexaSense

## 1. Objetivo

Definir medidas de segurança para reduzir os riscos identificados durante a avaliação do protótipo NexaSense e orientar o desenvolvimento de uma versão mais segura do dispositivo.

## 2. Medidas de mitigação

### 2.1 Proteção da interface serial

- Remover mensagens de depuração desnecessárias da versão de produção.
- Evitar transmitir informações sensíveis pela interface serial.
- Restringir fisicamente o acesso aos pinos de depuração.

### 2.2 Proteção das interfaces UART e JTAG

- Avaliar a necessidade de manter interfaces de depuração habilitadas.
- Restringir o acesso físico às interfaces.
- Utilizar mecanismos de proteção disponíveis no ESP32 para impedir acessos não autorizados.

### 2.3 Proteção do firmware

- Avaliar a implementação de Secure Boot.
- Avaliar o uso de Flash Encryption.
- Preservar cópias do firmware e registrar seus hashes SHA-256.
- Controlar alterações e versões do código-fonte.

### 2.4 Segurança das atualizações

- Implementar mecanismos de atualização autenticada.
- Verificar a integridade e autenticidade dos arquivos de atualização.
- Impedir a instalação de firmware não autorizado.

### 2.5 Segurança da comunicação

Caso a conectividade Wi-Fi seja implementada:

- Utilizar protocolos de comunicação protegidos.
- Implementar autenticação entre dispositivo e servidor.
- Proteger credenciais e informações transmitidas.
- Evitar o uso de credenciais padrão.

## 3. Referências de segurança

As recomendações consideram os seguintes referenciais:

- OWASP IoT Security Testing Guide.
- NIST IR 8259A — recomendações de capacidades básicas de segurança para dispositivos IoT.
- ETSI EN 303 645 — requisitos de segurança para dispositivos IoT de consumo.
- MITRE EMB3D — modelo de ameaças e riscos para dispositivos embarcados.
- Documentação oficial de segurança do ESP-IDF, da Espressif.

## 4. Prioridades de implementação

| Prioridade | Medida |
|---|---|
| Alta | Restringir acesso às interfaces de depuração |
| Alta | Avaliar Secure Boot e Flash Encryption |
| Alta | Proteger futuras atualizações de firmware |
| Média | Revisar mensagens e informações da interface serial |
| Média | Implementar autenticação e comunicação protegida |
| Média | Estabelecer controle de versões e integridade do firmware |

## 5. Situação atual

As medidas descritas representam recomendações de hardening. Não foram implementadas ou testadas no protótipo atual do Wokwi.

## 6. Conclusão

A aplicação das medidas propostas poderá reduzir a exposição de informações, dificultar o acesso não autorizado ao firmware e melhorar a proteção das futuras comunicações do NexaSense.

A implementação deverá ser validada em hardware real antes de considerar o dispositivo preparado para produção.
