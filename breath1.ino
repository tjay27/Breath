#include <Adafruit_BMP085.h>
char PRESSURESHOW[4];// initializing a character of size 4 for showing the  result

char TEMPARATURESHOW[4];// initializing a character of size 4 for showing the temparature result

Adafruit_BMP085 bmp;
void setup(){
  //QnJlYXRoZQ== username
  //Y2hlY2ticmVhdGhl pass

  Serial.begin(9600);

                if (!bmp.begin())

                {

                                Serial.println("ERROR");///if there is an error in communication

                                while (1) {}

                }
  Serial.println("Connection Made");
  pinMode(LED_BUILTIN, OUTPUT);
  
}
int k=0;
void loop(){
   double temp=bmp.readTemperature();
   double pres=bmp.readPressure()*0.000987/100;//in atm
   Serial.println(temp);
   if(temp>36.30){
      Serial.println("DANGER DANGER");
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100); 
      if(k==0){
        //email trigger
        k++;
        }
    }
  
  } 
