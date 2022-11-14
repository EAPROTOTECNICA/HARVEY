
/*Para conectarse con la ESP32 hay que usar los pines IO17 para el RX de la pantallla y IO16 para el TX
 * PASO1: Ir a Documentos/Arduino/librerias/ITEADLIB_Arduino_Nextion. Abrir el archivo NexConfig.h 
 * y asegurarse que estas líneas no están comentadas:
 *          #define DEBUG_SERIAL_ENABLE
 *          #define dbSerial Serial
 *          #define nexSerial Serial2 (Prestar atención que sea el Serial2)
 *PASO 2: Abrir el archivo NexHardware.cpp, buscar la función nexInit () y nexInit (int baud)
 *y asegurarse que están así:
 *
 *          nexInit(250000);
 *          
 *          dbSerialBegin(baud);
            nexSerial.begin(115200);
 *        
 *PASO 3: A la hora de ver a través del monitor serie, la comunicación es a 22000 bauds
 */
   
//Libreria Pantalla
#include "Nextion.h"

//Libreria Sensor de humedad y temperatura
#include <dht11.h>

//Libreria Expansor I/O Arduino
#include "PCF8575.h" 


#define TIMER 3
#define SOUND_SPEED 0.034
PCF8575 pcf8575(0x20);

  

void setup() {

  pantallaSetUP();
  SensorHTSetUP();
  extensorSetUP();
 
}

void loop() {

  SensorHT_loop();
  pantalla_loop ();


}
