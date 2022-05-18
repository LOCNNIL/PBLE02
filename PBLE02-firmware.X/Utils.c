#include "Utils.h"
#include "mcc_generated_files/system.h"

void delay_ms(unsigned long ms){
    volatile unsigned int l = 0;
    for(unsigned long i = 0; i < ms; i++)
        for(l=0; l < 226; l++);
}

void delay_us(unsigned long us){
    volatile unsigned int l = 0;
    for(l = 0; l < us/4; l++);
}
