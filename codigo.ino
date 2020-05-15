#include <SPI.h>    // incluye libreria interfaz SPI
#include <SD.h>     // incluye libreria para tarjetas SD

#define SSpin 10    // Slave Select en pin digital 10
String codigo;

File archivo;     // objeto archivo del tipo File

void setup() {
  Serial.begin(9600);       // inicializa monitor serie a 9600 bps
  Serial.println("Inicializando tarjeta ...");  // texto en ventana de monitor
  if (!SD.begin(SSpin)) {     // inicializacion de tarjeta SD
    Serial.println("fallo en inicializacion !");// si falla se muestra texto correspondiente y
    return;         // se sale del setup() para finalizar el programa
  }
}
void abrir_codigo(){
  
  archivo = SD.open(codigo);    // apertura de codigo

  if (archivo) {
    Serial.println("\nEjecutando Codigo"); // texto en monitor serie
    while (archivo.available()) {   // mientras exista contenido en el archivo
      Serial.write(archivo.read());     // lectura de a un caracter por vez
    }
    archivo.close();        // cierre de archivo
  } else {
    Serial.println("error en iniciacion de codigo");// texto de falla en apertura de archivo
  }
  
  
  }

void loop() {     
Serial.println("\nEsperando Codigo a recibir....");
  delay(2000);
if (Serial.available())
   {
     codigo = Serial.readStringUntil('\n');    
     abrir_codigo();
     
   }
   return;   
}
