#include <Arduino.h>

// Pinos ADC dos sensores
const int S1 = 32;
const int S2 = 33;
const int S3 = 34;
const int S4 = 35;
const int S5 = 36;  // VP

void setup() {
  Serial.begin(115200);

  // Configura como entrada
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  Serial.println("Leitura dos 5 sensores TCRT5000 iniciada...");
}

void loop() {
  int v1 = analogRead(S1);
  int v2 = analogRead(S2);
  int v3 = analogRead(S3);
  int v4 = analogRead(S4);
  int v5 = analogRead(S5);

  Serial.print("S1: "); Serial.print(v1);
  Serial.print(" | S2: "); Serial.print(v2);
  Serial.print(" | S3: "); Serial.print(v3);
  Serial.print(" | S4: "); Serial.print(v4);
  Serial.print(" | S5: "); Serial.println(v5);

  delay(200);
}