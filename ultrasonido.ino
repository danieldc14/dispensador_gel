const int trig=9;
const int echo=8;
const int led=12;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(trig, LOW);
}

// the loop function runs over and over again forever
void loop() {
  
  long t; //timepo que demora en llegar el eco
  float d; //distancia en centimetros

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(trig, LOW);
  
  t = pulseIn(echo, HIGH); //obtenemos el ancho del pulso
  d = (t/2.0)/29.0;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  
  if(d>=10||d<=0)
  {
    digitalWrite(led, HIGH);
      Serial.println("apagado");

  //  delay(1000);
  }
  

 
  else
  {
     digitalWrite(led, LOW);
     Serial.println("encendido");
  //   delay(3000);
  }
    delay(2000);
}
