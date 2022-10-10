#include <HCSR04.h> //Biblioteca do sensor de distância

//PINOS DOS LEDS
#define PIN_VERMELHO 2 
#define PIN_AMARELO  3
#define PIN_VERDE    4

//PINOS DO SENSOR DE DISTÂNCIA
#define PINO_SENSOR_RECEBE 11 //PINO ECHO DO SENSOR DE DISTÂNCIA QUE DETECTA A PRESENÇA DO OBJETO
#define PINO_SENSOR_ENVIA 12  //PINO TRIG DO SENSOR DE DISTÂNCIA QUE DISPARA ONDAS ULTRASSÔNICAS NO AMBIENTE 

#define ESPERA             1
#define ESPERA_VERMELHO 5000
#define ESPERA_AMARELO  2000
#define ESPERA_VERDE   10000

#define PRESENCA 0

byte sinalAtual = 0;
byte sinalProximo = 0;
unsigned int tempoInicio;
unsigned int tempoFim;

UltraSonicDistanceSensor distanceSensor(PINO_SENSOR_ENVIA, PINO_SENSOR_RECEBE);//Cria um objeto com os pinos do arduino

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_VERMELHO, OUTPUT);
  pinMode(PIN_AMARELO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PINO_SENSOR_RECEBE, INPUT);
  pinMode(PINO_SENSOR_ENVIA, OUTPUT);
  
  digitalWrite(PIN_VERMELHO, LOW);
  digitalWrite(PIN_AMARELO, LOW);
  digitalWrite(PIN_VERDE, LOW);

  tempoInicio = tempoFim = millis();
}

void loop()
{
  
  sinalProximo = semaforo(sinalAtual);
  if (sinalAtual == sinalProximo) 
    tempoFim = millis();
  else
    tempoInicio = tempoFim = millis();
  
  sinalAtual = sinalProximo;
  
  delay(ESPERA);
}

/*
 * Controla o estado do semáforo
 * @param id do sinal atual
 * @return id do próximo sinal
 */
byte semaforo(byte idSinal){
  byte _sinalProximo = idSinal;
  boolean sinal = verificaSemaforo(); // Variável que recebe a função verifica se o carro ultrapassou ou não.
  
  switch (idSinal){
    case 0: // Sinal vermelho
      digitalWrite(PIN_VERDE, LOW);
      digitalWrite(PIN_VERMELHO, HIGH);
      if (sinal == true){
        Serial.println("O carro ultrapassou o sinal vermelho ");
      }
      if ((tempoFim - tempoInicio) >= ESPERA_VERMELHO)
        _sinalProximo++;
      break;
    case 1: // Sinal amarelo
      digitalWrite(PIN_VERMELHO, LOW);
      digitalWrite(PIN_AMARELO, HIGH);
      if ((tempoFim - tempoInicio) >= ESPERA_AMARELO)
        _sinalProximo++;
      break;
    case 2: // Sinal verde
      digitalWrite(PIN_AMARELO, LOW);
      digitalWrite(PIN_VERDE, HIGH);
      if ((tempoFim - tempoInicio) >= ESPERA_VERDE)
        _sinalProximo = 0;
      break;
    default:
      break;
  }
  return _sinalProximo;  
}

boolean verificaSemaforo(){
  int distancia = 0;
  
  distancia = distanceSensor.measureDistanceCm();
  
  if(distancia >= PRESENCA){
    return true;
  }else {
  return false;
}}
