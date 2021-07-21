#include "Arduino.h"

const char* msg = "cool";

int main(){
    Serial.println("Hello");
    Serial.printf("Hello there %s\n", msg);
    Serial.flush();
}