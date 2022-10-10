
//PINOS DOS LEDS
#define PIN_VERMELHO 2 
#define PIN_AMARELO  3
#define PIN_VERDE    4

#define ESPERA             1
#define ESPERA_VERMELHO 5000
#define ESPERA_AMARELO  2000
#define ESPERA_VERDE   10000

byte sinalAtual = 0;
byte sinalProximo = 0;
unsigned int tempoInicio;
unsigned int tempoFim;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_VERMELHO, OUTPUT);
  pinMode(PIN_AMARELO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  
  digitalWrite(PIN_VERMELHO, LOW);
  digitalWrite(PIN_AMARELO, LOW);
  digitalWrite(PIN_VERDE, LOW);

  tempoInicio = tempoFim = millis();//
}

void loop()
{
  
  sinalProximo = semaforo(sinalAtual);
  if (sinalAtual == sinalProximo) 
    tempoFim = millis();
  else
    tempoInicio = tempoFim = millis();//
  
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
  
  
  switch (idSinal){
    case 0: // Sinal vermelho
      digitalWrite(PIN_VERDE, LOW);
      digitalWrite(PIN_VERMELHO, HIGH);
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
