#include "serialCom.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart1.h"
#include "var.h"
#include "menu.h"
#include "lcd.h"
#include "Utils.h"

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
    UART1_Write('\n');
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

            setTimer(vl*1000+m);
            
            break;
            
        case 'L':
            if(read[7] == 'P'){
                setLanguage(0);
            }else if(read[7] == 'E'){
                setLanguage(1);
            }
            break;
    }
    updateSM(0, m);
    
    
}

static uint8_t lstAS = 0;

const char msgAlarm[5][2][19] = {
    {
        "ALARME 1 BAIXO em ",
        "ALARM 1 LOW in "
    },
    {
        "ALARME 1 ALTO em ",
        "ALARM 1 HIGH in "
    },
    {
        "ALARME 2 BAIXO em ",
        "ALARM 2 LOW in "
    },
    {
        "ALARME 2 ALTO em ",
        "ALARM 2 HIGH in "
    },
    {
        "TEMPORIZADOR em ",
        "TIMER in "
    }
};

void seriaAlarm(uint8_t a, uint32_t m){
    
    uint8_t l = getLanguage()%2;
    
    while(!UART1_IsTxReady());
    
    if(bitRead(a, 0) != bitRead(lstAS, 0) && bitRead(a, 0)){
        uint8_t i = 0;
        while(msgAlarm[0][l][i] != 0){
            UART1_Write(msgAlarm[0][l][i]);
            i++;
        }
        UART1_Write(((m / 1000)/1000) % 10 + 48);
        UART1_Write(((m / 1000)/100) % 10 + 48);
        UART1_Write(((m / 1000)/10) % 10 + 48);
        UART1_Write(((m / 1000)/1) % 10 + 48);
        UART1_Write('\n');
    }
    
    if(bitRead(a, 1) != bitRead(lstAS, 1) && bitRead(a, 1)){
        uint8_t i = 0;
        while(msgAlarm[1][l][i] != 0){
            UART1_Write(msgAlarm[1][l][i]);
            i++;
        }
        UART1_Write(((m / 1000)/1000) % 10 + 48);
        UART1_Write(((m / 1000)/100) % 10 + 48);
        UART1_Write(((m / 1000)/10) % 10 + 48);
        UART1_Write(((m / 1000)/1) % 10 + 48);
        UART1_Write('\n');
    }
    
    if(bitRead(a, 2) != bitRead(lstAS, 2) && bitRead(a, 2)){
        uint8_t i = 0;
        while(msgAlarm[2][l][i] != 0){
            UART1_Write(msgAlarm[2][l][i]);
            i++;
        }
        UART1_Write(((m / 1000)/1000) % 10 + 48);
        UART1_Write(((m / 1000)/100) % 10 + 48);
        UART1_Write(((m / 1000)/10) % 10 + 48);
        UART1_Write(((m / 1000)/1) % 10 + 48);
        UART1_Write('\n');
    }
    
    if(bitRead(a, 3) != bitRead(lstAS, 3) && bitRead(a, 3)){
        uint8_t i = 0;
        while(msgAlarm[3][l][i] != 0){
            UART1_Write(msgAlarm[3][l][i]);
            i++;
        }
        UART1_Write(((m / 1000)/1000) % 10 + 48);
        UART1_Write(((m / 1000)/100) % 10 + 48);
        UART1_Write(((m / 1000)/10) % 10 + 48);
        UART1_Write(((m / 1000)/1) % 10 + 48);
        UART1_Write('\n');
    }
    
    if(bitRead(a, 4) != bitRead(lstAS, 4) && bitRead(a, 4)){
        uint8_t i = 0;
        while(msgAlarm[4][l][i] != 0){
            UART1_Write(msgAlarm[4][l][i]);
            i++;
        }
        UART1_Write(((m / 1000)/1000) % 10 + 48);
        UART1_Write(((m / 1000)/100) % 10 + 48);
        UART1_Write(((m / 1000)/10) % 10 + 48);
        UART1_Write(((m / 1000)/1) % 10 + 48);
        UART1_Write('\n');
    }
    lstAS=a;
}