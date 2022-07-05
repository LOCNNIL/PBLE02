/* 
 * File:   alarm.h
 * Author: derso
 *
 * Created on 4 de Julho de 2022, 17:20
 */

#include "var.h"

#ifndef ALARM_H
#define	ALARM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    void initAlarms(void);
    uint8_t updateAlarmsStatus(void);
    void updateAlarmHigh1(uint16_t high){ setAlarmHigh1(high); }
    void updateAlarmLow1(uint16_t low){ setAlarmLow1(low); }
    
    void updateAlarmHigh2(uint16_t high){ setAlarmHigh2(high); }
    void updateAlarmLow2(uint16_t low){ setAlarmLow2(low); }
    
    void updateAlarmTimer(uint32_t timer){ setAlarmHigh1(timer); }
    
    
    uint8_t timerSet;

#ifdef	__cplusplus
}
#endif

#endif	/* ALARM_H */

