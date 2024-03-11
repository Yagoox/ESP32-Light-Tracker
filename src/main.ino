#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#include "config.h" 

Servo servoHorizontal;
Servo servoVertical;

BluetoothSerial SerialBT;

//      Posiçao incial dos servos
int anguloHorizontalAtual = 90;
int anguloVerticalAtual = 90; 

// Flag de controle do rastreamento da luz()
bool seguirLuz = false; 
bool modoBluetooth = false;
bool panico = false;

int valor_botao;
int cont = 0;

void setup() {

    //      Definiçao pinos servos e botao
    servoHorizontal.attach(SERVO_HORIZONTAL_PIN);
    servoVertical.attach(SERVO_VERTICAL_PIN);
    pinMode(BOTAO_PIN, INPUT);

    //      Set posiçao inicial servos
    servoHorizontal.write(10); 
    servoVertical.write(90); 

    //      Ativaçao Monitor serial/Mensagem Bluetooth
    Serial.begin(115200);
    SerialBT.begin("ESP32-ServoBot");

    //      Inicializaçao com a funçao rastrearLuzInicial()
    rastrearLuzInicial(); 
}

void loop(){
    
    valor_botao = digitalRead(BOTAO_PIN);

    int ldrCimaDireita = analogRead(LDR_CIMA_DIREITA);
    int ldrCimaEsquerda = analogRead(LDR_CIMA_ESQUERDA);
    int ldrBaixoDireita = analogRead(LDR_BAIXO_DIREITA);
    int ldrBaixoEsquerda = analogRead(LDR_BAIXO_ESQUERDA);

    //      Calculo da media dos pares ldr
    int avgtop = (ldrCimaEsquerda + ldrCimaDireita) / 2; //         LDRs superiores
    int avgbot = (ldrBaixoEsquerda + ldrBaixoDireita) / 2; //       LDRs inferiores
    int avgleft = (ldrCimaEsquerda + ldrBaixoEsquerda) / 2; //      LDRs esquerdos
    int avgright = (ldrCimaDireita + ldrBaixoDireita) / 2; //       LDRs direitos

    if (valor_botao == HIGH) {

        cont++;
    }
    if (cont == 0) {

        seguirLuz = true;
    }
    if (cont == 1) {

        seguirLuz = false;
        modoBluetooth = true;
        panico = false;
    }

    if (cont == 2) {

        seguirLuz = false;
        modoBluetooth = false;
        panico = true;
    }

    if (cont == 3) {

        cont = 0;
        esp_restart();
    }

    Serial.println(cont);

    if (modoBluetooth) {

        if (SerialBT.available()) {

        char command = SerialBT.read();
        if (command == '1') {

            moverServoVertical(anguloVerticalAtual - incrementoAngulo);
        } else if (command == '2') {

            moverServoVertical(anguloVerticalAtual + incrementoAngulo);
        } else if (command == '3') {

            moverServoHorizontal(anguloHorizontalAtual + incrementoAngulo);
        } else if (command == '4') {

            moverServoHorizontal(anguloHorizontalAtual - incrementoAngulo);
        }
        }
    }

    if (seguirLuz && !panico) {

        //      Movimento suave com base na media
        if (avgleft < referenciaLDR) {
        moverServoHorizontal(anguloHorizontalAtual - incrementoAngulo);
        } else if (avgright < referenciaLDR) {
        moverServoHorizontal(anguloHorizontalAtual + incrementoAngulo);
        }

        if (avgtop < referenciaLDR) {

        moverServoVertical(anguloVerticalAtual - incrementoAngulo);
        } else if (avgbot < referenciaLDR) {

        moverServoVertical(anguloVerticalAtual + incrementoAngulo);
        }
    } else if (panico) {

        servoHorizontal.write(94);
        servoVertical.write(118);
    }

    //      Impressao
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

  if (anguloDesejado < 0) {

    anguloDesejado = 0;
  } else if (anguloDesejado > 180) {

    anguloDesejado = 180;
  }

  while (anguloHorizontalAtual != anguloDesejado) {

    if (anguloDesejado < anguloHorizontalAtual) {

      anguloHorizontalAtual--;
    } else {

      anguloHorizontalAtual++;
    }

    servoHorizontal.write(anguloHorizontalAtual);
    delay(pausaMovimento);
  }
}

void moverServoVertical(int anguloDesejado) {

  if (anguloDesejado < 0) {

    anguloDesejado = 0;
  } else if (anguloDesejado > 180) {

    anguloDesejado = 180;
  }

  while (anguloVerticalAtual != anguloDesejado) {

    if (anguloDesejado < anguloVerticalAtual) {

      anguloVerticalAtual--;
    } else {
        
      anguloVerticalAtual++;
    }

    servoVertical.write(anguloVerticalAtual);
    delay(pausaMovimento);
  }
}