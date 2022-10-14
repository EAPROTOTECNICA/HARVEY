
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


#define TIMER 2
#define SOUND_SPEED 0.034
PCF8575 pcf8575(0x20);

#define PUMPPIN 9    //peristaltic pump control pin, connect to arduino digital pin 9
#define waitTime 2000 //interval time(ms) between every state
  


Servo myservo;

void setup() {
  
  //SensorHTSetUP();
  extensorSetUP();
  pantallaSetUP();
    myservo.attach(PUMPPIN);
  
}

void loop() {

  //SensorHT_loop();
  //extensor_loop();
  pantalla_loop ();




    myservo.write(0);   //Clockwise maximum speed rotation
    delay(waitTime);
    myservo.write(90);  //Stop
    delay(waitTime);
    myservo.write(180); //Counterclockwise maximum speed rotation
    delay(waitTime);
    myservo.write(90);  //Stop
    delay(waitTime);
  
 /*tiempo2 = millis();
  if(tiempo2 > (tiempo1+1000)){  //Si ha pasado 1 segundo ejecuta el IF
    tiempo1 = millis(); //Actualiza el tiempo actual
    tiempoSegundos = tiempo1/1000;
    tiempo3++;
  }
  if (tiempo3==TIMER){
    //float temp=medirHT();
    //float humedad=medirHT();
    long NivelDeposito1=100-(medirNivel(trigPinDep1,echoPinDep1)*100)/9.8;
    p10_j0.setValue(NivelDeposito1);
    Serial.print("Distance 1 (cm): ");
    Serial.println(NivelDeposito1);
    long NivelDeposito2= 100-(medirNivel(trigPinDep2,echoPinDep2)*100)/9.8;
    Serial.print("Distance 2 (cm): ");
    Serial.println(NivelDeposito2);
    char cadena [8]={0};
    //dtostrf(temp,4,1,cadena);
    p1_t1.setText(cadena);
    p2_t1.setText(cadena);
    //dtostrf(humedad,2,0,cadena);
    //p2_t2.setText(cadena);
    
    tiempo3=0;    
  }*/
}
