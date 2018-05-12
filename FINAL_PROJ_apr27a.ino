// Joseph Nartey opey
#include <RTCZero.h>
/* Create an rtc object */
RTCZero rtc;

/* Change these values to set the current initial time */
const byte seconds = 0;
const byte minutes = 0;
const byte hours = 16;

/* Change these values to set the current initial date */
const byte day = 15;
const byte month = 6;
const byte year = 15;
unsigned int count=0;
int Hrs;
int Min;
int Sec;
int state=LOW;
int lastState=LOW;
int aray[4];
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  // put your setup code here, to run once:
  state=analogRead(A0);
  

  rtc.begin(); // initialize RTC

  // Set the time
  rtc.setHours(hours);
  rtc.setMinutes(minutes);
  rtc.setSeconds(seconds);

  // Set the date
  rtc.setDay(day);
  rtc.setMonth(month);
  rtc.setYear(year);

}

void loop() {
  int sensorValue1=analogRead(A0);
        if (state>40 && lastState<30){
          count++;
          aray[0]=count;
          
          
          //Serial.print(count);
             Min= rtc.getMinutes();
             //Serial.print(":");
             Sec=rtc.getSeconds();
             Hrs=rtc.getHours();
             aray[1]=Sec;
             aray[2]=Min;
             delay(1000);
          } 
            lastState=state;
            state=analogRead(A0);
          delay(1000);
          //Serial.print('x');
          //Serial.print(",");
          Serial.print(count);
          //Serial.print(",");
          //Serial.println(sensorValue1);
          //Serial.print(",");
          //Serial.println('x');
          //Serial.print(lastState);
          //Serial.print(",");
          //Serial.print(Hrs);
          //Serial.print(",");
          //Serial.print(Min);
          //Serial.print(",");
          //Serial.print(Sec);
          //Serial.print(",");
          //Serial.println('x');
            

        
           if (sensorValue1 >300){ 
              digitalWrite( 2,LOW);  
                               }
             else
             {
             digitalWrite(2,HIGH);
            //unsigned long Time= rtc.getSeconds();
            //unsigned long Min= rtc.getMinutes();
            // unsigned long Hour=rtc.getHours();
             
             //count++;
            //Serial.println(count);
            }


}
