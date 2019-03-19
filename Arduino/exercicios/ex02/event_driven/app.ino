#include "event_driven.h"
#include "app.h"
#include "pindefs.h"

unsigned int ledValue = 0;
unsigned short int ledTime = 500;

void appinit(void) {
  pinMode(LED1,OUTPUT);
  digitalWrite(LED1, LOW);
  button_listen(BUTTON1);
  button_listen(BUTTON2);
  timer_set(0,ledTime);
  
  
}


void button_changed(int p, int v) { 
  if ( p == BUTTON1 && v == LOW) {     
      ledTime += 250;
  }
  if ( p == BUTTON2 && v == LOW) {     
      ledTime -= 250;
  } 
}


void timer_expired(void) {
  ledValue = !ledValue;
  digitalWrite(LED1, ledValue);
  timer_set(0,ledTime);
}
