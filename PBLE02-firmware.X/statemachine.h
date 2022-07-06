/* 
 * File:   statemachine.h
 * Author: derso
 *
 * Created on June 17, 2022, 11:38 PM
 */

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/system.h"
    
    enum states{
        ALARM1,
        HIGH_ALARM1,
        LOW_ALARM1,
        ALARM2,
        HIGH_ALARM2,
        LOW_ALARM2,
        TIME,
        LANGUAGE
    };
    
    void initSM(void);
    
    void updateSM(uint8_t btns);
  
#ifdef	__cplusplus
}
#endif

#endif	/* STATEMACHINE_H */

