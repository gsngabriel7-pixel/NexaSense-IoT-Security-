# Avaliação de Riscos — NexaSense

## 1. Objetivo

Avaliar os riscos associados aos pontos de atenção identificados durante a análise inicial de segurança do protótipo NexaSense.

## 2. Metodologia

A avaliação considera dois critérios:

- **Probabilidade:** possibilidade de ocorrência do cenário identificado.
- **Impacto:** consequência potencial para a confidencialidade, integridade ou disponibilidade do dispositivo e de suas informações.

A classificação é qualitativa e preliminar.

## 3. Risco identificado

### RSK-001 — Exposição de informações pela interface serial

**Descrição:** o firmware transmite temperatura, umidade e mensagens de depuração pela interface serial.

**Ativo afetado:** informações coletadas pelo sensor DHT22.

**Condição necessária:** acesso físico à interface serial de um dispositivo real.

| Critério | Classificação |
|---|---|
| Probabilidade | Baixa |
| Impacto | Baixo a moderado |
| Prioridade | Baixa |

**Justificativa:** a exposição foi observada no Serial Monitor do Wokwi. Em um dispositivo físico, a possibilidade de observação dependeria da acessibilidade dos pinos e da interface serial.

## 4. Impactos potenciais

- Divulgação de informações ambientais.
- Exposição de mensagens internas de depuração.
- Possível obtenção de informações úteis para investigações posteriores, caso o firmware real transmita dados adicionais.

Não foi demonstrado acesso remoto, alteração de firmware ou comprometimento do dispositivo.

## 5. Recomendações

- Remover mensagens de depuração desnecessárias da versão de produção.
- Restringir fisicamente o acesso às interfaces de depuração.
- Evitar transmitir informações sensíveis pela serial.
- Avaliar mecanismos de proteção de UART e JTAG no hardware final.

## 6. Limitações

A classificação foi elaborada com base em um protótipo simulado. Não foram realizados testes físicos ou exploração de um dispositivo real.

Os demais pontos de atenção identificados ainda não possuem evidências suficientes para serem classificados como vulnerabilidades confirmadas.

## 7. Conclusão

O principal risco observado está relacionado à exposição de informações pela interface serial. A recomendação é restringir o acesso físico à interface e revisar as mensagens exibidas na versão de produção.
