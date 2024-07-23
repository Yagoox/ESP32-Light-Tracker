#include <Arduino.h>
#include <ESP32Servo.h>
#include <BluetoothSerial.h> // Inclusão da biblioteca BluetoothSerial
#include "config.h"
#include "servos.h"
#include "bluetooth.h"
#include "ldr.h"
#include "utils.h"

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
    Serial.begin(115200);
    Serial.println("Setup iniciado");

    // Configuração dos pinos dos servos e botão
    servoHorizontal.attach(SERVO_HORIZONTAL_PIN);
    servoVertical.attach(SERVO_VERTICAL_PIN);
    pinMode(BOTAO_PIN, INPUT);

    // Definição da posição inicial dos servos
    servoHorizontal.write(10);
    servoVertical.write(90);

    // Ativação do monitor serial e Bluetooth
    SerialBT.begin("ESP32-ServoBot");

    // Inicialização com a função rastrearLuzInicial
    rastrearLuzInicial();
    Serial.println("Setup completo");
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
