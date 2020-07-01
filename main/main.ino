#include <ESP8266WiFiMulti.h>
#include <Thread.h>
#include "counter.h"

Thread check_thread = Thread();
Thread update_thread = Thread();

Counter counter_1(5);
Counter counter_2(4);

void checkCounters()
{
  counter_1.getValue();
  counter_2.getValue();
}

void updateCounters()
{
  counter_1.update();
  counter_2.update();
}

void setup() {
  Serial.begin(115200);

  setupWifi();

  check_thread.setInterval(1000);
  check_thread.onRun(&checkCounters);
  
  update_thread.setInterval(10);
  update_thread.onRun(&updateCounters);
}


void loop() {
  if(check_thread.shouldRun()){
    check_thread.run();
  }
  if(update_thread.shouldRun()){
    update_thread.run();
  }
  delay(5);
}
