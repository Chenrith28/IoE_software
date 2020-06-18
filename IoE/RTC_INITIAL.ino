void RTC_initial(){
  Wire.begin(); 
  rtc.begin();  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // For getting the moment time.
  }
