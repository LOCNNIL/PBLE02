/* 
 * File:   serialCom.h
 * Author: derso
 *
 * Created on 11 de Julho de 2022, 11:19
 */

#ifndef SERIALCOM_H
#define	SERIALCOM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/system.h"
    
    void initSerial(void);
    void serialUpdate(uint32_t m);

#ifdef	__cplusplus
}
#endif

#endif	/* SERIALCOM_H */

