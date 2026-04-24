#include <Arduino.h>

//Saida digital dos sensores
const int S1 = 23;
const int S2 = 22;
const int S3 = 21;
const int S4 = 19;
const int S5 = 18;

void setup() {
  Serial.begin(115200);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  Serial.println("Leitura DIGITAL dos sensores...");
}

void loop() {
  int v1 = digitalRead(S1);
  int v2 = digitalRead(S2);
  int v3 = digitalRead(S3);
  int v4 = digitalRead(S4);
  int v5 = digitalRead(S5);

  Serial.print("S1: "); Serial.print(v1);
  Serial.print(" | S2: "); Serial.print(v2);
  Serial.print(" | S3: "); Serial.print(v3);
  Serial.print(" | S4: "); Serial.print(v4);
  Serial.print(" | S5: "); Serial.println(v5);

  delay(200);
}