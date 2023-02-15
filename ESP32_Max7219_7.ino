/*
Requisitos: Librería “LedController”. Usa el protocolo SPI, los pines a usar varian según la placa Arduino a usar
*/

#include "LedController.hpp"

/*
Conectar los pines del max7219 como la definición que sigue
*/
#define DIN 23
#define CS 5
#define CLK 18

/*
 Ahora necesitamos una variable LedController para trabajar.
 Solo tenemos un MAX72XX, por lo que las dimensiones son 1,1.
 */
 
LedController<1,1> lc;

/* Dar un tiempo entre refresco de display */
unsigned long delaytime=500;

void setup() {
  // Aquí se crea un nuevo objeto LedController sin hardware SPI.
  lc=LedController<1,1>(DIN,CLK,CS);
  lc.setIntensity(8); // Se establece el brillo en valores medios.
  lc.clearMatrix(); // Se borra el display
}

void loop() {
 for(int i=0; i<8; i++) {
     lc.setDigit(0,i,i,false);
     delay(delaytime);
  }



  lc.clearMatrix();
  delay(delaytime);
}
