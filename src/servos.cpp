#include <Arduino.h>
#include <ESP32Servo.h>
#include "config.h"
#include "servos.h"

extern Servo servoHorizontal;
extern Servo servoVertical;
extern int anguloHorizontalAtual;
extern int anguloVerticalAtual;
extern bool seguirLuz;

void moverServoHorizontal(int anguloDesejado) {
    anguloDesejado = constrain(anguloDesejado, 0, 180);
    while (anguloHorizontalAtual != anguloDesejado) {
        anguloHorizontalAtual += (anguloDesejado < anguloHorizontalAtual) ? -1 : 1;
        servoHorizontal.write(anguloHorizontalAtual);
        delay(PAUSA_MOVIMENTO);
    }
}

void moverServoVertical(int anguloDesejado) {
    anguloDesejado = constrain(anguloDesejado, 0, 180);
    while (anguloVerticalAtual != anguloDesejado) {
        anguloVerticalAtual += (anguloDesejado < anguloVerticalAtual) ? -1 : 1;
        servoVertical.write(anguloVerticalAtual);
        delay(PAUSA_MOVIMENTO);
    }
}

void rastrearLuzInicial() {
    int maxLDRValue = 0;
    int maxServoAngle = 0;

    for (int angle = 10; angle <= 170; angle += 5) {
        servoHorizontal.write(angle);
        delay(200);
        int ldrValue = analogRead(LDR_CIMA_DIREITA);

        if (ldrValue > maxLDRValue) {
            maxLDRValue = ldrValue;
            maxServoAngle = angle;
        }
    }

    servoHorizontal.write(maxServoAngle);
    delay(500);

    seguirLuz = true;
}

void rastrearLuz(int avgtop, int avgbot, int avgleft, int avgright) {
    if (avgleft < REFERENCIA_LDR) {
        moverServoHorizontal(anguloHorizontalAtual - INCREMENTO_ANGULO);
    } else if (avgright < REFERENCIA_LDR) {
        moverServoHorizontal(anguloHorizontalAtual + INCREMENTO_ANGULO);
    }

    if (avgtop < REFERENCIA_LDR) {
        moverServoVertical(anguloVerticalAtual - INCREMENTO_ANGULO);
    } else if (avgbot < REFERENCIA_LDR) {
        moverServoVertical(anguloVerticalAtual + INCREMENTO_ANGULO);
    }
}

void estadoPanico() {
    servoHorizontal.write(94);
    servoVertical.write(118);
}
