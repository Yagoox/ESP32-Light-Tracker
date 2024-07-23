#include <BluetoothSerial.h>
#include "bluetooth.h"
#include "servos.h"
#include "config.h"

extern BluetoothSerial SerialBT;
extern int anguloHorizontalAtual;
extern int anguloVerticalAtual;

void processarComandoBluetooth(char command) {
    switch (command) {
        case '1':
            moverServoVertical(anguloVerticalAtual - INCREMENTO_ANGULO);
            break;
        case '2':
            moverServoVertical(anguloVerticalAtual + INCREMENTO_ANGULO);
            break;
        case '3':
            moverServoHorizontal(anguloHorizontalAtual + INCREMENTO_ANGULO);
            break;
        case '4':
            moverServoHorizontal(anguloHorizontalAtual - INCREMENTO_ANGULO);
            break;
    }
}
