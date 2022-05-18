/* 
 * File:   keyboard.h
 * Author: derso
 *
 * Created on May 18, 2022, 1:14 PM
 */

#ifndef KEYBOARD_H
#define	KEYBOARD_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#include "mcc_generated_files/system.h"

    const uint16_t keys[6] = {
        0, 918, 1511, 2208, 2940, 3691
    };

    uint32_t btns = 0;
    uint32_t cnt = 0;
    uint32_t lstChangeSW = 0;
    uint32_t keySum = 0;
    
#define NSAMPLES_2P_SW 5 //MAX 20
#define TIMECHANGE 5 //millisegundos
    
    uint8_t getButtons(){ return ((btns & 0x7C00) >> 10); }
    
    void updateButtons(uint32_t m);
    


#ifdef	__cplusplus
}
#endif

#endif	/* KEYBOARD_H */

