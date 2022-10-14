#define MAX_OUTPUTS 17

uint8_t  extensorSetUP(){

  // Set pinMode to OUTPUT
  pcf8575.pinMode(P0, OUTPUT);
  pcf8575.pinMode(P1, OUTPUT);
  Serial.println("Iniciando extensor...");
  pcf8575.digitalWrite(P0, HIGH);
  pcf8575.digitalWrite(P1, HIGH);
  pcf8575.begin();
  
}

void extensor_loop()
{
  pcf8575.digitalWrite(P0, HIGH);
  delay(5000);
  pcf8575.digitalWrite(P0, LOW);
  delay(8000);
}
