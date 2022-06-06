#ifndef _MEMORIA_H
#define _MEMORIA_H

void i2cInit(void); 
void startC(void);
void stopC(void);
void clkPulse(void);
void checkAkB(void);
void writeByte(unsigned char dados);
unsigned int readByte(void);
void MEMwrite(unsigned char addr1, unsigned char addr2, unsigned int dados);
unsigned char MEMread(unsigned char addr1, unsigned char addr2);

#endif	// _MEMORIA_H