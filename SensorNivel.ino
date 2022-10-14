/*#define trigPinDep1 5
#define echoPinDep1 18
#define trigPinDep2 21
#define echoPinDep2 19
#define nebulizador 2

float distanceCm;

long medirNivel (int trig, int echo ){

   //Limpiamos los pines del sensor de nivel
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distanceCm =duration * SOUND_SPEED/2;
  return distanceCm;
}

void SensorNivelSetUP (){
  pinMode(trigPinDep1, OUTPUT); //Pin salida sensor nivel deposito1
  pinMode(echoPinDep1, INPUT); //Pin entrada sensor nivel deposito1
  pinMode(trigPinDep2, OUTPUT); //Pin salida sensor nivel deposito2
  pinMode(echoPinDep2, INPUT); //Pin entrada sensor nivel deposito2
  
}
 */
