#include "lcd.h"
#include "menu.h"

void updateDisplay(uint8_t STATE){
    
    lcdCommand(1);
    
    switch(STATE){
        case HIGH_ALARM1:
        for(uint8_t i = 0; i < 16; i++){
            lcdChar(menus[HIGH_ALARM1][0][i]);
        }
        lcdCommand(0xC0);
        for(uint8_t i = 0; i < 16; i++){
            lcdChar(menus[HIGH_ALARM1][0][i+16]);
        }
            
            break;
        
        case LOW_ALARM1:
            
            break;
        
        case HIGH_ALARM2:
            
            break;
        
        case LOW_ALARM2:
            
            break;
        
        case TIME:
            
            break;
        
        case LANGUAGE:
            
            break;
    }
    
}
