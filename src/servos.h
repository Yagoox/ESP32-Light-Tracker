#ifndef SERVOS_H
#define SERVOS_H

void moverServoHorizontal(int anguloDesejado);
void moverServoVertical(int anguloDesejado);
void rastrearLuzInicial();
void rastrearLuz(int avgtop, int avgbot, int avgleft, int avgright);
void estadoPanico();

#endif // SERVOS_H
