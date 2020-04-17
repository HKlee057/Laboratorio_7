/*
 Laboratorio 7 - Electrónica Digital 2
 Hector A. Klée González
 17118
 */

/***********************************************************
 * Librerías 
 ***********************************************************/
#include <SPI.h>
#include <SD.h>

/***********************************************************
 * Variables
 ***********************************************************/
File myFile;
String x = "";
int i = 0;
/***********************************************************
 * Void de inicio 
 ***********************************************************/
void setup() {
  // Inicio de comunicación serial con un baudrate de 9600 
  Serial.begin(9600);
  // Definición de módulo SPI a utilizar
  SPI.setModule(0);

  while (!Serial) {
    ; // Espera a conexión serial
  }
  // Despliegue de estado de lectura
  Serial.print("Iniciando tarjeta SD...");
  if (!SD.begin(4)) {
    // Mensaje en caso de inicio de inicialización fallida
    Serial.println("¡Inicialización fallida!");
    while (1);
  }
  // Al completar la inicialización de la tarjeta despliega el siguiente menú
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
/***********************************************************
 * Void de infinito 
 ***********************************************************/
void loop() {
    //Mientras esté disponible la comunicación, verificar esta condición
    while (Serial.available()){
      // Guarda valor leído en variable character
      char character = Serial.read();
      // En caso de no corresponder a uno de las opción, concatena los valores 
      if (character != '\n'){
        x.concat(character);
      }
    }
  //*****************************************************************************   
  // En caso de elegir la imágen de Darth Vader, realizar lo siguiente  
  if(x=="VADER"){
    // Abrir el archivo deseado
    myFile = SD.open("VADER.txt");
    // Si se cumple la condión de tener un archivo con el nombre indicado
    if (myFile) {
      Serial.println("Desplegando a Darth Vader:");
      // Leer el archivo por completo
      while (myFile.available()) {
        // Desplegar el archivo leído en el monitor
        Serial.write(myFile.read());
      }
      // Cerrar el archivo
      myFile.close();
      // Desplegar menú nuevamente
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
      // Limpia la variable inicial
      x = ""; 
    } 
    else {
      // Si el archivo no se abre, desplegar mensaje de error
      Serial.println("Error desplegando el archivo.");
    }
  }
  //*****************************************************************************
  // En caso de elegir la imágen de R2-D2, realizar lo siguiente  
  if(x=="R2D2"){
    // Abrir el archivo deseado
    myFile = SD.open("R2D2.txt");
    // Si se cumple la condión de tener un archivo con el nombre indicado
    if (myFile) {
      Serial.println("Desplegando a R2-D2:");
      // Leer el archivo por completo
      while (myFile.available()) {
        // Desplegar el archivo leído en el monitor
        Serial.write(myFile.read());
      }
      // Cerrar el archivo
      myFile.close();
      // Desplegar menú nuevamente
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
      // Limpia la variable inicial
      x = ""; 
    } 
    else {
      // Si el archivo no se abre, desplegar mensaje de error
      Serial.println("Error desplegando el archivo.");
    }
  }
  //*****************************************************************************
  // En caso de elegir la imágen de MegaMan, realizar lo siguiente  
  if(x=="MEGAMAN"){
    // Abrir el archivo deseado
    myFile = SD.open("MEGAMAN.txt");
    // Si se cumple la condión de tener un archivo con el nombre indicado
    if (myFile) {
      Serial.println("Desplegando a MegaMan:");
      // Leer el archivo por completo
      while (myFile.available()) {
        // Desplegar el archivo leído en el monitor
        Serial.write(myFile.read());
      }
      // Cerrar el archivo
      myFile.close();
      // Desplegar menú nuevamente
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
      // Limpia la variable inicial
      x = ""; 
    } 
    else {
      // Si el archivo no se abre, desplegar mensaje de error
      Serial.println("Error desplegando el archivo.");
    }
  }
  //*****************************************************************************
  // En caso de elegir la opción de finalizado, realizar lo siguiente  
  if(x=="END"){
    // Verificar si la variable de conteo es menor que 1
    if(i<1){
      // Sumar la variable de conteo
      i++;
      // Desplegar mensaje de despedida
      Serial.println("Adiós.");
      }
    // Finalizar comunicación serial  
    Serial.end();
  }
}
