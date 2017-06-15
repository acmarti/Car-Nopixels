//derivative of bttestgree_working_app for debugging
//in construction  as of 6/15/17

#include<SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>


#define PIN     6
#define NUMPIXELS 20 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 100;// delay tenth of a second
////--temp--////
int state = 0;
int flag = 0;
////////////
//String color;

SoftwareSerial BT(0,1); //TX, Rx respectively
//String color;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  delay(1500);
  strip.begin();
  strip.setBrightness(64);
  strip.show();//initialize all pixels to 'off'
}

void loop() {
  //Serial.println(BT.read());
  /*
  if (BT.available()<0){
  for(int i=0; i<NUMPIXELS; i++){
     strip.setPixelColor(i,strip.Color(88,233,255));
     strip.show();
     delay(delayval);
  }}
*/
  
  if(BT.available() > 0){    //Serial.available
    delay(10); //used for stabilization
    state = BT.read(); //do not delete
    //state = BT.read();
    flag = 0;
    //char c = Serial.read(); //conduct serial read
    //color += c; //build string-blue,red,green

  }
  
    //"Green"  state =='1'
    if(state == '2')
    {
      for(int i=0;i<NUMPIXELS;i++){

         // strip.Color takes RGB values, from 0,0,0 up to 255,255,255
         strip.setPixelColor(i, strip.Color(0,200,0)); // Moderately bright green color.
         strip.show(); // This sends the updated pixel color to the hardware.
         delay(delayval); // Delay for a period of time (in milliseconds).

          //if(flag == 0){
          //  Serial.println("LED: Green");
          //  flag = 1;
         // }
       }
     }


    if (state == '0')  //color =="Stop"
    {  
       turnoff();
    
       if(flag == 0){
         Serial.println("LED: off");
         flag = 1;
       }
     }
     
      //color picker
      else if(state== '1')
     {
      //Serial.println(BT.read());
      int red = BT.parseInt();
      int green = BT.parseInt();
      int blue = BT.parseInt();
      int rando = BT.parseInt();
     Serial.print(red);
     Serial.print(green);
     Serial.println(blue);
       // if(Serial.read() == '\n'){
      //red = constrain(red,0,255);
      //green = constrain(green,0,255);
      //blue = constrain(blue,0,255);
      turnoff();
        for(int i=0; i<NUMPIXELS; i++){
          strip.setPixelColor(i,strip.Color(red,green,blue));
          strip.show();
          delay(delayval);

          /////////Debug///////////
          //Serial.println(red );
          //Serial.print(green);
          //Serial.print(blue);
         // }
        }
     }

  }
      
      //decrement
void turnoff(){
  for(int i=NUMPIXELS;i>0;i--){
    strip.setPixelColor(i, strip.Color(0,0,0)); //
    strip.show(); 
    delay(60);
  }
}

/*
    for(int i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, strip.Color(0,0,0)); //
    strip.show(); 
    delay(10); 
    }
      */ 


  /*
 to Do
 +add color palate using colors-> make color to send 3 values to arduino
 +add weather/mod function function
 +time of day function
  
  */

