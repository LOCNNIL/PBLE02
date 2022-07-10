/* 
 * File:   adc.h
 * Author: derso
 *
 * Created on June 17, 2022, 1:41 PM
 */

#define POTSAMPLES 4
#define DIFSAMPLES 3
#include "mcc_generated_files/system.h"

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

    uint16_t readPOTADC(void);
    int readDiff(void);
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

