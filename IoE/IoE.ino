/*
 * If you miss understand about the codes, you can go and read the readme.txt file this folder.
 * And you can also go and check out my repository in the GitHub account. This is the link
 * "https://github.com/Chenrith28/IoE_software"
 *  
 *  I put nearly all the comment of all the code in the Readme file.
 */

/*
 * The librarires
 * The time and sd card library
 */
#include <Wire.h>  // Real time clock library 
#include "RTClib.h"
#include <SPI.h>  // SD card library
#include <SD.h> 
RTC_DS3231 rtc; // Initial the variable for RTC 
File myFile;  //Name of the SD card file saving
char Time[32], Date[32];  // For store the date and time.

#define tem1 A0
#define tem2 A1
#define tem3 A2
#define tem4 A3
#define tem5 A4
#define gas A14
#define st_r 11 // Stablu and IoE rgb logo 
#define st_g 13
#define st_b 9 
#define ioe_r 5
#define ioe_g 7
#define ioe_b 3
#define buzzer 35
#define fan 29
#define System 23
#define AC_volt A13
#define AC_current A10 

//We use the millis() fucntion to replace delay()
unsigned long previouseMillis = 0;
const long interval = 5;
float mVperamp = 0.1, rZero,cali;
long sampleDuration;
const int voltage_arduino = 5; // constant of arduino voltage.
const float t0 = 298.15, R0 = 10000, belta = 3950, r = 10000; //Temperature constant data for calculation.
struct  Data{
  float data[4]; 
  float smoke, volt, corrent,power,energy;
  
}Temp, Gas,AC;

void setup(){
  Serial.begin(115200); //Start the serial baudrate with 115200
  sd_card_initial();
  pinMode(st_r,OUTPUT);
  pinMode(st_b,OUTPUT);
  pinMode(st_g,OUTPUT);
  pinMode(ioe_r,OUTPUT);
  pinMode(ioe_g,OUTPUT);
  pinMode(ioe_b,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(System,OUTPUT);

}

void loop(){
  Temperature();
  TIME();
  
  //Gas measurement 
  Gas.smoke = analogRead(gas);
  DC_data();
  RTC_initial();
  
}

/*
 * Initialize the RGB for the logo of Stablu and IoE
 */
void RGB_STABLU(int r, int g, int b){
    /*
   * This is the function that we use for RGB controlled for our logo
   * We just added the value to this function, then we can controll it to what we want.
   * Example: RGB_STABLU(200,200,100);
   */
  analogWrite(st_r, r);
  analogWrite(st_g, g);
  analogWrite(st_b, b);
}
void RGB_IoE(int r, int g, int b){
  /*
   * This is the function that we use for RGB controlled for our logo
   * We just added the value to this function, then we can controll it to what we want.
   * Example: RGB_IoE(255,100,0)
   */
  analogWrite(ioe_r, r);
  analogWrite(ioe_g, g);
  analogWrite(ioe_b, b);
}
void serialCommunication(){
  Serial.print(Temp.data[0]);
  Serial.print("a");
  Serial.print(Temp.data[1]);
  Serial.print("b");
  Serial.print(Temp.data[2]);
  Serial.print("c");
  Serial.print(Temp.data[3]);
  Serial.print("d");
  Serial.print(Temp.data[4]);
  Serial.println("e");
}
void AC_data(){
  float Sample=0.0,sample =0.0,sample_average,Vrms, Irms,I_volt_rms,Sample_average;
  float SUM_1,Average, powerFactor = 0.85;
  float second_average;
  int rVal = 0, sampleCount = 0;
  unsigned long currentMillis = millis();
  if(currentMillis -previouseMillis >= interval){
    sample_average = analogRead(AC_volt);
    second_average = analogRead(AC_volt);
  }
  AC.volt = second_average*220/1023;
//AC.volt = 220; // This is the sample way, because the AC voltage is always 220 volt.
  sampleDuration = 19.8;       // 100ms
  unsigned long rSquaredSum;
  unsigned long startTime = millis();
  if(millis() - startTime < sampleDuration){
    rVal = (analogRead(AC_current)-rZero);
    rVal=sq(rVal);
    rSquaredSum+=(rVal);
    sampleCount++;
  }
  float MEAN = sqrt(rSquaredSum/sampleCount);
  double voltRMS = (voltage_arduino * MEAN);
  voltRMS = voltRMS/1024.0;
  AC.corrent = voltRMS * 10.0;
  AC.power = AC.corrent * AC.volt;
  
}
