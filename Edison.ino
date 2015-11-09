  // Grove Buzzer connect to D4
  //Light sensor A0
  //Temperature A1
  //Flame D8
  //Suelo A2
//Tonos.
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};



//Variables de los puertos
const int pinTemp = A0;
const int B = 3975;
int flama=8;
int suelo=A1;
const int pinLight = A2;
int Buzzer = 4; 

//Funcion de flama
boolean isFlameDetected()
  {
     if(digitalRead(8))
    	return false;
      else return true;
   }



void setup() {
   Serial.begin(9600);
   pinMode(flama, INPUT);
   pinMode(Buzzer, OUTPUT);
   pinMode(2, OUTPUT);
}

void loop() {
  
    //Recopilacion de datos
    
    // Temperatura
    int val = analogRead(pinTemp);
    float resistance = (float)(1023-val)*10000/val;
    float temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;
     //Suelo
     int valor_suelo = analogRead(suelo);
  
  
    //Acciones
    //Suelo
    Serial.print("Lectura de Humedad: ");
    Serial.println( valor_suelo ); 
   
    //luz
    int sensorValue;
    long  sum=0;
    for(int i=0;i<1024;i++)
     {  
        sensorValue=analogRead(A0);
        sum=sensorValue+sum;
        delay(2);
     }   
     sum = sum >> 10;
     Serial.print("The voltage value:");
     Serial.print(sum*4980.0/1023.0);
     Serial.println("mV");
          
    //Temperatura
    Serial.println(temperature);
    
    //Flama
    if(isFlameDetected())
    {
       Serial.println("Me quemo");
      
          tone(Buzzer, 1);
        
      
   
    }
    else
    {
      Serial.println("No me quemo");
       digitalWrite(2, LOW);
       noTone(Buzzer); 
    }
    
    delay(1000);

}
