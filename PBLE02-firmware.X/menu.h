/* 
 * File:   menu.h
 * Author: derso
 *
 * Created on June 17, 2022, 11:13 PM
 */
#include "statemachine.h"
#include "mcc_generated_files/system.h"
#ifndef MENU_H
#define	MENU_H

#ifdef	__cplusplus
extern "C" {
#endif

    void updateDisplay(uint8_t STATE);

    char menus[6][2][32] = {
        {
            "TESTE1",
            "TESTE2"
        },
        {
            "TESTE3",
            "f"
        },
        {
            "a",
            "b"
        },
        {
            "c",
            "d"
        },
        {
            "e",
            "f"
        },
        {
            "g",
            "h"
        },
    };
    
#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

