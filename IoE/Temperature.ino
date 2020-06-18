void Temperature(){
  float val, R, vol;   

 // The first batteries
 val = analogRead(tem1);
 vol = (val*voltage_arduino)/1024;
 R = (r *(voltage_arduino))/vol;
 Temp.data[0] = (t0 * belta) / (belta + (t0 * log(R / R0)));
 Temp.data[0] =  Temp.data[0] -273;

 // second temperature
 val = analogRead(tem2);
 vol = (val*voltage_arduino)/1024;
 R = (r *(voltage_arduino))/vol;
 Temp.data[1] = (t0 * belta) / (belta + (t0 * log(R / R0)));
 Temp.data[1] =  Temp.data[1] -273;

 // third temperature
 val = analogRead(tem3);
 vol = (val*voltage_arduino)/1024;
 R = (r *(voltage_arduino))/vol;
 Temp.data[2] = (t0 * belta) / (belta + (t0 * log(R / R0)));
 Temp.data[2] =  Temp.data[2] -273;

  // fouth temperature
 val = analogRead(tem4);
 vol = (val*voltage_arduino)/1024;
 R = (r *(voltage_arduino))/vol;
 Temp.data[3] = (t0 * belta) / (belta + (t0 * log(R / R0)));
 Temp.data[3] =  Temp.data[3] -273;
 
  // firth temperature
 val = analogRead(tem5);
 vol = (val*voltage_arduino)/1024;
 R = (r *(voltage_arduino))/vol;
 Temp.data[4] = (t0 * belta) / (belta + (t0 * log(R / R0)));
 Temp.data[4] =  Temp.data[4] -273;

 
 /*
  * Testing the data 
  */
//Serial.print("Temp1: ");
//Serial.println(Temp.data[0]);
//Serial.print("Temp2: ");
//Serial.println(Temp.data[1]);
//Serial.print("Temp3: ");
//Serial.println(Temp.data[2]);
//Serial.print("Temp4: ");
//Serial.println(Temp.data[3]);
//Serial.print("Temp5: ");
//Serial.println(Temp.data[4]);
}
