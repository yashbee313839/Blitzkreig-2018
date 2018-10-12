/*
 * IRremoteESP8266: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 Sept, 2015
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009, Copyright 2009 Ken Shirriff, http://arcfn.com
 */

#include <IRremoteESP8266.h>

int RECV_PIN = 2; //an IR detector/demodulatord is connected to GPIO pin 2
int val,del,prev_del= 0 ;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  del = millis();
  if (irrecv.decode(&results) ) {
    
   // Serial.println(results.value, HEX);
    val = results.value;
    if(val == 0x12345678){
    Serial.print(val);
    Serial.print("  ");
    Serial.println(del-prev_del);}
    irrecv.resume(); // Receive the next value
    prev_del = del;
    
  }
  delay(100);
}
