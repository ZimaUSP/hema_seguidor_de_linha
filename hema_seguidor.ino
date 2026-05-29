#include <Arduino.h>

// -------------------------
// Sensores (DIGITAIS)
// -------------------------
const int S1 = 23;
const int S2 = 22;
const int S3 = 21;
const int S4 = 19;
const int S5 = 18;

// -------------------------
// Motores (ESP32 DAC - Tensão Contínua)
// -------------------------
const int PWM_ESQ = 26; // Canal DAC2 (Tensão pura) 
const int DIR_ESQ = 33;

const int PWM_DIR = 25; // Canal DAC1 (Tensão pura)
const int DIR_DIR = 32;

// -------------------------
// Controle
// -------------------------
float Kp = 1.0;
int velocidade_base = 104; // 1.25V (Ponto onde o motor começa a girar)
float ultimo_erro = 0;

// --------------------------------------------------------------
// Função para ajustar velocidade dos motores
// --------------------------------------------------------------
void setMotores(int vel_esq, int vel_dir) {
  
  // Define sentido (frente)
  digitalWrite(DIR_ESQ, HIGH);
  digitalWrite(DIR_DIR, HIGH);

  // Garante a faixa limite: Máximo 110 solicitado
  vel_esq = constrain(vel_esq, 0, 110);
  vel_dir = constrain(vel_dir, 0, 110);

  // Saída de Tensão Analógica Pura (DAC)
  dacWrite(PWM_ESQ, vel_esq);
  dacWrite(PWM_DIR, vel_dir);
}

// --------------------------------------------------------------
// SETUP
// --------------------------------------------------------------
void setup() {
  Serial.begin(115200);

  // Sensores
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  // Motores
  pinMode(DIR_ESQ, OUTPUT);
  pinMode(DIR_DIR, OUTPUT);
  pinMode(PWM_ESQ, OUTPUT);
  pinMode(PWM_DIR, OUTPUT);

  // --- SEQUÊNCIA DE INICIALIZAÇÃO PARA O DRIVER DE BIKE ---
  Serial.println("Iniciando rotina de destravamento do driver direito...");
  
  // 1. Medida de segurança: Garante acelerador no ZERO ao ligar
  dacWrite(PWM_ESQ, 0);
  dacWrite(PWM_DIR, 0);
  delay(200);

  // 2. Inverte a direção (LOW) e dá um pulso mínimo para o driver registrar
  digitalWrite(DIR_DIR, LOW);
  dacWrite(PWM_DIR, 0);
  digitalWrite(DIR_ESQ, LOW);
  dacWrite(PWM_ESQ, 0);
  delay(200); // Mantém invertido por meio segundo

  // 3. Corta a aceleração, volta para frente (HIGH) e aguarda estabilizar
  delay(200); // Pequena pausa com o motor desligado
  digitalWrite(DIR_DIR, HIGH);
  digitalWrite(DIR_ESQ, HIGH);
  delay(500); // Tempo para o driver processar a nova direção
  // --------------------------------------------------------

  Serial.println("Robô iniciando com controle por Tensão Pura (DAC)...");
}

// --------------------------------------------------------------
// LOOP PRINCIPAL
// --------------------------------------------------------------
void loop() {

  int v1 = digitalRead(S1);
  int v2 = digitalRead(S2);
  int v3 = digitalRead(S3);
  int v4 = digitalRead(S4);
  int v5 = digitalRead(S5);

  // Montar padrão binário
  int leitura = (v1<<4) | (v2<<3) | (v3<<2) | (v4<<1) | (v5);

  float erro = 0;
  bool leitura_normal = false;

  // 1) Linha perdida
  if(leitura == 0b00000){
      erro = ultimo_erro;
      Serial.println("Linha perdida — procurando...");
  }

  // 2) Leituras normais
  else if(
      leitura == 0b00001 || leitura == 0b00010 || leitura == 0b00011 ||
      leitura == 0b00100 || leitura == 0b00110 || leitura == 0b00111 ||
      leitura == 0b01000 || leitura == 0b01100 || leitura == 0b01110 ||
      leitura == 0b10000 || leitura == 0b11000 || leitura == 0b11100
  ){
      leitura_normal = true;

      int pesos[5] = {-1, -1, 0, +1, +1};
      int sensores[5] = {v1, v2, v3, v4, v5};

      float soma = 0;
      float ativos = 0;

      for(int i = 0; i < 5; i++){
          if(sensores[i] == 1){
              soma += pesos[i];
              ativos++;
          }
      }

      if(ativos > 0){
        erro = soma / ativos;
        ultimo_erro = erro;
      }
  }

  // 3) Leituras especiais
  else {
      Serial.println("Leitura especial — reduzindo velocidade");
      erro = ultimo_erro * 0.5;
  }

  // Controle proporcional
  float correcao = Kp * erro;

  int vel_esq = velocidade_base + correcao;
  int vel_dir = velocidade_base - correcao;

  // Aplica nos motores
  setMotores(vel_esq, vel_dir);

  // Debug
  Serial.print("Erro=");
  Serial.print(erro);
  Serial.print(" | VE=");
  Serial.print(vel_esq);
  Serial.print(" | VD=");
  Serial.println(vel_dir);

  delay(100);
}