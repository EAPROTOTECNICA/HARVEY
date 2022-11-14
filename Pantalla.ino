#include "Nextion.h"
#define ledPin 2

//Pagina 0
NexPage p0 = NexPage(0,0,"page0");
//Pagina 1
NexPage p1 = NexPage(1,0,"page1");
NexText p1_t1 = NexText(1,8,"t0_1");
NexText p1_t2 = NexText(1,12,"t2_1");
NexText p1_t3 = NexText(1,14,"t4_1");
NexText p1_t4 = NexText(1,16,"t6_1");
NexText p1_t5 = NexText(1,19,"t8_1");
NexText p1_t6 = NexText(1,20,"t10_1");
NexText p1_t7 = NexText(1,22,"t12_1");
NexText p1_t8 = NexText(1,24,"t14_1");
NexDSButton p1_bt0 = NexDSButton(1,9,"bt0_1");
//Pagina 2
NexPage p2 = NexPage(2,0,"page2");
NexText p2_t1 = NexText(2,1,"t0_2");
NexText p2_t2 = NexText(2,2,"t1_2");
NexDSButton p2_bt0 = NexDSButton(2,4,"bt0_2");
NexDSButton p2_bt1 = NexDSButton(2,5,"bt1_2");
//Pagina 3
NexPage p3 = NexPage(3,0,"page3");
NexText p3_t1 = NexText(3,1,"t0_3");
NexText p3_t2 = NexText(3,2,"t1_3");
NexDSButton p3_bt0 = NexDSButton(3,4, "bt0_3");
NexDSButton p3_bt1 = NexDSButton(2,5,"bt1_3");
//Pagina 4
NexPage p4 = NexPage(4,0,"page4");
NexText p4_t1 = NexText(4,1,"t0_4");
NexText p4_t2 = NexText(4,2,"t1_4");
NexDSButton p4_bt0 = NexDSButton(4,4, "bt0_4");
NexDSButton p4_bt1 = NexDSButton(4,5,"bt1_4");
//Pagina 5
NexPage p5 = NexPage(5,0,"page5");
NexText p5_t1 = NexText(5,1,"t0_5");
NexText p5_t2 = NexText(5,2,"t1_5");
NexDSButton p5_bt0 = NexDSButton(5,4, "bt0_5");
NexDSButton p5_bt1 = NexDSButton(5,5,"bt1_5");
//Pagina 6
NexPage p6 = NexPage(6,0,"page6");
NexText p6_t1 = NexText(6,1,"t0_6");
NexText p6_t2 = NexText(6,2,"t1_6");
NexDSButton p6_bt0 = NexDSButton(6,4, "bt0_6");
NexDSButton p6_bt1 = NexDSButton(6,5,"bt1_6");
//Pagina 7
NexPage p7 = NexPage(7,0,"page7");
NexText p7_t1 = NexText(7,1,"t0_7");
NexText p7_t2 = NexText(7,2,"t1_7");
NexDSButton p7_bt0 = NexDSButton(7,4, "bt0_7");
NexDSButton p7_bt1 = NexDSButton(7,5,"bt1_7");
//Pagina 8
NexPage p8 = NexPage(8,0,"page8");
NexText p8_t1 = NexText(8,1,"t0_8");
NexText p8_t2 = NexText(8,2,"t1_8");
NexDSButton p8_bt0 = NexDSButton(8,4, "bt0_8");
NexDSButton p8_bt1 = NexDSButton(8,5,"bt1_8");
//Pagina 9
NexPage p9 = NexPage(9,0,"page9");
NexText p9_t1 = NexText(9,1,"t0_9");
NexText p9_t2 = NexText(9,2,"t1_9");
NexDSButton p9_bt0 = NexDSButton(9,4, "bt0_9");
NexDSButton p9_bt1 = NexDSButton(9,5,"bt1_9");
//Pagina 11
NexPage p11 = NexPage(11,0,"page11");
NexText p11_t1 = NexText(11,5,"t0_11");
NexText p11_t2 = NexText(11,6,"t1_11");
NexProgressBar p11_j0  = NexProgressBar(11,1,"j0_11");
NexDSButton p11_bt0 = NexDSButton(11,3, "bt0_11");
NexDSButton p11_bt1 = NexDSButton(11,4,"bt1_11");
//Pagina 12
NexPage p12 = NexPage(12,0,"page12");
NexText p12_t1 = NexText(12,5,"t0_12");
NexText p12_t2 = NexText(12,6,"t1_12");
NexProgressBar p12_j0  = NexProgressBar(12,1,"j0_12");
NexDSButton p12_bt0 = NexDSButton(12,3, "bt0_12");
NexDSButton p12_bt1 = NexDSButton(12,4,"bt1_12");
//Pagina 13
NexPage p13 = NexPage(13,0,"page13");
//Pagina 14
NexPage p14 = NexPage(14,0,"page14");


