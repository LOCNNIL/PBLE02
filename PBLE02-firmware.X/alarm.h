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
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* ALARM_H */

