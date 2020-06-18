void TIME(){
  DateTime now = rtc.now(); // The moment time for arduino.
  sprintf(Time, "%02d:%02d:%02d",  now.hour(), now.minute(), now.second()); 
  sprintf(Date, "%02d/%02d/%02d",  now.day(), now.month(), now.year());

//  Serial.println(F("Time: "));
//  Serial.println(Time);
//  Serial.print(F("Date: "));
//  Serial.print(Date);

}
