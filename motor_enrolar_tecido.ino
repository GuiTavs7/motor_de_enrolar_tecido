// -------------------------------------------------------------------------------------------------------------------------

const int botao_acionador = 8;  //CONFIGURA O PINO DIGITAL DO BOTÃO COMO 8       
  
const int rele_pin = 9;         //CONFIGURA O PINO DIGITAL DO RELÉ COMO 9        

const int led_pin = 13;         //CONFIGURA O PINO DIGITAL DO LED COMO 13

const int sensor_pin = A3;      //CONFIGURA O PINO ANALÓGICO DO SENSOR TCRT 5000 COMO 3

const int pot_pin = A4;         // CONFIGURA O PINO ANALÓGICO DO POTENCIÔMETRO

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

  digitalWrite(led_pin,LOW); // Reseta estado natural e inicial do led
  
  digitalWrite(rele_pin,LOW); // Reseta estado natural e inicial do relé

  int ler_potenciometro = analogRead(pot_pin);

  int luminosidade = analogRead(sensor_pin);

  Serial.println(luminosidade); 

  if (ler_potenciometro > 100){

    luminosidade = map(ler_potenciometro, 0, 1023, 800, 1020); // 0 POT - 800 SENSOR - ALTA LUMINOSIDADE | 1023 POT - 1010 SENSOR - BAIXA LUMINOSIDADE
  }

  // -------------------------------------------------------------------------------------------------------------------------

  int estado_botao_acionador = digitalRead(botao_acionador);

  if ((luminosidade > 1000) && (estado_botao_acionador == LOW)){ // Se o botão e sensor acionados:

    while((luminosidade > 1000) && (estado_botao_acionador == LOW)){ // Enquanto as duas condições são atendidas:

      luminosidade = analogRead(sensor_pin); // Verifica constantemente luminosidade via sensor

      estado_botao_acionador = digitalRead(botao_acionador); // Verifica constantemente estado do botão

      digitalWrite(led_pin,HIGH);
      
      digitalWrite(rele_pin,HIGH);
      
    } // Fim do loop while para cortar energia
    
  } // Fim do if

  // -------------------------------------------------------------------------------------------------------------------------
  
} // FIM DA FUNÇÃO PRINCIPAL - VOID LOOP
