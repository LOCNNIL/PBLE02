#include "keypad.h"
#include "event.h"
#include "mcc_generated_files/uart1.h"
#include "var.h"

static unsigned int key_ant;
static unsigned char pos = 0; // posicao atual do buffer
static char buffer[8]; // buffer temporario
char valorLido;

//void eventInit(void) {
//    kpInit();
//    key_ant = 0;
//}

//Lê cada uma das teclas ? ? ? ? ENTER e registra em uma variável.

unsigned int eventRead(void) {
    int key;
    int ev = EV_NOEVENT;
    key = kpRead();

    valorLido = UART1_Read();
    if (valorLido != 0) 
    {
        UART1_Write(valorLido);
        if ((valorLido == 'D') || (valorLido == 'd')) 
        {
            ev = EV_RIGHT; 
        }
        else if ((valorLido == 'A') || (valorLido == 'a')) 
        {
            ev = EV_LEFT; 
        }
        else if ((valorLido == 'E') || (valorLido == 'e')) 
        {
            ev = EV_ENTER; 
        }
        else if ((valorLido == 'W') || (valorLido == 'w')) 
        {
            ev = EV_UP; 
        }
        else if ((valorLido == 'S') || (valorLido == 's')) 
        {
            ev = EV_DOWN; 
        }
        else
        {
            buffer [pos] = valorLido;
            pos ++;
            UART1_Write(pos + '0');
            if (buffer[0] == '!') 
            {               
                if(buffer[pos - 1] == '.')
                {
                    for(int i = 0; i < pos; i++)
                    {
                         UART1_Write(buffer[i]);
                    }
                    
                    if(buffer[1] == 'Z' && buffer[2] == '1' && buffer[3] == 'L') //alarme 1 low
                    {
                        int valor = (buffer[7] - '0') + (buffer[6] - '0')*10  + (buffer[5] - '0')*100 + (buffer[4] - '0')*1000;
                        setAlarmLevelLow1(valor);
                    }
                    if(buffer[1] == 'Z' && buffer[2] == '1' && buffer[3] == 'H') //alarme 1 high
                    {
                        int valor = (buffer[7] - '0') + (buffer[6] - '0')*10  + (buffer[5] - '0')*100 + (buffer[4] - '0')*1000;
                        setAlarmLevelHigh1(valor);
                    }
                    if(buffer[1] == 'Z' && buffer[2] == '2' && buffer[3] == 'L') //alarme 2 low
                    {
                        int valor = (buffer[7] - '0') + (buffer[6] - '0')*10  + (buffer[5] - '0')*100 + (buffer[4] - '0')*1000;
                        setAlarmLevelLow2(valor);
                    }
                    if(buffer[1] == 'Z' && buffer[2] == '2' && buffer[3] == 'H') //alarme 2 high
                    {
                        int valor = (buffer[7] - '0') + (buffer[6] - '0')*10  + (buffer[5] - '0')*100 + (buffer[4] - '0')*1000;
                        setAlarmLevelHigh2(valor);
                    }  
                    if(buffer[1] == 'P' && buffer[2] == 'T') // portugues
                    {
                        setLanguage(0);
                    }                 
                    if(buffer[1] == 'I' && buffer[2] == 'N') // ingles
                    {
                        setLanguage(1);
                    }
                    if(buffer[1] == 'T') // tempo de atraso do loop principal
                    {
                        int valor = (buffer[5] - '0') + (buffer[4] - '0')*10  + (buffer[3] - '0')*100 + (buffer[2] - '0')*1000;
                        setTime(valor);
                    }
                    //pos = 0;
                }                
            }
            if(valorLido == '.'){
                pos = 0;
            }
        }
    }        
    
    if (key != key_ant) 
    {
        if (key > 175 && key < 390) 
        {
            //ev = EV_RIGHT;
            ev = EV_UP;
        } else if (key > 390 && key < 478) 
        {
            //ev = EV_UP;
            ev = EV_RIGHT;
        } else if (key > 478 && key < 614) 
        {
            //ev = EV_LEFT;
            ev = EV_DOWN;       
        } else if (key > 614 && key < 860) 
        {
            //ev = EV_DOWN;
            ev = EV_LEFT;
        } else if (key > 860 && key < 1300) 
        {
            ev = EV_ENTER;
        }
        key_ant = key;
    }

    return ev;
}
