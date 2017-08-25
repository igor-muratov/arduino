#include <Wire.h>
#include <SeeedOLED.h>



#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
 
void setup(){
 Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  Serial1.begin(57600);   
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column

int num = DHT.temperature;
char snum[5];
itoa(num, snum, 10);
  SeeedOled.putString("temp = "); //Print the String
  SeeedOled.setTextXY(0,8);
  SeeedOled.putString(snum); //Print the String
  SeeedOled.setTextXY(0,10);
  SeeedOled.putString("C"); //Print the String
  SeeedOled.setTextXY(2,0); 
SeeedOled.putString("humid = "); //Print the String

 Serial1.println(snum);   

num = DHT.humidity;
itoa(num, snum, 10);

  SeeedOled.setTextXY(2,9); 
SeeedOled.putString(snum); //Print the String

  SeeedOled.setTextXY(2,11); 
SeeedOled.putString("%"); //Print the String

    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 
