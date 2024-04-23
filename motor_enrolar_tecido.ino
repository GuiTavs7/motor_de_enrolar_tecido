// -------------------------------------------------------------------------------------------------------------------------

const int botao_acionador = 8;  //CONFIGURA O PINO DIGITAL DO BOTÃO COMO 8       
  
const int rele_pin = 9;         //CONFIGURA O PINO DIGITAL DO RELÉ COMO 9        

const int led_pin = 13;         //CONFIGURA O PINO DIGITAL DO LED COMO 13

const int sensor_pin = A3;      //CONFIGURA O PINO ANALÓGICO DO SENSOR TCRT 5000 COMO 3

const int pot_pin = A4;         // CONFIGURA O PINO ANALÓGICO DO POTENCIÔMETRO

int luminosidade = 0;           // DECLARA E INICIALIZA VARIÁVEL PARA ARMAZENAR VALOR DO SENSOR COMO 0;

// -------------------------------------------------------------------------------------------------------------------------

void setup() {

  pinMode(rele_pin, OUTPUT);                // DEFINE PINO DO RELÉ COMO SAÍDA

  pinMode(led_pin, OUTPUT);                 // DEFINE PINO DO LED COMO SAÍDA

  pinMode(sensor_pin, INPUT);               // DEFINE O PINO DO SENSOR COMO ENTRADA

  pinMode(botao_acionador, INPUT_PULLUP);   // DEFINE O PINO DO BOTÃO DE ENROLAR TECIDO COM RESISTOR INTERNO

  Serial.begin(9600);                       // INICIALIZA COMUNICAÇÃO SERIAL COM UMA TAXA DE 9600 BAUD

}

// -------------------------------------------------------------------------------------------------------------------------

void loop() {

  int potenciometro = analogRead(pot_pin);

  luminosidade = analogRead(sensor_pin);

  Serial.println(luminosidade);

  int estado_botao_acionador = digitalRead(botao_acionador);

  if (potenciometro > 100){

    luminosidade = map(potenciometro, 0, 1023, 800, 1020); // 0 POT - 800 SENSOR - ALTA LUMINOSIDADE | 1023 POT - 1010 SENSOR - BAIXA LUMINOSIDADE
  }

  if ((luminosidade > 1010) && (estado_botao_acionador == LOW)){

    digitalWrite(led_pin,HIGH);
    digitalWrite(rele_pin,HIGH);
  }
  else{
    
    digitalWrite(led_pin,LOW);
    digitalWrite(rele_pin,LOW);
    
  }
  

}
