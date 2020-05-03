
# define PinTrig 16
# define PinEcho 5
# define Rele 4



void setup()
   {  Serial.begin(9600);
      delay(1500);

      pinMode(Rele, OUTPUT);      
      digitalWrite(Rele, LOW);


      // Ponemos el pin Trig en modo salida
      pinMode(PinTrig, OUTPUT);
      // Ponemos el pin Echo en modo entrada
      pinMode(PinEcho, INPUT);
  
   }
//La única novedad es la instrucción que inicia el servidor. En el loop creamos el cliente y comprobamos si hay algo  disponible:


void loop() 
{
     int i;
      float distancias[10], sum=0, promedio=0;
      for (int i=0; i<10; i++)
        distancias[i]=0;

      for (int i=0; i<10; i++)
      {
      digitalWrite(PinTrig, LOW);
      delayMicroseconds(2);
      digitalWrite(PinTrig, HIGH);
      delayMicroseconds(10);
  
      float tiempo = pulseIn(PinEcho, HIGH);
      float distancia = (tiempo/2)/29.1;
      //distancia = 340m/s*tiempo;
     
      distancias[i]=distancia;
      }

      for (int i=0; i<10; i++)
        sum=sum + distancias[i];

      promedio= sum/i;

      
      Serial.print(promedio);
      Serial.print("cm");
      Serial.println();

      
      if ( promedio > 10)
      {
        digitalWrite(Rele, HIGH);
        Serial.println("Prender Motor");
       }
       else
            {
               digitalWrite(Rele, LOW);
               Serial.println("apagar Motor");
              
              }     
      delay(2000);

}
