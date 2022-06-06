#include "var.h"
#include "stateMachine.h"
#include "event.h"
#include "output.h"
#include "lcd.h"
#include "keypad.h"
#include "mcc_generated_files/uart1.h"

static int aux; // criação das variávis auxíliares

int getAlarm_Low_High(){ // retorna se o loop está no alarme alto ou baixo
    return aux;
}

void smInit(void) {
    setState(STATE_TEMPO);
}

void smLoop(void) {
    unsigned char evento;   

    evento = eventRead(); // verifica qual dos 5 botões foram pressionados, sendo eles:
    // EV_DOWN , EV_UP, EV_LEFT, EV_RIGHT, EV_ENTER 

    // verifica em qual ponto está a máquina de estado
    switch (getState()) 
    {
        // estado de menu do alarme 1
        case STATE_ALARME_1_MENU:
            // execução de atividade
            // gestão da maquina de estado

            // caso o botão EV_DOWN seja pressionado, vai para o estado STATE_IDIOMA_MENU
            if (evento == EV_LEFT) {
                setState(STATE_IDIOMA_MENU);
            }

            // caso o botão EV_UP seja pressionado, vai para o estado STATE_ALARME_2_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_ALARME_2_MENU);
            }

            // caso o botão EV_ENTER seja pressionado, vai para o estado STATE_ALARME_1
            if (evento == EV_ENTER) {
                setState(STATE_ALARME_1);
            }
        break;

        case STATE_ALARME_1:
            // execução de atividade

            // a variável auxiliar_1 foi criada para setar os valores dos niveis baixo e alto do alarme,
            // sem haver a necessidade da criação de um novo estado para modificar cada nível

            // Nível baixo do ALARME
            // caso o botão pressionado seja EV_UP, será somada 1 unidade ao nível baixo do alarme 1
            if (evento == EV_UP && aux == 0) {
                setAlarmLevelLow1(getAlarmLevelLow1() + 1);
            }
            // caso o botão pressionado seja EV_DOWN, será subtraída 1 unidade ao nível baixo do alarme 1
            if (evento == EV_DOWN && aux == 0) {
                setAlarmLevelLow1(getAlarmLevelLow1() - 1);
            }

            // Nível alto do ALARME
            // caso o botão pressionado seja EV_UP, será somada 1 unidade ao nível alto do alarme 1
            if (evento == EV_UP && aux == 1) {
                setAlarmLevelHigh1(getAlarmLevelHigh1() + 1);
            }
            // caso o botão pressionado seja EV_DOWN, será subtraída 1 unidade ao nível alto do alarme 1
            if (evento == EV_DOWN && aux == 1) {
                setAlarmLevelHigh1(getAlarmLevelHigh1() - 1);
            }

            // gestão da maquina de estado
            // caso seja pressionado EV_LEFT, a máquina irá para o estado STATE_ALARME_1_MENU
            if (evento == EV_LEFT) {
                aux = 0;

                setState(STATE_ALARME_1_MENU);
            }

            // caso seja pressionado EV_ENTER, é somado 1 á variável auxliar_1. 
            if (evento == EV_ENTER) {
                aux++;
            }

            // caso a variável auxiliar 1 atinja o valor 2, seu valor é setado para zero.
            if (aux == 2) {
                aux = 0;
            }
        break;

        case STATE_ALARME_2_MENU:
            // execução de atividade
            // gestão da maquina de estado

            // caso seja pressionado EV_DOWN, a máquina vai para o estado STATE_ALARME_1_MENU
            if (evento == EV_LEFT) {
                setState(STATE_ALARME_1_MENU);
            }

            // caso seja pressionado EV_UP, a máquina vai para o estado STATE_TEMPO_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_TEMPO_MENU);
            }

            // caso seja pressionado EV_ENTER, a máquina vai para o estado STATE_ALARME_2
            if (evento == EV_ENTER) {
                setState(STATE_ALARME_2);
            }
        break;

        case STATE_ALARME_2:
            // execução de atividade

            // a variável auxiliar_1 foi criada para setar os valores dos niveis baixo e alto do alarme,
            // sem haver a necessidade da criação de um novo estado para modificar cada nível

            // Nível baixo do ALARME
            // caso o botão pressionado seja EV_UP, será somada 1 unidade ao nível baixo do alarme 2
            if (evento == EV_UP && aux == 0) {
                setAlarmLevelLow2(getAlarmLevelLow2() + 1);
            }
            // caso o botão pressionado seja EV_DOWN, será subtraída 1 unidade ao nível baixo do alarme 2
            if (evento == EV_DOWN && aux == 0) {
                setAlarmLevelLow2(getAlarmLevelLow2() - 1);
            }

            //Nível alto do ALARME
            // caso o botão pressionado seja EV_UP, será somada 1 unidade ao nível alto do alarme 2
            if (evento == EV_UP && aux == 1) {
                setAlarmLevelHigh2(getAlarmLevelHigh2() + 1);
            }
            // caso o botão pressionado seja EV_DOWN, será somada 1 unidade ao nível alto do alarme 2
            if (evento == EV_DOWN && aux == 1) {
                setAlarmLevelHigh2(getAlarmLevelHigh2() - 1);
            }

            // gestão da maquina de estado
            // caso seja pressionado o botão EV_LEFT, a máquina vai para o estado STATE_ALARME_2_MENU
            if (evento == EV_LEFT) {
                aux = 0;

                setState(STATE_ALARME_2_MENU);
            }
            // caso seja pressionado o botão EV_ENTER, é somado 1 a variável auxiliar_2
            if (evento == EV_ENTER) {
                aux++;
            }
            // caso o valor da valor da variável auxiliar_2 seja igual a 2, ela é zerada 
            if (aux == 2) {
                aux = 0;
            }
        break;

        case STATE_TEMPO_MENU:
            //execução de atividade

            //gestão da maquina de estado

            // caso o botão EV_DOWN seja pressiondo, a máquina vai para o estado STATE_ALARME_2_MENU
            if (evento == EV_LEFT) {
                setState(STATE_ALARME_2_MENU);
            }

            // caso o botão EV_UP seja pressionado, a máquina vai para o estado STATE_IDIOMA_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_IDIOMA_MENU);
            }

            // caso o botão EV_ENTER seja pressionado, a máquina vai para o estado STATE_TEMPO
            if (evento == EV_ENTER) {
                setState(STATE_TEMPO);
            }
        break;

        case STATE_TEMPO:
            //execução de atividade
            // caso seja pressionado o botão EV_UP, é somado 1 unidade a variável time
            if (evento == EV_UP) {
                setTime(getTime() + 1);
            }
            // caso seja pressionado o botão EV_DOWN, é subtraída 1 unidade a variável time
            if (evento == EV_DOWN) {
                setTime(getTime() - 1);
            }

            // gestão da maquina de estado
            // caso seja pressionado o botão EV_LEFT, a máquina vai para o estado STATE_TEMPO_MENU
            if (evento == EV_LEFT) {
                setState(STATE_TEMPO_MENU);
            }
         break;

        case STATE_IDIOMA_MENU:
            // execução de atividade

            // gestão da maquina de estado

            // caso seja pressionado o botão EV_DOWN, a máquina vai para o estado STATE_TEMPO_MENU
            if (evento == EV_LEFT) {
                setState(STATE_TEMPO_MENU);
            }

            // caso seja pressionado o botão EV_UP, a máquina vai para o estado STATE_ALARME_1_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_ALARME_1_MENU);
            }

            // caso seja pressionado o botão EV_ENTER, a máquina vai para o estado STATE_IDIOMA
            if (evento == EV_ENTER) {
                setState(STATE_IDIOMA);
            }
        break;

        case STATE_IDIOMA:
            // execução de atividade
            // caso seja pressionado o botão EV_UP, é somado 1 na variável language
            if (evento == EV_UP) {
                setLanguage(getLanguage() + 1);
            }
            // caso seja pressionado o botão EV_DOWN, é subtraído 1 na variável language
            if (evento == EV_DOWN) {
                setLanguage(getLanguage() - 1);
            }
            
            //gestão da maquina de estado

            // caso seja pressionado o botão EV_LEFT, a máquina vai para o estado STATE_IDIOMA_MENU
            if (evento == EV_LEFT) {
                setState(STATE_IDIOMA_MENU);
            }
        break;         
    }

    outputPrint(getState(), getLanguage()); // esta função é utilizada para mostrar mensagens no display LCD
}
