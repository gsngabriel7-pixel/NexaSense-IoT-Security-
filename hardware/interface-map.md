# Mapeamento da Superfície de Ataque — NexaSense

## 1. Objetivo

Identificar as interfaces e os componentes que podem representar pontos de exposição à segurança do dispositivo NexaSense.

## 2. Interfaces identificadas

### GPIO15
Utilizado para receber os dados enviados pelo sensor DHT22.

**Situação:** funcional e validado na simulação.

**Ponto de atenção:** investigar a possibilidade de manipulação dos sinais de entrada em um dispositivo físico.

### Interface serial
Utilizada para exibir mensagens de inicialização, temperatura, umidade e informações de depuração.

**Situação:** comunicação serial observada no Wokwi.

**Ponto de atenção:** verificar se informações sensíveis poderiam ser expostas por uma interface serial acessível fisicamente.

### UART
Interface de comunicação serial que poderá ser utilizada para depuração e interação com o ESP32 físico.

**Situação:** não testada em hardware real.

**Ponto de atenção:** investigar a existência de acesso não autorizado por meio dessa interface.

### JTAG
Interface de depuração de hardware.

**Situação:** não verificada.

**Ponto de atenção:** investigar se a interface está habilitada e se existem mecanismos de proteção contra acesso indevido.

## 3. Superfícies ainda não implementadas ou verificadas

### Wi-Fi
O firmware atual não possui configuração de conectividade sem fio.

**Situação:** não implementado no protótipo atual.

### Memória flash
A memória física do ESP32 não foi inspecionada.

**Situação:** não analisada.

### Atualização OTA
O firmware atual não possui mecanismo de atualização remota.

**Situação:** não implementado.

## 4. Resumo dos pontos de investigação

- Exposição de informações pela interface serial.
- Segurança das interfaces de depuração UART e JTAG.
- Possibilidade de manipulação das entradas GPIO.
- Proteção do firmware armazenado na memória flash.
- Segurança de futuras implementações de conectividade Wi-Fi.
- Autenticidade e integridade de futuras atualizações de firmware.

## 5. Limitações

O mapeamento foi elaborado com base no firmware e no circuito simulado no Wokwi.

Não foram realizados testes físicos de UART, JTAG, memória flash ou conectividade Wi-Fi.

Os pontos não verificados representam itens para investigação futura, não vulnerabilidades confirmadas.
