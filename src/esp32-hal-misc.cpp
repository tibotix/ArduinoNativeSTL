
#include "esp32-hal-misc.h"


float temperatureRead()
{
    return ESP_TEMPERATURE;
}


#if CONFIG_AUTOSTART_ARDUINO

extern TaskHandle_t loopTaskHandle;
extern bool loopTaskWDTEnabled;

void enableLoopWDT(){
}

void disableLoopWDT(){
}

void feedLoopWDT(){
}
#endif

void enableCore0WDT(){
}

void disableCore0WDT(){
}

#ifndef CONFIG_FREERTOS_UNICORE
void enableCore1WDT(){
}

void disableCore1WDT(){
}
#endif


unsigned long micros()
{
    ASSERT_NOT_REACHED("micros");
}

unsigned long millis()
{
    ASSERT_NOT_REACHED("millis");
}

void delay(uint32_t ms)
{
    ASSERT_NOT_REACHED("delay");
}

void delayMicroseconds(uint32_t us)
{
    uint32_t m = micros();
    if(us){
        uint32_t e = (m + us);
        if(m > e){ //overflow
            while(micros() > e){
                NOP();
            }
        }
        while(micros() < e){
            NOP();
        }
    }
}

void initArduino()
{
}

//used by hal log
const char * pathToFileName(const char * path)
{
    size_t i = 0;
    size_t pos = 0;
    char * p = (char *)path;
    while(*p){
        i++;
        if(*p == '/' || *p == '\\'){
            pos = i;
        }
        p++;
    }
    return path+pos;
}

