#include "lcd.h"
#include "statemachine.h"
#include "mcc_generated_files/system.h"
#include "var.h"
#include "adc.h"
#include "menu.h"
#include "Utils.h"

const char menus[9][2][2][17] = {
    {
        {
            "<<  Alarme 1  >>",
            ""
        },
        {
            "<<  Alarm 1   >>",
            ""
        }
    },
    {
        {
            "|Alarme 1 Alto| ",
            "Alto: "
        },
        {
            " |High Alarm 1| ",
            "High: "
        }
    },

    {
        {
            "|Alarme 1 Baixo|",
            "Baixo: "
        },
        {
            " |Low Alarm 1|  ",
            "Low  : "
        }
    },

    {
        {
            "<<  Alarme 2  >>",
            ""
        },
        {
            "<<  Alarm 2   >>",
            ""
        }
    },
    {
        {
            "|Alarme 2 Alto|",
            "Alto: "
        },
        {
            " |High Alarm 2| ",
            "High: "
        }
    },
    {
        {
            "|Alarme 2 Baixo|",
            "Baixo: "
        },
        {
            " |Low Alarm 2|  ",
            "Low  : "
        }
    },
    {
        {
            "<<Temporizador>>",
            "Tempo: "
        },
        {
            "<<   Timer    >>",
            "Time : "
        }
    },
    {
        {
            "<<   Atraso  >>",
            "Tempo: "
        },
        {
            "<<   Delay    >>",
            "Time : "
        }
    },
    {
        {
            "<<   IDIOMA   >>",
            ""
        },
        {
            "<<  LANGUAGE  >>",
            ""
        }
    }
};

void initDisplay(void){
    lcdInit();
    lcdCommand(1);
}

void updateDisplayMenu(uint32_t m){
    states STATE = getState();
    uint8_t lang = getLanguage()%2;
    
    lcdCommand(1);
    
    lcdString(menus[(uint8_t)STATE][lang][0]);
    lcdCommand(0xC0);
    lcdString(menus[(uint8_t)STATE][lang][1]);
    
    switch(STATE){
        case ALARM1:
            
            lcdCommand(0xC0);
            lcdInt(getAlarmLow1());
            lcdString("|      |");
            lcdInt(getAlarmHigh1());
           
            break;
        
        case HIGH_ALARM1:
            //NOTHING
            break;
        
        case LOW_ALARM1:
            //NOTHING
            break;
        
        case ALARM2:
            lcdCommand(0xC0);
            lcdInt(getAlarmLow2());
            lcdString("|      |");
            lcdInt(getAlarmHigh2());
            break;
            
        case HIGH_ALARM2:
            //NOTHING
            break;
        
        case LOW_ALARM2:
            //NOTHING
            break;
        
        case TIME:
            
            break;
        
        case LANGUAGE:
            
            break;
    }
    updateDisplayData(m);
}

void updateDisplayData(uint32_t m){
    
    states STATE = getState();
    
    switch(STATE){
        case ALARM1:
            lcdCommand(0xC6);
            lcdInt(readPOTADC());
            break;
        
        
        case ALARM2:
            lcdCommand(0xC5);
            lcdString("      ");
            lcdCommand(0xC5);
            lcdInt(readDiff());
            break;
            
        
        case TIME:
            lcdCommand(0xC7);
            uint32_t t = getTimer();
            if(t > m)
                lcdUInt16((t-m)/1000);
            else lcdUInt16(0);
            //lcdUInt16(t);
            break;
        
        case LANGUAGE:
            lcdCommand(0xC0);
            if(!getLanguage()) lcdString("   Portugues");
            else lcdString("    English");
            break;
    }
}

void updateDisplayLimits(){
    
    states STATE = getState();
    
    switch(STATE){
    
        case HIGH_ALARM1:
            lcdCommand(0xC6);
            lcdInt(getAlarmHigh1());
            break;
        
        case LOW_ALARM1:
            lcdCommand(0xC6);
            lcdInt(getAlarmLow1());
            break;
            
        case HIGH_ALARM2:
            lcdCommand(0xC6);
            lcdInt(getAlarmHigh2());
            break;
        
        case LOW_ALARM2:
            lcdCommand(0xC6);
            lcdInt(getAlarmLow2());
            break;
            
        case SET_TIMER:
            lcdCommand(0xC7);
            lcdUInt16((getTimer())/1000);
            break;
    }
}