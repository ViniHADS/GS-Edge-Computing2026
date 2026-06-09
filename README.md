# GS-Edge-Computing2026
FIAP_Class
# 🚀 SPACEAIR GUARDIAN

Projeto desenvolvido para a disciplina de **Edge Computing** do curso de **Engenharia de Software (FIAP)**.

## 👥 Integrantes

- Vinicius Araujo (RM 572666)
- Gabriel Donato (RM 572320)
- Jorge Meert (RM 572179)

---

# 📖 Sobre o Projeto

O **SPACEAIR GUARDIAN** é um sistema embarcado desenvolvido em Arduino para monitoramento da qualidade do ar e das condições ambientais em ambientes simulados terrestres e espaciais.

O sistema utiliza sensores para monitorar temperatura e qualidade do ar, fornecendo alertas visuais e sonoros quando os parâmetros definidos são ultrapassados.

Além disso, o projeto implementa tratamento de falhas dos sensores e armazenamento de eventos utilizando EEPROM, permitindo registrar ocorrências críticas para análise posterior.

---

# 🎯 Objetivo

Desenvolver uma solução de Edge Computing capaz de:

- Monitorar temperatura ambiente em tempo real.
- Monitorar níveis de gases e qualidade do ar.
- Operar em diferentes cenários ambientais.
- Alertar usuários sobre condições perigosas.
- Detectar falhas dos sensores.
- Exibir informações localmente sem necessidade de conexão com a nuvem.

---

# 🔧 Hardware Utilizado

| Componente | Quantidade |
|------------|------------|
| Arduino Uno R3 | 1 |
| Sensor TMP36 | 1 |
| Sensor MQ-2 | 1 |
| LCD 16x2 | 1 |
| Slide Switch | 1 |
| LED Verde | 1 |
| LED Amarelo | 1 |
| LED Vermelho | 1 |
| Buzzer Piezo | 1 |
| Resistores | Conforme necessário |

---

# 🛰️ Modos de Operação

O sistema possui dois modos de operação selecionados através de uma **Slide Switch**.

## 🌎 Modo Terra

Parâmetros utilizados para ambientes terrestres.

### Estado Seguro

- Temperatura entre 0°C e 30°C
- Gás abaixo de 40%

Indicador:

🟢 LED Verde

---

### Estado de Atenção

- Temperatura entre 30°C e 40°C
- Temperatura entre -10°C e 0°C
- Gás entre 40% e 55%

Indicador:

🟡 LED Amarelo

---

### Estado Crítico

- Temperatura acima de 40°C
- Temperatura abaixo de -10°C
- Gás acima de 55%

Indicadores:

🔴 LED Vermelho

🔊 Buzzer

---

## 🚀 Modo Espaço

Parâmetros mais rigorosos para simular uma estação espacial.

### Estado Seguro

- Temperatura entre 18°C e 25°C
- Gás abaixo de 40%

Indicador:

🟢 LED Verde

---

### Estado de Atenção

- Temperatura entre 25°C e 28°C
- Temperatura entre 15°C e 18°C
- Gás entre 40% e 50%

Indicador:

🟡 LED Amarelo

---

### Estado Crítico

- Temperatura acima de 28°C
- Temperatura abaixo de 15°C
- Gás acima de 50%

Indicadores:

🔴 LED Vermelho

🔊 Buzzer

---

# 📟 Interface com Usuário

O sistema exibe informações em um display LCD 16x2.

### Exemplo de Estado Seguro

```text
BASE SEGURA
T:24C G:35%
```

### Exemplo de Atenção

```text
TEMP ALTA
T:32C G:45%
```

### Exemplo de Estado Crítico

```text
AR CONTAM.
T:24C G:60%
```

### Troca de Modo

```text
MODO TERRA
CONFIGURANDO
```

ou

```text
MODO ESPACO
CONFIGURANDO
```

---

# ⚠️ Tratamento de Falhas

O sistema realiza validação dos sensores para identificar leituras fora dos limites esperados.

## TMP36

Faixa operacional esperada:

```text
0.10V até 1.75V
```

Caso a tensão fique fora dessa faixa:

```text
FALHA TMP36
```

---

## MQ-2

O sistema verifica leituras extremas do conversor ADC.

Exemplos:

```text
0
```

ou

```text
1023
```

Caso detectado:

```text
FALHA MQ2
```

---

# 🔌 Pinagem

## Sensores

| Componente | Pino |
|------------|------|
| TMP36 | A0 |
| MQ-2 | A1 |
| Slide Switch | 7 |

---

## LEDs

| LED | Pino |
|------|------|
| Verde | 2 |
| Amarelo | 3 |
| Vermelho | 4 |

---

## Buzzer

| Componente | Pino |
|------------|------|
| Buzzer | 5 |

---

## LCD 16x2

| LCD | Arduino |
|------|---------|
| RS | 13 |
| E | 12 |
| D4 | 11 |
| D5 | 10 |
| D6 | 9 |
| D7 | 8 |

---

# 🧠 Conceitos Aplicados

- Edge Computing
- Sistemas Embarcados
- Sensores Analógicos
- Arduino
- Tratamento de Falhas
- Monitoramento Ambiental
- Interface Homem-Máquina (HMI)
- Simulação no Tinkercad
- Tomada de decisão baseada em regras

---

# 📚 Disciplina

**Edge Computing**

Curso de **Engenharia de Software**

FIAP – Faculdade de Informática e Administração Paulista

---

# 🏛️ Instituição

FIAP – Faculdade de Informática e Administração Paulista

Ano: 2026

---

# 📄 Licença

Projeto desenvolvido exclusivamente para fins acadêmicos na disciplina de Edge Computing.
