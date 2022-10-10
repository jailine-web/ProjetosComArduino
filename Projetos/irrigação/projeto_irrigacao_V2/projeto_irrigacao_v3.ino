#define PORTA_RELE  3
#define PORTA_SENSOR_UMIDADE A0
#define PORTA_SENSOR_NIVEL 5
#define DELAY 4000

#define MAX_SECO 800
#define MIN_SECO 400

void setup() {
  
  Serial.begin(9600);
  
  pinMode(PORTA_RELE, OUTPUT);
  pinMode(PORTA_SENSOR_UMIDADE, INPUT);
  pinMode (PORTA_SENSOR_NIVEL, INPUT_PULLUP);
  digitalWrite(PORTA_RELE, LOW);

}
void loop() {

 int sensor_umidade = 0;
 int sensor_nivel = 0 ;

  sensor_umidade = analogRead(PORTA_SENSOR_UMIDADE);
  sensor_nivel  = digitalRead(PORTA_SENSOR_NIVEL);
  
  Serial.println(sensor_umidade);
  
  
  if(sensor_umidade > MAX_SECO){
    if (sensor_nivel == LOW) {
       digitalWrite(PORTA_RELE, HIGH);
       Serial.println("Há água no reservatório e a bomba será ligada");
     } else {
        digitalWrite(PORTA_RELE, LOW);
        Serial.println("Não há água no reservatório, a bomba será desativada");
     }
  }
   else if (sensor_umidade < MIN_SECO){
      digitalWrite(PORTA_RELE, LOW);
      Serial.println("Bomba desligada");
  }
   
  delay(DELAY);
}
