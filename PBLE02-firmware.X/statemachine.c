#include "statemachine.h"
#include "var.h"
#include "menu.h"
#include "Utils.h"

void initSM(){
    uint8_t s = getState();
    s = s%STATES_END;
    setState(s);
    initDisplay();
    
    
}

void updateSM(uint8_t btns, uint32_t m){
    states state = getState();
    
    switch(state){
        case ALARM1:
            if(bitRead(btns, 2)){
                setState(HIGH_ALARM1);
            }
            if(bitRead(btns, 0)){
                setState(ALARM2);
            }
            if(bitRead(btns, 1)){
                setState(LANGUAGE);
            }
            
            break;
            
        case HIGH_ALARM1:
            //MENU CHANGE
            if(bitRead(btns, 1) || bitRead(btns, 0)){
                setState(LOW_ALARM1);
            }
            
            if(bitRead(btns, 2)){
                setState(ALARM1);
            }
            //MENU CHANGE
            
            //LIMITS CONFIG
            if(bitRead(btns, 3)){
                setAlarmHigh1(getAlarmHigh1()+10);
            }
            if(bitRead(btns, 4)){
                setAlarmHigh1(getAlarmHigh1()-10);
            }
            //LIMITS CONFIG
            break;
            
        case LOW_ALARM1:
            //MENU CHANGE
            if(bitRead(btns, 1) || bitRead(btns, 0)){
                setState(HIGH_ALARM1);
            }
            
            if(bitRead(btns, 2)){
                setState(ALARM1);
            }
            //MENU CHANGE
            
            //LIMITS CONFIG
            if(bitRead(btns, 3)){
                setAlarmLow1(getAlarmLow1()+10);
            }
            if(bitRead(btns, 4)){
                setAlarmLow1(getAlarmLow1()-10);
            }
            //LIMITS CONFIG
            break;
            
        case ALARM2:
            if(bitRead(btns, 2)){
                setState(HIGH_ALARM2);
            }
            if(bitRead(btns, 0)){
                setState(TIME);
            }
            if(bitRead(btns, 1)){
                setState(ALARM1);
            }
            break;
            
        case HIGH_ALARM2:
            //MENU CHANGE
            if(bitRead(btns, 1) || bitRead(btns, 0)){
                setState(LOW_ALARM2);
            }
            
            if(bitRead(btns, 2)){
                setState(ALARM2);
            }
            //MENU CHANGE
            
            //LIMITS CONFIG
            if(bitRead(btns, 3)){
                setAlarmHigh2(getAlarmHigh2()+10);
            }
            if(bitRead(btns, 4)){
                setAlarmHigh2(getAlarmHigh2()-10);
            }
            //LIMITS CONFIG
            break;
            
        case LOW_ALARM2:
            //MENU CHANGE
            if(bitRead(btns, 1) || bitRead(btns, 0)){
                setState(HIGH_ALARM2);
            }
            
            if(bitRead(btns, 2)){
                setState(ALARM2);
            }
            //MENU CHANGE
            
            //LIMITS CONFIG
            if(bitRead(btns, 3)){
                setAlarmLow2(getAlarmLow2()+10);
            }
            if(bitRead(btns, 4)){
                setAlarmLow2(getAlarmLow2()-10);
            }
            //LIMITS CONFIG
            break;
            
        case TIME:
            if(bitRead(btns, 0)){
                setState(LANGUAGE);
            }
            if(bitRead(btns, 1)){
                setState(ALARM2);
            }
            
            if(bitRead(btns, 2)){
                setState(SET_TIMER);
            }
            
            break;
            
        case SET_TIMER:
            if(bitRead(btns, 2)){
                setState(TIME);
            }
            
            if(bitRead(btns, 3)){
                setTimer(m + 5000);
            }
            if(bitRead(btns, 4)){
                setTimer(m > 5000 ? m - 5000 : 0);
            }
            
            break;
            
        case LANGUAGE:
            if(bitRead(btns, 0)){
                setState(ALARM1);
            }
            if(bitRead(btns, 1)){
                setState(TIME);
            }
            
            if(bitRead(btns, 3) || bitRead(btns, 4)){
                setLanguage(getLanguage() ? 0 : 1);
            }
            
            break;
    }
    
    updateDisplayMenu(m);
}
