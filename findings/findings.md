# Achados de Segurança — NexaSense

## Achado 01 — Exposição de informações pela interface serial

**Categoria:** Exposição de informações

**Componente:** Interface serial do ESP32

**Status:** Comportamento observado na simulação.

### Descrição

O firmware transmite informações de temperatura, umidade e mensagens de inicialização por meio da interface serial.

Não existe mecanismo de autenticação ou criptografia implementado para restringir a leitura dessas informações pela interface.

### Demonstração

Durante a simulação no Wokwi, foi possível visualizar diretamente no Serial Monitor:

- Mensagens de inicialização do dispositivo.
- Temperatura medida pelo sensor DHT22.
- Umidade medida pelo sensor DHT22.
- Mensagens de depuração.

### Impacto potencial

Em um dispositivo físico, caso os pinos ou a interface serial estejam acessíveis, uma pessoa com acesso físico poderia observar informações transmitidas pelo dispositivo.

A exposição de temperatura e umidade pode revelar informações sobre o ambiente monitorado.

### Limitações

A demonstração foi realizada no ambiente simulado Wokwi. Não foi realizado acesso não autorizado a uma placa física.

Não foi demonstrada exploração remota nem acesso a informações pela rede.

### Recomendações

- Remover mensagens de depuração desnecessárias da versão de produção.
- Evitar transmitir informações sensíveis pela interface serial.
- Restringir fisicamente o acesso às interfaces de depuração.
- Avaliar mecanismos de proteção das interfaces de depuração no hardware final.
