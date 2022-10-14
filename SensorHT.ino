#define DHT11_PINB1 4

dht11 DHT;

uint8_t  SensorHTSetUP(){

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
  Serial.print(DHT.humidity,1);
  Serial.print(",\t");
  Serial.println(DHT.temperature,1);
}
