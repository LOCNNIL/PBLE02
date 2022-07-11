#include "Utils.h"
#include "mcc_generated_files/system.h"

void delay_ms(unsigned long ms){
    volatile unsigned int l = 0;
    for(unsigned long i = 0; i < ms; i++)
        for(l=0; l < 787; l++);
}

void delay_us(unsigned long us){
    volatile unsigned int l = 0;
    for(l = 0; l < (us*806)>>10; l++);
}

void delay_ns(unsigned long ns){
    volatile unsigned int l = 0;
    for(l = 0; l < (ns*825)>>20; l++);
}