NexTouch *nex_listen_list[] = {
  &p1_bt0,&p2_bt0,&p2_bt1,&p3_bt0,&p3_bt1,&p4_bt0,&p4_bt1,&p5_bt0,&p5_bt1,&p6_bt0,&p6_bt1,&p7_bt0,
  &p7_bt1,&p8_bt0,&p8_bt1,&p9_bt0,&p9_bt1,&p11_bt0,&p11_bt1,&p12_bt0,&p12_bt1,NULL
};

uint32_t next, myInt = 0;

void escribir (){
  float temp =4.9;
  char cadena [8]={0};
  dtostrf(temp,4,1,cadena);
  p1_t2.setText(cadena);
  //p1_t2.setText("Hola");
}

void p2_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p2_bt0.getValue(&dual_state);
  if(dual_state) {
        pcf8575.digitalWrite(P0, HIGH);
        Serial.println("luz off");
        
  }else{
        pcf8575.digitalWrite(P0, LOW);
        Serial.println("luz on");
  }
}
void p2_bt1_Press (void *ptr) {
  uint32_t dual_state;
  p2_bt1.getValue(&dual_state);
  if(dual_state) {
        pcf8575.digitalWrite(P1, HIGH);
        Serial.println("BOMBA OFF");
        
  }else{

        pcf8575.digitalWrite(P1, LOW);
        Serial.println("BOMBA ON");
  }
}
void p3_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p3_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);

  }
}
void p4_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p4_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);
  }
}
void p5_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p5_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);
  }
}
void p6_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p6_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);
  }
}

void p7_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p7_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);
  }
}
void p8_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p8_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);
  }
}
void p9_bt0_Press (void *ptr) {
  uint32_t dual_state;
  p9_bt0.getValue(&dual_state);
  if(dual_state) {
        digitalWrite(ledPin, HIGH);
  }else{
        digitalWrite(ledPin, LOW);
  }
  
}

void pantallaSetUP() {
  nexInit();
  Serial.println("Iniciando pantalla");
  p2_bt0.attachPush(p2_bt0_Press, &p2_bt0 );
  p2_bt1.attachPush(p2_bt1_Press, &p2_bt1 );
  p3_bt0.attachPush(p3_bt0_Press, &p3_bt0 );
  p4_bt0.attachPush(p4_bt0_Press, &p4_bt0 );
  p5_bt0.attachPush(p5_bt0_Press, &p5_bt0 );
  p6_bt0.attachPush(p6_bt0_Press, &p6_bt0 );
  p7_bt0.attachPush(p7_bt0_Press, &p7_bt0 );
  p8_bt0.attachPush(p8_bt0_Press, &p8_bt0 );
  p9_bt0.attachPush(p9_bt0_Press, &p9_bt0 );
  p1.show ();
  delay (1000);
}

void pantalla_loop (){
    nexLoop(nex_listen_list);
}
