/* 
 * File:   Utils.h
 * Author: derso
 *
 * Created on 25 de Julho de 2021, 12:13
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

    #define bitRead(value, bit) (((value) >> (bit)) & 0x01)
    #define bitSet(value, bit) ((value) |= (1UL << (bit)))
    #define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
    #define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
    
    uint32_t millis = 0;
    void *timer1(){ millis++; }
    
    void delay_ms(unsigned long ms);
    void delay_us(unsigned long us);
    void delay_ns(unsigned long ns);

    
#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

