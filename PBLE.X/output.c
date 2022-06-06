#include "output.h"
#include "lcd.h"
#include "stateMachine.h"
#include "var.h"
#include "adc.h"
#include "mcc_generated_files/uart1.h"
#include "stateMachine.h"
#include <stdio.h>

#define NUM_IDIOMAS 2

unsigned int aux = 0, piscaValorAlarm = 0;

//msgs com 16 caracteres
//1 msg por estado (apenas linha de cima)
static char * msgs[11][NUM_IDIOMAS] = {
    {"<<    Menu    >>", "<<    Menu    >>"},
    {"< Baixo | Alto  ", "<  Low  | High   "},
    {"<<    Menu    >>", "<<    Menu    >>"},
    {"< Baixo | Alto  ", "<  Low  | High   "},
    {"<<    Menu    >>", "<<    Menu    >>"},
    {"<    Tempo      ", "<     Time      "},
    {"<<    Menu    >>", "<<    Menu    >>"},
    {"<    Idioma     ", "<    Language   "},
    {"    Alarme 1    ", "     Alarm 1    "},
    {"    Alarme 2    ", "     Alarm 2    "},
    {"  Alarme 1 e 2  ", "   Alarm 1 e 2  "}
};

//1 msg por estado (apenas linha debaixo )
static char * msgs2[9][NUM_IDIOMAS] = {
    {" Alarme 1: ", " Alarm 1 : "},
    {"                ", "                "},
    {" Alarme 2: ", " Alarm 2 : "},
    {"                ", "                "},
    {"     Tempo      ", "      Time      "},
    {"                ", "                "},
    {"     Idioma     ", "    Language    "},
    {"    Portugues   ", "     English    "},
    {"    acionado    ", "    triggered   "}
};

void outputInit(void) {
    lcdInit(); // realiza a inicialização do display LCD
}

