#include <Arduino.h>

// Teste do motor de hoverboard variando a tensão na esp

// -------------------------
// Configuração do Motor (Lado Direito)
// -------------------------
const int PINO_DAC = 25;  // Pino de controle de tensão (DAC1)
const int PINO_DIR = 32;  // Pino de direção do motor

void setup() {
  Serial.begin(115200);

  // Configura os pinos como saída
  pinMode(PINO_DAC, OUTPUT);
  pinMode(PINO_DIR, OUTPUT);

  // Trava a direção do motor como HIGH (Frente)
  digitalWrite(PINO_DIR, LOW);

  Serial.println("=======================================");
  Serial.println("Iniciando teste isolado do motor (DAC)");
  Serial.println("Faixa de operação: 97 a 104");
  Serial.println("=======================================");
  delay(2000);
}

void loop() {
  // Estágio 1: Arrancada / Velocidade Mínima
  Serial.println("Estágio: MINIMO | Valor DAC: 97 (~1.25V)");
  dacWrite(PINO_DAC, 97);
  delay(3000); // Mantém o motor girando assim por 3 segundos

  // Estágio 2: Velocidade Intermediária
  Serial.println("Estágio: MEDIO  | Valor DAC: 100 (~1.30V)");
  dacWrite(PINO_DAC, 100);
  delay(3000);

  // Estágio 3: Velocidade Máxima da sua faixa
  Serial.println("Estágio: MAXIMO | Valor DAC: 104 (~1.35V)");
  dacWrite(PINO_DAC, 104);
  delay(3000);

  // Estágio 4: Parada de segurança
  Serial.println("Estágio: PARADO | Valor DAC: 0 (0V)");
  dacWrite(PINO_DAC, 0);
  Serial.println("---------------------------------------");
  delay(3000);
}