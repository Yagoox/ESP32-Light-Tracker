#include <Arduino.h>
#include "utils.h"

extern int anguloHorizontalAtual;
extern int anguloVerticalAtual;
extern int cont;

void imprimirValores(int ldrCimaDireita, int ldrCimaEsquerda, int ldrBaixoDireita, int ldrBaixoEsquerda) {
    Serial.print("LDR Cima Direita: ");
    Serial.println(ldrCimaDireita);
    Serial.print("LDR Cima Esquerda: ");
    Serial.println(ldrCimaEsquerda);
    Serial.print("LDR Baixo Direita: ");
    Serial.println(ldrBaixoDireita);
    Serial.print("LDR Baixo Esquerda: ");
    Serial.println(ldrBaixoEsquerda);
    Serial.print("Ângulo Horizontal: ");
    Serial.println(anguloHorizontalAtual);
    Serial.print("Ângulo Vertical: ");
    Serial.println(anguloVerticalAtual);
    Serial.print("Cont: ");
    Serial.println(cont);
}
