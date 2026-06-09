// ===============================
// SPACEAIR GUARDIAN
// Monitoramento de Qualidade do Ar
// ===============================
#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Sensores
const int tempPin = A0;
const int gasPin  = A1;
const int switchPin = 7;

// LEDs
const int ledVerde    = 2;
const int ledAmarelo  = 3;
const int ledVermelho = 4;

// Buzzer
const int buzzer = 5;

// Memória 
bool modoAnterior = LOW;

void setup()
{
  Serial.begin(9600);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  pinMode(switchPin, INPUT);
  
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);

  // Tela inicial
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SPACEAIR");
  lcd.setCursor(0, 1);
  lcd.print("GUARDIAN");

  delay(2500);

  lcd.clear();
}

void loop()
{
  // ======================
  // Leitura TMP36
  // ======================

  int leituraTemp = analogRead(tempPin);

  float tensao = leituraTemp * 5.0;
  tensao /= 1024.0;

  float temperatura = (tensao - 0.5) * 100.0;

  // ======================
  // Leitura MQ-2
  // ======================

  int gas = analogRead(gasPin);
  int gasPercent = map(gas, 0, 1023, 0, 100);
  
  // ======================
  // Leitura da Slide Switch
  // ======================
  
  bool modoEspaco = digitalRead(switchPin) == HIGH;

  if (modoEspaco != modoAnterior)
  {
    lcd.clear();
    lcd.setCursor(0, 0);

    if (modoEspaco)
    {
      lcd.print("MODO ESPACO");
      Serial.println("Modo ESPACO selecionado");
    }
    else
    {
      lcd.print("MODO TERRA");
      Serial.println("Modo TERRA selecionado");
    }

    lcd.setCursor(0, 1);
    lcd.print("CONFIGURANDO");

    modoAnterior = modoEspaco;
    delay(1200);
    return;
  }
  
  // ======================
  // Serial Monitor
  // ======================

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" C");

  Serial.print(" | %Gas: ");
  Serial.println(gasPercent);

  Serial.print(" | Modo: ");
  Serial.println(modoEspaco ? "ESPACO" : "TERRA");
    
  // ======================
  // ESTADO CRITICO
  // ======================

  if (
    (!modoEspaco && (temperatura >= 40 || temperatura < -10 || gasPercent >= 55))
    ||
    (modoEspaco && (temperatura >= 28 || temperatura < 15 || gasPercent >= 50))
   )
  {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);

    lcd.clear();

    lcd.setCursor(0, 0);

    if (!modoEspaco)
    {
      if (temperatura < -10)
      {
        lcd.print("ALERTA FRIO");
      }
      else if (temperatura >= 40)
      {
        lcd.print("ALERTA CALOR");
      }
      else
      {
        lcd.print("AR CONTAM.");
      }
    }
    else
    {
      if (temperatura < 15)
      {
        lcd.print("ALERTA FRIO");
      }
      else if (temperatura >= 28)
      {
        lcd.print("ALERTA CALOR");
      }
      else
      {
        lcd.print("AR CONTAM.");
      }
    }

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print((int)temperatura);
    lcd.print("C G:");
    lcd.print(gasPercent);
    lcd.print("%");

    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1200);
    delay(200);

    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
    delay(100);

    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1200);
    delay(200);

    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
    delay(500);
  }

  // ======================
  // ESTADO ATENCAO
  // ======================
  
  else if (
    (!modoEspaco && (
      (temperatura >= 30 && temperatura < 40) ||
      (temperatura >= -10 && temperatura < 0) ||
      (gasPercent >= 40 && gasPercent < 55)
    ))
    ||
    (modoEspaco && (
      (temperatura >= 25 && temperatura < 28) ||
      (temperatura >= 15 && temperatura < 18) ||
      (gasPercent >= 40 && gasPercent < 50)
    ))
  )
  {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);

    noTone(buzzer);

    lcd.clear();

    lcd.setCursor(0, 0);

    if (!modoEspaco)
    {
      if (temperatura >= 30)
      {
        lcd.print("TEMP ALTA");
      }
      else if (temperatura < 0)
      {
        lcd.print("TEMP BAIXA");
      }
      else
      {
        lcd.print("ATENCAO GAS");
      }
    }
    else
    {
      if (temperatura >= 25)
      {
        lcd.print("TEMP ALTA");
      }
      else if (temperatura < 18)
      {
        lcd.print("TEMP BAIXA");
      }
      else
      {
        lcd.print("ATENCAO GAS");
      }
    }

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print((int)temperatura);
    lcd.print("C G:");
    lcd.print(gasPercent);
    lcd.print("%");

    delay(1000);
  }

  // ======================
  // ESTADO SEGURO
  // ======================

  else
  {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);

    noTone(buzzer);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BASE SEGURA");

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print((int)temperatura);
    lcd.print("C G:");
    lcd.print(gasPercent);
    lcd.print("%");

    delay(1000);
  }
}