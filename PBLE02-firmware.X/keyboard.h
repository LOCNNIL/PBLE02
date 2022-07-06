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

#define NSAMPLES_2P_SW 5 //MAX 20
#define TIMECHANGE 5 //millisegundos
    
    uint8_t getButtons();
    
    void updateButtons(uint32_t m);
    


#ifdef	__cplusplus
}
#endif

#endif	/* KEYBOARD_H */

