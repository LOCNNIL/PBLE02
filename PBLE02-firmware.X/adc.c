#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/system.h"
#define POTSAMPLES 10

uint16_t readPOTADC(void){
    uint32_t potSum = 0;
    for(uint8_t i = 0; i < (1 << POTSAMPLES); i++){
        ADC1_Enable();
        ADC1_ChannelSelect(POT);
        ADC1_SoftwareTriggerEnable();
        ADC1_SoftwareTriggerDisable();
        while(!ADC1_IsConversionComplete(POT));
        potSum += ADC1_ConversionResultGet(POT);
        ADC1_Disable();
    }
    return (uint16_t)(potSum >> POTSAMPLES);
}
