#include "serialCom.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart1.h"
#include "var.h"
#include "menu.h"
#include "lcd.h"

#define startCommand '$'
#define commandSize 8


void initSerial(void){
    UART1_Initialize();
}


void serialUpdate(uint32_t m){
    
    uint8_t a = 0;
    uint8_t readIndex = 0;
    
    char read[commandSize];
    
    if(UART1_IsRxReady())
        delay_ms(10);
    
    while(UART1_IsRxReady()){
        if(readIndex < commandSize)
            read[readIndex] = UART1_Read();
        readIndex++;
        a = 1;
    }
    if(!a) return;
    
    
    if(readIndex != commandSize)
        return;
    
    if(read[0] != startCommand)
        return;
    
    
    for(uint8_t i = 0; i < commandSize; i++)
        UART1_Write(read[i]);
    uint32_t vl;
    
    switch(read[1]){
        case 'A':
            
            vl = (read[4]-48)*1000 + (read[5]-48)*100 + (read[6]-48)*10 + (read[7]-48);
            
            if(read[2] == 'H'){
                if(read[3] == '1'){
                    setAlarmHigh1(vl);
                }else if(read[3] == '2'){
                    setAlarmHigh2(vl);
                }
            }else if(read[2] == 'L'){
                if(read[3] == '1'){
                    setAlarmLow1(vl);
                }else if(read[3] == '2'){
                    setAlarmLow2(vl);
                }
            }
            
            break;
        
        case 'T':
            vl = (read[2]-48)*100000+(read[3]-48)*10000+(read[4]-48)*1000+(read[5]-48)*100+(read[6]-48)*10+(read[7]-48);
            //lcdCommand(0x80);
            //lcdUInt32(vl);
            setTimer(vl*1000+m);
            
            break;
            
        case 'L':
            if(read[7] == 'P'){
                setTimer(0);
            }else if(read[7] == 'E'){
                setTimer(1);
            }
            break;
    }
    updateSM(0, m);
    
    
}