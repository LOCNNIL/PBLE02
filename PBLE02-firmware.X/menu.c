#include "lcd.h"
#include "statemachine.h"
#include "mcc_generated_files/system.h"
#include "var.h"
#include "adc.h"
//#include "menu.h"

const char menus[7][2][2][16] = {
    {
        {
            "<<  Alarme 1  >>",
            ""
        },
        {
            "<<   Alarm 1  >>",
            ""
        }
    },
    {
        {
            "  |Alarme Alto| ",
            "Alto: "
        },
        {
            "  |High Alarm|  ",
            "High: "
        }
    },

    {
        {
            "TESTE5",
            "TESTE6"
        },
        {
            "TESTE7",
            "TESTE8"
        }
    },

    {
        {
            "TESTE9",
            "TESTE10"
        },
        {
            "TESTE11",
            "TESTE12"
        }
    },
    {
        {
            "TESTE13",
            "TESTE14"
        },
        {
            "TESTE15",
            "TESTE16"
        }
    },
    {
        {
            "TESTE17",
            "TESTE18"
        },
        {
            "TESTE19",
            "TESTE20"
        }
    },
    {
        {
            "TESTE21",
            "TESTE22"
        },
        {
            "TESTE23",
            "TESTE24"
        }
    }
};

void initDisplay(void){
    lcdInit();
    lcdCommand(1);
}

void updateDisplayMenu(char STATE){
    
    lcdCommand(1);
    
    switch(STATE){
        case ALARM1:
            lcdString(menus[ALARM1][0][0]);
            lcdCommand(0xC0);
            lcdString(menus[ALARM1][0][1]);
            
            lcdCommand(0xC0);
            lcdInt(getAlarmLow1());
            lcdString("|      |");
            lcdInt(getAlarmHigh1());
            
            lcdCommand(0xC6);
            lcdInt(readPOTADC());
            break;
        
        case HIGH_ALARM1:
            lcdString(menus[HIGH_ALARM1][0][0]);
            lcdCommand(0xC0);
            lcdString(menus[HIGH_ALARM1][0][1]);
            
            
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

void updateDisplayData(char STATE){
    switch(STATE){
        case ALARM1:
            lcdCommand(0xC6);
            lcdInt(readPOTADC());
            break;
        
        case HIGH_ALARM1:
            
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
