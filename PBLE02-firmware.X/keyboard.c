#include "keyboard.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/adc1.h"
#include "Utils.h"

void updateButtons(uint32_t m){
    
    ADC1_Enable();
    ADC1_ChannelSelect(SW);
    ADC1_SoftwareTriggerEnable();
    ADC1_SoftwareTriggerDisable();
    while(!ADC1_IsConversionComplete(SW));
    keySum += ADC1_ConversionResultGet(SW);
    ADC1_Disable();
    cnt++;
    if(cnt < (1 << NSAMPLES_2P_SW)) return;
    keySum = keySum / cnt;
    cnt = 0;
    
    for(uint8_t i = 0; i < 5; i++){
        bitWrite(btns, i, keySum > keys[i] && keySum < keys[i + 1]);
        if(bitRead(btns, i) != bitRead(btns, i + 5)){
            bitWrite(btns, i + 5, bitRead(btns, i));
            lstChangeSW = m;
            bitClear(btns, 15);
        }
    }
    
    if(!bitRead(btns, 15)){
        if(lstChangeSW - m > TIMECHANGE){
            btns = (btns & 0x83FF) + ((btns & 0x03E0) << 5);
            bitSet(btns,15);
        }
    }
    
    keySum = 0;
}
