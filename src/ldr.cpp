#include <Arduino.h>
#include "ldr.h"
#include "config.h"

void calibrarLDRs() {
    int totalCimaDireita = 0, totalCimaEsquerda = 0, totalBaixoDireita = 0, totalBaixoEsquerda = 0;
    const int numLeituras = 100;

    for (int i = 0; i < numLeituras; i++) {
        totalCimaDireita += analogRead(LDR_CIMA_DIREITA);
        totalCimaEsquerda += analogRead(LDR_CIMA_ESQUERDA);
        totalBaixoDireita += analogRead(LDR_BAIXO_DIREITA);
        totalBaixoEsquerda += analogRead(LDR_BAIXO_ESQUERDA);
        delay(10);
    }

    int referenciaCimaDireita = totalCimaDireita / numLeituras;
    int referenciaCimaEsquerda = totalCimaEsquerda / numLeituras;
    int referenciaBaixoDireita = totalBaixoDireita / numLeituras;
    int referenciaBaixoEsquerda = totalBaixoEsquerda / numLeituras;

    Serial.print("Referência LDR Cima Direita: ");
    Serial.println(referenciaCimaDireita);
    Serial.print("Referência LDR Cima Esquerda: ");
    Serial.println(referenciaCimaEsquerda);
    Serial.print("Referência LDR Baixo Direita: ");
    Serial.println(referenciaBaixoDireita);
    Serial.print("Referência LDR Baixo Esquerda: ");
    Serial.println(referenciaBaixoEsquerda);
}
