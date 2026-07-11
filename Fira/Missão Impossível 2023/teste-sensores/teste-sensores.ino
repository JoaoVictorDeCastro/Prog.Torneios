#include <Servo.h>

const int pinoSeguidorEsq = 1; 
const int pinoSeguidorDir = 2; 
float leituraSeguidorEsq;
float leituraSeguidorDir;

#define IN1   8
#define IN2   9
#define SERVO 5

Servo s; // Variável Servo
int pos; // Posição Servo

void setup(){
  pinMode(pinoSeguidorEsq, INPUT_PULLUP);
  pinMode (pinoSeguidorDir, INPUT_PULLUP);
  // Inicializa os pinos do motor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  Serial.begin(9600);
  s.attach(SERVO);
  s.write(0); // Inicia motor posição zero
}

void loop(){
  leituraSeguidorEsq = digitalRead(pinoSeguidorEsq);
  leituraSeguidorDir = digitalRead(pinoSeguidorDir);
  Serial.println("Leitura 1");
  Serial.println(leituraSeguidorEsq);
  Serial.println("Leitura 2");
  Serial.println(leituraSeguidorDir);
  delay(1000);
   if (leituraSeguidorEsq == 0 && leituraSeguidorDir == 1) {
      //Liga o motor da esquerda e desliga o da direita.
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("Leitura 1");
      Serial.println(leituraSeguidorEsq);
      Serial.println("Leitura 2");
      Serial.println(leituraSeguidorDir);
    } 
    if (leituraSeguidorEsq == 1 && leituraSeguidorDir == 0) {
      //Liga o motor da direita e desliga o da esquerda.
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("Leitura 1");
      Serial.println(leituraSeguidorEsq);
      Serial.println("Leitura 2");
      Serial.println(leituraSeguidorDir);
    } 
    if (leituraSeguidorEsq == 1 && leituraSeguidorDir == 1) {
      //Liga o motor ambos os motores.
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      Serial.println("Leitura 1");
      Serial.println(leituraSeguidorEsq);
      Serial.println("Leitura 2");
      Serial.println(leituraSeguidorDir);
    } 
        if (leituraSeguidorEsq == 0 && leituraSeguidorDir == 0) {
      //Liga o motor ambos os motores.
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      Serial.println("Leitura 1");
      Serial.println(leituraSeguidorEsq);
      Serial.println("Leitura 2");
      Serial.println(leituraSeguidorDir);
    } 
}
