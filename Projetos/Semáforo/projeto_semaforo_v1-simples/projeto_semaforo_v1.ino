#define VERMELHO 8
#define AMARELO 9
#define VERDE 10

#define DELAY 3000

void setup()
{
  pinMode(VERMELHO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop()
{
  digitalWrite(VERMELHO, HIGH);
  delay(DELAY); // Espera por 3000 milisegundos
  digitalWrite(VERMELHO,LOW);
  
  digitalWrite(AMARELO, HIGH);
  delay(DELAY); 
  digitalWrite(AMARELO, LOW);
   
  digitalWrite(VERDE, HIGH);
  delay(DELAY); 
  digitalWrite(VERDE, LOW);
  
}
