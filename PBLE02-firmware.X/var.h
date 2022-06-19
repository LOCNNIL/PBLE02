/* 
 * File:   var.h
 * Author: derso
 *
 * Created on June 18, 2022, 12:03 AM
 */

#ifndef VAR_H
#define	VAR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/system.h"
    
    uint8_t getState(void);
    void setState(uint8_t state);
    
    uint16_t getAlarmHigh1(void);
    void setAlarmHigh1(uint16_t alarmHigh1);

    uint16_t getAlarmLow1(void);
    void setAlarmLow1(uint16_t alarmLow1);

    uint16_t getAlarmHigh2(void);
    void setAlarmHigh1(uint16_t alarmHigh2);

    uint16_t getAlarmLow2(void);
    void setAlarmLow1(uint16_t alarmLow2);
#ifdef	__cplusplus
}
#endif

#endif	/* VAR_H */

