# NexaSense — Avaliação de Segurança de um Dispositivo IoT

## 1. Sobre o projeto

Este projeto foi desenvolvido como parte da atividade acadêmica de Hardware Hacking da UniFECAF, com o objetivo de analisar aspectos de segurança de um dispositivo IoT.

O dispositivo utilizado como referência é o **NexaSense**, um sensor ambiental baseado em ESP32, projetado para realizar leituras de temperatura e umidade por meio de um sensor DHT22.

Como não foi utilizado um ESP32 físico, o protótipo foi desenvolvido e testado em ambiente de simulação utilizando o Wokwi.

## 2. Objetivos

- Desenvolver um protótipo funcional de dispositivo IoT.
- Identificar componentes e interfaces do sistema.
- Analisar o código-fonte do firmware.
- Mapear possíveis superfícies de ataque.
- Avaliar a exposição de informações pela interface serial.
- Identificar riscos e propor medidas de segurança.

## 3. Arquitetura do dispositivo

O protótipo é composto pelos seguintes elementos:

- **ESP32:** microcontrolador responsável pelo processamento.
- **DHT22:** sensor utilizado para obter temperatura e umidade.
- **GPIO 15:** pino utilizado para receber os dados do sensor.
- **Interface Serial:** utilizada para apresentar informações e mensagens de depuração.
- **Wokwi:** ambiente utilizado para simular o circuito.

O firmware realiza leituras periódicas do sensor e apresenta os resultados no monitor serial, utilizando comunicação a 115200 baud.

O diagrama da arquitetura está disponível em `architecture/architecture-diagram.md`.

## 4. Escopo e limitações

A análise foi realizada exclusivamente em um ambiente de simulação controlado.

**Não foram realizados testes em hardware físico.**

Por esse motivo, não foram confirmados:
- Acesso físico às interfaces UART e JTAG.
- Extração de firmware diretamente da memória Flash.
- Captura de tráfego Wi-Fi ou de rede.
- Funcionamento de mecanismos de atualização OTA.
- Exploração de vulnerabilidades em um dispositivo físico.

A conectividade Wi-Fi e os protocolos de rede não foram implementados nesta versão do protótipo.

## 5. Ferramentas utilizadas

- Wokwi — simulação do ESP32 e do circuito.
- Arduino C++ — desenvolvimento do firmware.
- DHTesp — biblioteca para leitura do sensor DHT22.
- GitHub — armazenamento e documentação do projeto.
- Windows PowerShell — cálculo do hash SHA-256 do código-fonte.

## 6. Estrutura do repositório

| Diretório/arquivo | Descrição |
|---|---|
| `architecture/` | Diagrama e documentação da arquitetura |
| `docs/` | Diário de desenvolvimento e relatório técnico |
| `evidence/` | Capturas de tela e evidências |
| `firmware/` | Código-fonte e análise do firmware |
| `hardware/` | Mapeamento das interfaces de hardware |
| `network/` | Análise da comunicação |
| `findings/` | Identificação e avaliação de riscos |
| `remediation/` | Recomendações de segurança |
| `README.md` | Apresentação geral do projeto |

## 7. Análise do firmware

O firmware foi desenvolvido em Arduino C++ e utiliza a biblioteca DHTesp para realizar a leitura do sensor DHT22.

As informações apresentadas incluem:
- Temperatura.
- Umidade.
- Mensagens de inicialização.
- Mensagens de depuração.

O código-fonte está disponível em `firmware/sketch.ino`.

O arquivo `firmware/hashes.txt` registra o SHA-256 do código-fonte `sketch.ino`. Esse hash não representa um firmware binário compilado.

## 8. Análise das interfaces de hardware

Foram documentados os seguintes pontos:

- GPIO 15: entrada de dados do sensor DHT22.
- Interface Serial: saída de informações e mensagens de depuração.
- UART e JTAG: interfaces consideradas na análise teórica, sem validação em hardware físico.

A documentação está em `hardware/interface-map.md`.

## 9. Análise de comunicação

Nesta versão, a comunicação observada ocorre pela interface serial.

Não foram implementados protocolos de rede como HTTP, HTTPS ou MQTT, nem comunicação Wi-Fi.

Como não houve tráfego de rede no protótipo, não foi realizada captura com Wireshark.

A análise completa está em `network/protocol-analysis.md`.

## 10. Resultados e riscos identificados

Foi documentada a seguinte exposição:

**F01 — Exposição de informações pela interface serial**

Durante a simulação, foi possível observar informações de temperatura, umidade e mensagens de depuração no monitor serial.

Em um dispositivo físico, caso essa interface esteja acessível sem restrições, informações internas poderão ser observadas por alguém com acesso à interface.

Essa condição foi demonstrada no ambiente simulado e não representa uma vulnerabilidade de acesso remoto confirmada.

A avaliação está documentada em `findings/`.

## 11. Recomendações de segurança

Entre as medidas propostas estão:

- Restringir o acesso físico às interfaces de depuração.
- Reduzir informações sensíveis exibidas na interface serial.
- Avaliar e proteger as interfaces UART e JTAG.
- Utilizar Secure Boot e Flash Encryption quando aplicáveis.
- Implementar autenticação e proteção das atualizações OTA.
- Utilizar mecanismos seguros de autenticação e criptografia caso a conectividade de rede seja implementada.

As recomendações completas estão em `remediation/hardening-plan.md`.

## 12. Evidências

As evidências do desenvolvimento e das análises estão armazenadas em `evidence/`, incluindo capturas do circuito, do código-fonte, da saída serial e das documentações técnicas.

## 13. Relatório técnico

O relatório completo está disponível em:

`docs/relatorio-tecnico.md`

## 14. Conclusão

O projeto permitiu desenvolver um protótipo de sensor ambiental com ESP32 e DHT22 em ambiente simulado, além de documentar aspectos relevantes de segurança de firmware, interfaces de hardware e comunicação.

A análise identificou a exposição de informações pela interface serial como uma condição que merece atenção em dispositivos IoT.

Os resultados devem ser interpretados considerando as limitações do ambiente Wokwi, uma vez que não foram realizados testes em hardware físico.

---

**Instituição:** UniFECAF  
**Disciplina:** Hardware Hacking  
**Projeto:** Do Protótipo ao Produto Seguro — Avaliação de Segurança de um Dispositivo IoT
