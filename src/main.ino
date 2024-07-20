#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#include "config.h"

// Definição de objetos para os servos e Bluetooth
Servo servoHorizontal;
Servo servoVertical;
BluetoothSerial SerialBT;

// Posição inicial dos servos
int anguloHorizontalAtual = 90;
int anguloVerticalAtual = 90;

// Flags de controle
bool seguirLuz = false;
bool modoBluetooth = false;
bool panico = false;

// Variáveis de controle
int valor_botao;
int cont = 0;

void setup() {
    // Configuração dos pinos dos servos e botão
    servoHorizontal.attach(SERVO_HORIZONTAL_PIN);
    servoVertical.attach(SERVO_VERTICAL_PIN);
    pinMode(BOTAO_PIN, INPUT);

    // Definição da posição inicial dos servos
    servoHorizontal.write(10);
    servoVertical.write(90);

    // Ativação do monitor serial e Bluetooth
    Serial.begin(115200);
    SerialBT.begin("ESP32-ServoBot");

    // Inicialização com a função rastrearLuzInicial
    rastrearLuzInicial();
}

void loop() {
    valor_botao = digitalRead(BOTAO_PIN);

    int ldrCimaDireita = analogRead(LDR_CIMA_DIREITA);
    int ldrCimaEsquerda = analogRead(LDR_CIMA_ESQUERDA);
    int ldrBaixoDireita = analogRead(LDR_BAIXO_DIREITA);
    int ldrBaixoEsquerda = analogRead(LDR_BAIXO_ESQUERDA);

    // Cálculo da média dos pares de LDRs
    int avgtop = (ldrCimaEsquerda + ldrCimaDireita) / 2;
    int avgbot = (ldrBaixoEsquerda + ldrBaixoDireita) / 2;
    int avgleft = (ldrCimaEsquerda + ldrBaixoEsquerda) / 2;
    int avgright = (ldrCimaDireita + ldrBaixoDireita) / 2;

    // Controle do botão e dos modos de operação
    if (valor_botao == HIGH) {
        cont++;
    }
    switch (cont) {
        case 0:
            seguirLuz = true;
            break;
        case 1:
            seguirLuz = false;
            modoBluetooth = true;
            panico = false;
            break;
        case 2:
            seguirLuz = false;
            modoBluetooth = false;
            panico = true;
            break;
        case 3:
            cont = 0;
            esp_restart();
            break;
    }

    // Controle via Bluetooth
    if (modoBluetooth) {
        if (SerialBT.available()) {
            char command = SerialBT.read();
            processarComandoBluetooth(command);
        }
    }

    // Rastreamento da luz
    if (seguirLuz && !panico) {
        rastrearLuz(avgtop, avgbot, avgleft, avgright);
    } else if (panico) {
        estadoPanico();
    }

    // Impressão dos valores no monitor serial
    imprimirValores(ldrCimaDireita, ldrCimaEsquerda, ldrBaixoDireita, ldrBaixoEsquerda);

    delay(100);
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
