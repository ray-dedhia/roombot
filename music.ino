#include "SD.h"
#define SD_ChipSelectPin 8
#include "TMRpcm.h"
#include "SPI.h"
#include "IRremote.h" //include the library

TMRpcm tmrpcm;
int receiver = 2;
IRrecv irrecv(receiver); //create a new instance of receiver
decode_results results;


void setup(){
  Serial.println("setup0");
tmrpcm.speakerPin = 9;
Serial.begin(9600);
Serial.println("setup");



//irrecv.enableIRIn(); //start the receiver
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
//return;

}
else {
 Serial.println("SD loadded"); 
}

tmrpcm.setVolume(3);

tmrpcm.play("song2.wav");
Serial.print("hello world");
}


//PIN



void loop() {
 if (irrecv.decode(&results)) { //we have received an IR
 Serial.println (results.value, HEX); //display HEX
 irrecv.resume(); //next value
 } 
 //Serial.println(analogRead(3));
 }

