/* 
 * File:   menu.h
 * Author: derso
 *
 * Created on June 17, 2022, 11:13 PM
 */
#ifndef MENU_H
#define	MENU_H

#include "statemachine.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void initDisplay(void);
    
    void updateDisplayMenu(uint32_t m);
    
    void updateDisplayData(uint32_t m);
    void updateDisplayLimits();
#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

