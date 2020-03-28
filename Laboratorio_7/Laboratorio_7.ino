/*
 Laboratorio 4 - Electrónica Digital 2
 Hector A. Klée González
 17118
 */

#include <SPI.h>
#include <SD.h>

File myFile;
String x = "";
int i = 0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Iniciando tarjeta SD...");
  if (!SD.begin(4)) {
    Serial.println("¡Inicialización fallida!");
    while (1);
  }
  Serial.println("Inicialización completada.");
  Serial.println("");
  Serial.println("Ingrese alguno de los siguientes:");
  Serial.println("");
  Serial.println("-VADER");
  Serial.println("");
  Serial.println("-R2D2");
  Serial.println("");
  Serial.println("-MEGAMAN");  
  Serial.println("");
  Serial.println("-END (para cerrar)"); 
}

void loop() {
    while (Serial.available()){
      char character = Serial.read();
      if (character != '\n'){
        x.concat(character);
      }
    } 
  if(x=="VADER"){
    // re-open the file for reading:
    myFile = SD.open("VADER.txt");
    if (myFile) {
      Serial.println("Desplegando a Darth Vader:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Serial.println("");
      Serial.println("Ingrese alguno de los siguientes:");
      Serial.println("");
      Serial.println("-VADER");
      Serial.println("");
      Serial.println("-R2D2");
      Serial.println("");
      Serial.println("-MEGAMAN");  
      Serial.println("");
      Serial.println("-END (para cerrar)"); 
      x = ""; //Limpia la variable inicial
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("Error desplegando el archivo.");
    }
  }
    if(x=="R2D2"){
    // re-open the file for reading:
    myFile = SD.open("R2D2.txt");
    if (myFile) {
      Serial.println("Desplegando a R2-D2:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Serial.println("");
      Serial.println("Ingrese alguno de los siguientes:");
      Serial.println("");
      Serial.println("-VADER");
      Serial.println("");
      Serial.println("-R2D2");
      Serial.println("");
      Serial.println("-MEGAMAN");  
      Serial.println("");
      Serial.println("-END (para cerrar)"); 
      x = ""; //Limpia la variable inicial
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("Error desplegando el archivo.");
    }
  }
    if(x=="MEGAMAN"){
    // re-open the file for reading:
    myFile = SD.open("MEGAMAN.txt");
    if (myFile) {
      Serial.println("Desplegando a MegaMan:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
      Serial.println("");
      Serial.println("Ingrese alguno de los siguientes:");
      Serial.println("");
      Serial.println("-VADER");
      Serial.println("");
      Serial.println("-R2D2");
      Serial.println("");
      Serial.println("-MEGAMAN");  
      Serial.println("");
      Serial.println("-END (para cerrar)"); 
      x = ""; //Limpia la variable inicial
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("Error desplegando el archivo.");
    }
  }
  if(x=="END"){
      if(i<1){
        i++;
        Serial.println("Adiós.");
        }
      Serial.end();
  }
}