void outputPrint(int numTela, int idioma) {
    // caso os valores analógicos adcRead1 e adcRead2, que por sua vez representam o alarme 1 e alarme 2
    // respectivamente, estejam dentro da faixa de trabalho, isto é, acima do nível minímo e abaixo do nível
    // máximo, o programa segue com a exibição de mensagens para cada estado   
    if(verificaAlarme() == 0)
    {
        if (numTela == STATE_ALARME_1_MENU) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);                    
            lcdCommand(0xC0);
            lcdString(msgs2[numTela][idioma]);
            lcdInt(adcRead1());

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String(msgs2[numTela][idioma]);
                UART1_Write((adcRead1()/100 + '0'));
                UART1_Write(((adcRead1()/10)%10 + '0'));
                UART1_Write((adcRead1()%10 + '0'));
                UART1_Write(13);
            }
        }
        if (numTela == STATE_ALARME_1) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);
            lcdCommand(0xC0);
            lcdString("  ");
            piscaValorAlarm++;
            if(getAlarm_Low_High() == 0) //alarme baixo
            {
                if(piscaValorAlarm == 1) // pisca o valor do alarme
                {
                    lcdInt(getAlarmLevelLow1());
                }
                else
                {
                    lcdString("    ");
                    piscaValorAlarm = 0;
                }
                lcdString("  | ");
                lcdInt(getAlarmLevelHigh1());
                lcdString(" ");
            }
            if(getAlarm_Low_High() == 1) //alrme alto
            {    
                lcdInt(getAlarmLevelLow1());
                lcdString("  | ");
                if(piscaValorAlarm == 1) // pisca o valor do alarme
                {
                    lcdInt(getAlarmLevelHigh1());
                }
                else
                {
                    lcdString("    ");
                    piscaValorAlarm = 0;
                }
                lcdString(" ");
            }

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String("  ");
                UART1_Write((getAlarmLevelLow1()/100 + '0'));
                UART1_Write(((getAlarmLevelLow1()/10)%10 + '0'));
                UART1_Write((getAlarmLevelLow1()%10 + '0'));
                UART1_Write_String("  | ");
                UART1_Write((getAlarmLevelHigh1()/100 + '0'));
                UART1_Write(((getAlarmLevelHigh1()/10)%10 + '0'));
                UART1_Write((getAlarmLevelHigh1()%10 + '0'));
                UART1_Write_String("    ");
                UART1_Write(13);
            }
        }
        if (numTela == STATE_ALARME_2_MENU) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);

            lcdCommand(0xC0);
            lcdString(msgs2[numTela][idioma]);
            lcdInt(adcRead2());

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String(msgs2[numTela][idioma]);
                UART1_Write((adcRead2()/100 + '0'));
                UART1_Write(((adcRead2()/10)%10 + '0'));
                UART1_Write((adcRead2()%10 + '0'));
                UART1_Write(13);
            }            
        }
        if (numTela == STATE_ALARME_2) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);
            lcdCommand(0xC0);
            lcdString("  ");
            piscaValorAlarm++;
            if(getAlarm_Low_High() == 0) //alarme baixo
            {
                if(piscaValorAlarm == 1) // pisca o valor do alarme
                {
                    lcdInt(getAlarmLevelLow2());
                }
                else
                {
                    lcdString("    ");
                    piscaValorAlarm = 0;
                }
                lcdString("  | ");
                lcdInt(getAlarmLevelHigh2());
                lcdString(" ");
            }
            if(getAlarm_Low_High() == 1) //alrme alto
            {    
                lcdInt(getAlarmLevelLow2());
                lcdString("  | ");
                if(piscaValorAlarm == 1) // pisca o valor do alarme
                {
                    lcdInt(getAlarmLevelHigh2());
                }
                else
                {
                    lcdString("    ");
                    piscaValorAlarm = 0;
                }
                lcdString(" ");
            }

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String("  ");
                UART1_Write((getAlarmLevelLow2()/100 + '0'));
                UART1_Write(((getAlarmLevelLow2()/10)%10 + '0'));
                UART1_Write((getAlarmLevelLow2()%10 + '0'));
                UART1_Write_String("  | ");
                UART1_Write((getAlarmLevelHigh2()/100 + '0'));
                UART1_Write(((getAlarmLevelHigh2()/10)%10 + '0'));
                UART1_Write((getAlarmLevelHigh2()%10 + '0'));
                UART1_Write_String("    ");
                UART1_Write(13);
            }
        }
        if (numTela == STATE_TEMPO_MENU) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);
            lcdCommand(0xC0);
            lcdString(msgs2[numTela][idioma]);

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String(msgs2[numTela][idioma]);
                UART1_Write(13);
            }
        }
        if (numTela == STATE_TEMPO) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);
            lcdCommand(0xC0);
            lcdString("      ");
            lcdInt(getTime());
            lcdString("      ");

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String("      ");
                UART1_Write((getTime()/100 + '0'));
                UART1_Write(((getTime()/10)%10 + '0'));
                UART1_Write((getTime()%10 + '0'));
                UART1_Write_String("      ");
                UART1_Write(13);
            }
        }
        if (numTela == STATE_IDIOMA_MENU) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);
            lcdCommand(0xC0);
            lcdString(msgs2[numTela][idioma]);

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String(msgs2[numTela][idioma]);
                UART1_Write(13);
            }
        }
        if (numTela == STATE_IDIOMA) 
        {
            lcdCommand(0x80);
            lcdString(msgs[numTela][idioma]);
            lcdCommand(0xC0);
            lcdString(msgs2[numTela][idioma]);

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[numTela][idioma]);
                UART1_Write(13);
                UART1_Write_String(msgs2[numTela][idioma]);
                UART1_Write(13);
            }            
        }
    }
    else
    {
        // caso os valores analógicos adcRead1 e adcRead2, que por sua vez representam o alarme 1 e alarme 2
        // respectivamente, estejam fora da faixa de trabalho, isto é, abaixo do nível minímo e acima do nível
        // máximo, o programa fica travado num loop infinito, até que amboso valores lidos estejam dentro 
        // da sua faixa de operação.
        // caso haja anormalidade, ou seja, um ou ambos os sensores estejam fora da faixa de trabalho, haverá
        // indicações para todos os casos
        // sensor 1 abaixo do nível minímo ou sensor 1 acima do nível máximo
        if (verificaAlarme() == 1) 
        {
            lcdCommand(0x80);
            lcdString(msgs[8][idioma]);
            lcdCommand(0xC0);
            lcdString(msgs2[8][idioma]);

            if(!UART1_IsRxReady())
            {
            UART1_Write_String(msgs[8][idioma]);
            UART1_Write(13);
            UART1_Write_String(msgs2[8][idioma]);
            UART1_Write(13);
            }
        }
        // sensor 2 abaixo do nível minímo ou sensor 2 acima do nível máximo
        if (verificaAlarme() == 2) 
        {
            lcdCommand(0x80);
            lcdString(msgs[9][idioma]);
            lcdCommand(0xC0);
            lcdString(msgs2[8][idioma]);

            if(!UART1_IsRxReady())
            {
            UART1_Write_String(msgs[9][idioma]);
            UART1_Write(13);
            UART1_Write_String(msgs2[8][idioma]);
            UART1_Write(13);
            }
        }    
        // sensor 1 e 2 acionados
        if (verificaAlarme() == 3) 
        {
            lcdCommand(0x80);
            lcdString(msgs[10][idioma]);
            lcdCommand(0xC0);
            lcdString(msgs2[8][idioma]);

            if(!UART1_IsRxReady())
            {
                UART1_Write_String(msgs[10][idioma]);
                UART1_Write(13);
                UART1_Write_String(msgs2[8][idioma]);
                UART1_Write(13);
            }
        } 
    }
}

