#include "keyboard.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/adc1.h"
#include "Utils.h"


const uint16_t keys[6] = {
    0, 918, 1511, 2208, 2940, 3691
};

uint32_t key_btns = 0;
uint32_t key_cnt = 0;
uint32_t key_lstChangeSW = 0;
uint32_t keySum = 0;

void updateButtons(uint32_t m){
    
    ADC1_Enable();
    ADC1_ChannelSelect(SW);
    ADC1_SoftwareTriggerEnable();
    ADC1_SoftwareTriggerDisable();
    while(!ADC1_IsConversionComplete(SW));
    keySum += ADC1_ConversionResultGet(SW);
    ADC1_Disable();
    key_cnt++;
    if(key_cnt < (1 << NSAMPLES_2P_SW)) return;
    keySum = keySum >> NSAMPLES_2P_SW;
    key_cnt = 0;
    
    for(uint8_t i = 0; i < 5; i++){
        bitWrite(key_btns, i, keySum > keys[i] && keySum < keys[i + 1]);
        if(bitRead(key_btns, i) != bitRead(key_btns, i + 5)){
            bitWrite(key_btns, i + 5, bitRead(key_btns, i));
            key_lstChangeSW = m;
            bitClear(key_btns, 15);
        }
    }
    
    if(!bitRead(key_btns, 15)){
        if(key_lstChangeSW - m > TIMECHANGE){
            key_btns = (key_btns & 0x83FF) + ((key_btns & 0x03E0) << 5);
            bitSet(key_btns,15);
        }
    }
    
    keySum = 0;
}

uint8_t getButtons(){
    return ((key_btns & 0x7C00) >> 10);
}