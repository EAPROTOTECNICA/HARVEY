#define DHT11_PINB1 4
dht11 DHT;
int tiempo1=0,tiempoSegundos=0,tiempo2=0;
int tiempo3=0;

bool contarsegundos (){
  tiempo2 = millis();
  if(tiempo2 > (tiempo1+1000)){  //Si ha pasado 1 segundo ejecuta el IF
    tiempo1 = millis(); //Actualiza el tiempo actual
    tiempoSegundos = tiempo1/1000;
    Serial.print (tiempoSegundos);
    tiempo3++;
  }
  if (tiempo3==TIMER){
    tiempo3=0;
    return true;
  }
  else 
  return false;
}

void  SensorHTSetUP(){

  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  int chk;
  chk = DHT.read(DHT11_PINB1); 
  switch (chk){
    case DHTLIB_OK:
                Serial.println("Sensor DH11 OK \t");
                break;
    case DHTLIB_ERROR_CHECKSUM:
                Serial.print("Sensor DH11 checksum error,\t");
                break;
    case DHTLIB_ERROR_TIMEOUT:
                Serial.print("Sensor time out error,\t");
                break;
    default:
                Serial.print("Sensor unknown error,\t");
                break;
  }
  
}

void SensorHT_loop()
{
  if(contarsegundos()){
  char cadena [8]={0};
  char cadena1 [8]={0};
  dtostrf(DHT.temperature,4,1,cadena);
  dtostrf(DHT.humidity,4,1,cadena1);
  p1_t1.setText(cadena);
  p1_t2.setText(cadena1);
  }
}
