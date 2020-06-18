/*
 * If you miss understand about the codes, you can go and read the readme.txt file this folder.
 * And you can also go and check out my repository in the GitHub account. This is the link
 * "https://github.com/Chenrith28/IoE_software"
 *  
 *  I put nearly all the comment of all the code in the Readme file.
 */

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


const int voltage_arduino = 5; // constant of arduino voltage.
const float t0 = 298.15, R0 = 10000, belta = 3950, r = 10000; //Temperature constant data for calculation.
struct  Data{
  float data[4]; 
  float smoke;
  
}Temp, Gas;

void setup(){
  Serial.begin(115200); //Start the serial baudrate with 115200
}

void loop(){
  Temperature();
  
  
  //Gas measurement 
  Gas.smoke = analogRead(gas);
  DC_data();
  
}

/*
 * Initialize the RGB for the logo of Stablu and IoE
 */
void RGB_STABLU(int r, int g, int b){
  analogWrite(st_r, r);
  analogWrite(st_g, g);
  analogWrite(st_b, b);
}
void RGB_IoE(int r, int g, int b){
  analogWrite(ioe_r, r);
  analogWrite(ioe_g, g);
  analogWrite(ioe_b, b);
}
