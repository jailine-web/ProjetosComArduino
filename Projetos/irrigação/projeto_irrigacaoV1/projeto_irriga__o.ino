#define PORTA_RELE  3
#define PORTA_SENSOR_UMIDADE A0
#define DELAY 3000

#define MAX_SECO 800
#define MIN_SECO 400

void setup() {
  
  Serial.begin(9600);
 
  pinMode(PORTA_RELE, OUTPUT);
  pinMode(SENSOR_UMIDADE, INPUT);
  digitalWrite(PORTA_RELE, LOW);
}

void loop() {
  
  int sensor_umidade = 0;

  sensor_umidade = analogRead(PORTA_SENSOR_UMIDADE);

  Serial.println(sensor_umidade);
  if(sensor_umidade > MAX_SECO){
    digitalWrite(PORTA_RELE, HIGH);
      Serial.println("Bomba ligada");
  } 
  else if (sensor_umidade < MIN_SECO){
      digitalWrite(PORTA_RELE, LOW);
      Serial.println("Bomba desligada");
  }
   
  delay(DELAY);
}
  }
