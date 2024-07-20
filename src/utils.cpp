#include <SD.h>
#include "utils.h"

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

void logData(int ldrCimaDireita, int ldrCimaEsquerda, int ldrBaixoDireita, int ldrBaixoEsquerda, int anguloHorizontalAtual, int anguloVerticalAtual) {
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.print("LDR Cima Direita: ");
        dataFile.println(ldrCimaDireita);
        dataFile.print("LDR Cima Esquerda: ");
        dataFile.println(ldrCimaEsquerda);
        dataFile.print("LDR Baixo Direita: ");
        dataFile.println(ldrBaixoDireita);
        dataFile.print("LDR Baixo Esquerda: ");
        dataFile.println(ldrBaixoEsquerda);
        dataFile.print("Ângulo Horizontal: ");
        dataFile.println(anguloHorizontalAtual);
        dataFile.print("Ângulo Vertical: ");
        dataFile.println(anguloVerticalAtual);
        dataFile.close();
    } else {
        Serial.println("Erro ao abrir o arquivo datalog.txt");
    }
}
