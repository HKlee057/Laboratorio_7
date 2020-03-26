/*
 Laboratorio 4 - Electrónica Digital 2
 Hector A. Klée González
 17118
 */

#include <SPI.h>
#include <SD.h>

File myFile;
int x = 0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 
  SPI.setModule(0);
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  Serial.println("");
  Serial.println("Please enter your character");
  Serial.println("");
  Serial.println("METROID");
  Serial.println("");
  Serial.println("LINK");
  Serial.println("");
  Serial.println("WALUIGI");  
  


}

void loop() {
  if(Serial.available()>0){
  x = Serial.read();
  }
  if(x==86){
    // re-open the file for reading:
    myFile = SD.open("Vader.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
  }
}
