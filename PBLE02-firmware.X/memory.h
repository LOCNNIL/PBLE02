/* 
 * File:   memory.h
 * Author: derso
 *
 * Created on June 16, 2022, 9:00 PM
 */

#ifndef MEMORY_H
#define	MEMORY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/i2c2.h"
    uint8_t writeMem(uint8_t address, uint8_t* pData, uint16_t ncount);
    uint8_t readMem(uint16_t address, uint8_t *pData, uint16_t nCount);

#ifdef	__cplusplus
}
#endif

#endif	/* MEMORY_H */

