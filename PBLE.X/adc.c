#include "adc.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/pin_manager.h"
#include "var.h"

unsigned int i;

int adcRead1(void) {
    int ADvalor;

    ADC1_ChannelSelect(ANA_IN1);
    ADC1_Start();
    //Provide Delay
    for(i=0;i <1000;i++)
    {
    }
    ADC1_Stop();
    while(!ADC1_IsConversionComplete())
    {
        ADC1_Tasks();   
    }
    //ADvalor = ADC1_ConversionResultGet()/4;   
    ADvalor = 50; // Teste
    return ADvalor;
}

int adcRead2(void) {
    int ADvalor;
    ADC1_ChannelSelect(ANA_IN2);
    ADC1_Start();
    //Provide Delay
    for(i=0;i <1000;i++)
    {
    }
    ADC1_Stop();
    while(!ADC1_IsConversionComplete())
    {
        ADC1_Tasks();   
    }
    //ADvalor = ADC1_ConversionResultGet()/4;   
    ADvalor = 50; // Teste
    return ADvalor;
}

int adcPot(void) {
    int ADvalor;

    ADC1_ChannelSelect(Pot);
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
}

int verificaAlarme()
{
    //dentro dos níveis definidos nos alarmes 
    if ((adcRead1() > getAlarmLevelLow1()) && (adcRead2() > getAlarmLevelLow2()) && (adcRead1() < getAlarmLevelHigh1()) && (adcRead2() < getAlarmLevelHigh2())) 
    {
        PORTA0_SetHigh();
        PORTA1_SetHigh();
        return 0;
    }
    // sensor 1 abaixo do nível minímo ou sensor 1 acima do nível máximo
    else if(adcRead1() < getAlarmLevelLow1() || adcRead1() > getAlarmLevelHigh1())
    {
        PORTA0_SetLow();
        PORTA1_SetHigh();
        return 1;
    }
    // sensor 2 abaixo do nível minímo ou sensor 2 acima do nível máximo
    else if (adcRead2() < getAlarmLevelLow2() || adcRead2() > getAlarmLevelHigh2()) 
    {
        PORTA0_SetHigh();
        PORTA1_SetLow();
        return 2;
    }
    // ambos os alarmes são acionados
    else if(((adcRead1() < getAlarmLevelLow1()) && (adcRead2() < getAlarmLevelLow2())) || ((adcRead1() < getAlarmLevelLow1()) && (adcRead2() > getAlarmLevelHigh2())) || ((adcRead1() > getAlarmLevelHigh1()) && (adcRead2() > getAlarmLevelHigh2())) || ((adcRead1() > getAlarmLevelHigh1()) && (adcRead2() < getAlarmLevelLow2())))
    {
        PORTA0_SetLow();
        PORTA1_SetLow();
        return 3;
    }
}
