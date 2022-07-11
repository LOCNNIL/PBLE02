#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "lcd.h"
#include "Utils.h"
#include "statemachine.h"
#include "alarm.h"
#include "menu.h"
#include "keyboard.h"
#include "serialCom.h"

void *timer1(){
    millis++;
}

uint32_t lstTimeDataUp = 0;
#define DT_Period 200

uint32_t lstAlarm = 0;
#define Alarm_Period 150
uint8_t lstStatus = 0;

uint32_t lstTimeKEY = 0;
#define KEY_Period 10
uint8_t lstBtn = 0;
uint8_t btns = 0;

int main(void){
    // initialize the device
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(timer1);
    
    LED1_SetHigh();
    LED2_SetHigh();
    LED3_SetHigh();
    LED4_SetHigh();
    
    //setLanguage(0);
    
    initSerial();
    initAlarms();
    initSM();
    updateSM(0, millis);
    for(;;){
        
        serialUpdate(millis);
        
        updateButtons(millis);
        btns = getButtons();
        if(lstBtn != btns){
            lstBtn = btns;
            updateSM(btns, millis);
            updateDisplayLimits();
        }
        
        if(millis - lstAlarm >= Alarm_Period){
            lstAlarm = millis;
            
            uint8_t alarmStatus = updateAlarmsStatus();
            if(lstStatus != alarmStatus){
                lstStatus = alarmStatus;
                if(bitRead(alarmStatus, 0)){
                    if(bitRead(alarmStatus, 1))LED2_SetLow();
                    if(!bitRead(alarmStatus, 1))LED1_SetLow();
                }else{
                    LED1_SetHigh();
                    LED2_SetHigh();
                }
                
                if(bitRead(alarmStatus, 2)){
                    if(bitRead(alarmStatus, 3))LED4_SetLow();
                    if(!bitRead(alarmStatus, 3))LED3_SetLow();
                }else{
                    LED3_SetHigh();
                    LED4_SetHigh();
                }
                
            }
        }
        
        if(millis - lstTimeDataUp >= DT_Period){
            lstTimeDataUp = millis;
            
            updateDisplayData(millis);
            
        }
    }
    
    return 1; 
}