#include "keypad.h"
#include "mcc_generated_files/adc1.h"

unsigned int ADvalor;

unsigned int kpRead(void) {
    ADC1_ChannelSelect(Teclado);
    ADC1_Start();
    //Provide Delay
    for(int i=0;i <1000;i++)
    {
    }
    ADC1_Stop();
    while(!ADC1_IsConversionComplete())
    {
        ADC1_Tasks();   
    }
    ADvalor = ADC1_ConversionResultGet();
    
    
    return ADvalor;
}


//void kpInit(void) {
//    TRISB = 0xff; //quatro entradas e quatro saidas
//    TRISD = 0x00;
//    
//    BitClr(INTCON2, 7); //liga pull up
//    ADCON1 = 0b00001110; //apenas AN0 é analogico, a referencia é baseada na fonte
//
//}