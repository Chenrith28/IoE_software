void sd_card_initial(){
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...\n");

  if (!SD.begin(53)) {  // 53 is the CS pin of mega 2560 .
    Serial.println("initialization failed!");
    Serial.println("1. Please check the wire.");
    Serial.println("2. Please check the memory card.");
    Serial.println("3. Please check the code.");
    Serial.println("4. Buy a new one.)");
    while (1);
  }
  Serial.println("Initialization done.");
  Serial.println("Start saving data!!!^_^");
  
  myFile = SD.open("STABL_data.txt", FILE_WRITE); // created and open the file.
  /*
     I want to write the header file in this sheet.
     Set the head file is easy for store and look not only in text and in excel.
  */
  if (myFile) { // open the file before write
    /*
       This is the how to open the file for store the data in memory.
    */

  }
}
