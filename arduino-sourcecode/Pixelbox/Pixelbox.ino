/**
    Pixelbox Firmware
    Copyright (C) 2016  John Bakker

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/



#include <Adafruit_NeoPixel.h>
// include the SD library:
#include <SPI.h>
#include <SdFat.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>


const int chipSelect = 10;
#define PIN 6


SdFat sd;
SdFile file;


// mode 0 is (next row starts at 0)
// mode 1 is next row starts below the last pixel
byte mode = 1;

int lb=0;
byte displayMode=0;
boolean breakAnim=false;
boolean autoadvance=true;

const byte maxMode=2;
const char filePattern[10]= "A%03d.SRC";
const int totalPixels=256;
char line[64];

byte xSize = 16;
byte ySize = 16;

byte loops=10;
byte lnr=0;
byte nr=0;
int delayspeed=100;

int buttonPin=A1;

  
byte imageScale =1;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(totalPixels, PIN, NEO_GRB + NEO_KHZ800);


void setup() {

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  pinMode(10, OUTPUT);
  if (!sd.begin(chipSelect, SPI_FULL_SPEED)) {
    sd.initErrorHalt();
  }  
  pinMode(buttonPin, INPUT_PULLUP);

  //read config
}


void loop() {
  
  if(displayMode==0)
  {
    autoadvance=true;
    loadAnim();
  }
  else if(displayMode==1)
  {

     autoadvance=false;
     loadAnim();
  }


  breakAnim=false;
 
  checkButtons();
}


void wipeScreen()
{
  for(int pixel=0;pixel<totalPixels;pixel++)
  {
    strip.setPixelColor(pixel,color(0,0,0));
  }
}
void checkButtons()
{
 int c = analogRead(buttonPin);
  Serial.println(c);
  if(c<lb+4 && c>lb-4)
  {
    //same button
    lb =c ;
    //nothing happened
    return;
  }
  lb =c;
  
  if(c<100)
  {
    //button 1
    breakAnim=true;
    nr++;
  }
  else if(c<300)
  {
    wipeScreen();
    //button 2
    breakAnim=true;
    displayMode++;
    if(displayMode>=maxMode)
    {
      displayMode=0;
    }
      
  }
}

void loadAnim()
{
  unsigned long  startMil =0;
  char infile[13];
    sprintf(infile,filePattern,nr);

  uint32_t c;

  if (file.open(infile,O_READ)) {//file exists




    byte frames  = file.read();// first byte is the amount of frames

    loops = file.read();
    delayspeed = file.read()*10;
    for(byte f=0;f<frames;f++)
    {

      startMil = millis();
      for(byte y=0;y<ySize;y++)
      {
        for(byte x=0;x<xSize;x++)
        {
          byte r = file.read();
          byte g = file.read();
          byte b = file.read();          
          c= color(r*0.3,g*0.3,b*0.3);
          
          setPixel(x,y,c);    
              

        }
         checkButtons(); 
        if(breakAnim)
        {
           file.close();
           return;
        }    
      }


      strip.show();
      int del = millis()-startMil;
//      checkButtons();      
      if(del<delayspeed)
      {
        //just continue;
        delay(delayspeed-del);
      }

    }

    file.close();

    lnr++;
    if(lnr>=loops)
    {
      if(autoadvance)
      {
        nr++;
      }
      lnr=0;
    }
  
  }
  else
  {

    nr=0;
    lnr=0;
  }

}

void setPixel(byte x,byte y,uint32_t color)
{

  if(mode==0)
  {
    strip.setPixelColor((y*xSize)+x,color);
  }
  else if(mode==1)
  {
    if(y % 2!=0)
    {
      strip.setPixelColor((y*xSize)+x,color);
    }
    else
    {

      strip.setPixelColor((y*xSize)+((xSize-1)-x),color);
    }
  }
}
uint32_t color(byte r,byte g,byte b)
{
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}
int stringToInt(String inp)
{
  char buf[inp.length()+1];
  int rv=0;

  inp.toCharArray(buf,inp.length()+1);



  rv = atoi(buf);
  return rv;
}

String splitString(String s, char parser,int index){
  String rs='\0';
  int parserIndex = index;
  int parserCnt=0;
  int rFromIndex=0, rToIndex=-1;

  while(index>=parserCnt){
    rFromIndex = rToIndex+1;
    rToIndex = s.indexOf(parser,rFromIndex);

    if(index == parserCnt){
      if(rToIndex == 0 || rToIndex == -1){
        return '\0';
      }
      return s.substring(rFromIndex,rToIndex);
    }
    else{
      parserCnt++;
    }

  }
  return rs;
}

