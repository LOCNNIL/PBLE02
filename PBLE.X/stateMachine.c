#include "var.h"
#include "stateMachine.h"
#include "event.h"
#include "output.h"
#include "lcd.h"
#include "keypad.h"
#include "mcc_generated_files/uart1.h"

static int aux; // cria��o das vari�vis aux�liares

int getAlarm_Low_High(){ // retorna se o loop est� no alarme alto ou baixo
    return aux;
}

void smInit(void) {
    setState(STATE_TEMPO);
}

void smLoop(void) {
    unsigned char evento;   

    evento = eventRead(); // verifica qual dos 5 bot�es foram pressionados, sendo eles:
    // EV_DOWN , EV_UP, EV_LEFT, EV_RIGHT, EV_ENTER 

    // verifica em qual ponto est� a m�quina de estado
    switch (getState()) 
    {
        // estado de menu do alarme 1
        case STATE_ALARME_1_MENU:
            // execu��o de atividade
            // gest�o da maquina de estado

            // caso o bot�o EV_DOWN seja pressionado, vai para o estado STATE_IDIOMA_MENU
            if (evento == EV_LEFT) {
                setState(STATE_IDIOMA_MENU);
            }

            // caso o bot�o EV_UP seja pressionado, vai para o estado STATE_ALARME_2_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_ALARME_2_MENU);
            }

            // caso o bot�o EV_ENTER seja pressionado, vai para o estado STATE_ALARME_1
            if (evento == EV_ENTER) {
                setState(STATE_ALARME_1);
            }
        break;

        case STATE_ALARME_1:
            // execu��o de atividade

            // a vari�vel auxiliar_1 foi criada para setar os valores dos niveis baixo e alto do alarme,
            // sem haver a necessidade da cria��o de um novo estado para modificar cada n�vel

            // N�vel baixo do ALARME
            // caso o bot�o pressionado seja EV_UP, ser� somada 1 unidade ao n�vel baixo do alarme 1
            if (evento == EV_UP && aux == 0) {
                setAlarmLevelLow1(getAlarmLevelLow1() + 1);
            }
            // caso o bot�o pressionado seja EV_DOWN, ser� subtra�da 1 unidade ao n�vel baixo do alarme 1
            if (evento == EV_DOWN && aux == 0) {
                setAlarmLevelLow1(getAlarmLevelLow1() - 1);
            }

            // N�vel alto do ALARME
            // caso o bot�o pressionado seja EV_UP, ser� somada 1 unidade ao n�vel alto do alarme 1
            if (evento == EV_UP && aux == 1) {
                setAlarmLevelHigh1(getAlarmLevelHigh1() + 1);
            }
            // caso o bot�o pressionado seja EV_DOWN, ser� subtra�da 1 unidade ao n�vel alto do alarme 1
            if (evento == EV_DOWN && aux == 1) {
                setAlarmLevelHigh1(getAlarmLevelHigh1() - 1);
            }

            // gest�o da maquina de estado
            // caso seja pressionado EV_LEFT, a m�quina ir� para o estado STATE_ALARME_1_MENU
            if (evento == EV_LEFT) {
                aux = 0;

                setState(STATE_ALARME_1_MENU);
            }

            // caso seja pressionado EV_ENTER, � somado 1 � vari�vel auxliar_1. 
            if (evento == EV_ENTER) {
                aux++;
            }

            // caso a vari�vel auxiliar 1 atinja o valor 2, seu valor � setado para zero.
            if (aux == 2) {
                aux = 0;
            }
        break;

        case STATE_ALARME_2_MENU:
            // execu��o de atividade
            // gest�o da maquina de estado

            // caso seja pressionado EV_DOWN, a m�quina vai para o estado STATE_ALARME_1_MENU
            if (evento == EV_LEFT) {
                setState(STATE_ALARME_1_MENU);
            }

            // caso seja pressionado EV_UP, a m�quina vai para o estado STATE_TEMPO_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_TEMPO_MENU);
            }

            // caso seja pressionado EV_ENTER, a m�quina vai para o estado STATE_ALARME_2
            if (evento == EV_ENTER) {
                setState(STATE_ALARME_2);
            }
        break;

        case STATE_ALARME_2:
            // execu��o de atividade

            // a vari�vel auxiliar_1 foi criada para setar os valores dos niveis baixo e alto do alarme,
            // sem haver a necessidade da cria��o de um novo estado para modificar cada n�vel

            // N�vel baixo do ALARME
            // caso o bot�o pressionado seja EV_UP, ser� somada 1 unidade ao n�vel baixo do alarme 2
            if (evento == EV_UP && aux == 0) {
                setAlarmLevelLow2(getAlarmLevelLow2() + 1);
            }
            // caso o bot�o pressionado seja EV_DOWN, ser� subtra�da 1 unidade ao n�vel baixo do alarme 2
            if (evento == EV_DOWN && aux == 0) {
                setAlarmLevelLow2(getAlarmLevelLow2() - 1);
            }

            //N�vel alto do ALARME
            // caso o bot�o pressionado seja EV_UP, ser� somada 1 unidade ao n�vel alto do alarme 2
            if (evento == EV_UP && aux == 1) {
                setAlarmLevelHigh2(getAlarmLevelHigh2() + 1);
            }
            // caso o bot�o pressionado seja EV_DOWN, ser� somada 1 unidade ao n�vel alto do alarme 2
            if (evento == EV_DOWN && aux == 1) {
                setAlarmLevelHigh2(getAlarmLevelHigh2() - 1);
            }

            // gest�o da maquina de estado
            // caso seja pressionado o bot�o EV_LEFT, a m�quina vai para o estado STATE_ALARME_2_MENU
            if (evento == EV_LEFT) {
                aux = 0;

                setState(STATE_ALARME_2_MENU);
            }
            // caso seja pressionado o bot�o EV_ENTER, � somado 1 a vari�vel auxiliar_2
            if (evento == EV_ENTER) {
                aux++;
            }
            // caso o valor da valor da vari�vel auxiliar_2 seja igual a 2, ela � zerada 
            if (aux == 2) {
                aux = 0;
            }
        break;

        case STATE_TEMPO_MENU:
            //execu��o de atividade

            //gest�o da maquina de estado

            // caso o bot�o EV_DOWN seja pressiondo, a m�quina vai para o estado STATE_ALARME_2_MENU
            if (evento == EV_LEFT) {
                setState(STATE_ALARME_2_MENU);
            }

            // caso o bot�o EV_UP seja pressionado, a m�quina vai para o estado STATE_IDIOMA_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_IDIOMA_MENU);
            }

            // caso o bot�o EV_ENTER seja pressionado, a m�quina vai para o estado STATE_TEMPO
            if (evento == EV_ENTER) {
                setState(STATE_TEMPO);
            }
        break;

        case STATE_TEMPO:
            //execu��o de atividade
            // caso seja pressionado o bot�o EV_UP, � somado 1 unidade a vari�vel time
            if (evento == EV_UP) {
                setTime(getTime() + 1);
            }
            // caso seja pressionado o bot�o EV_DOWN, � subtra�da 1 unidade a vari�vel time
            if (evento == EV_DOWN) {
                setTime(getTime() - 1);
            }

            // gest�o da maquina de estado
            // caso seja pressionado o bot�o EV_LEFT, a m�quina vai para o estado STATE_TEMPO_MENU
            if (evento == EV_LEFT) {
                setState(STATE_TEMPO_MENU);
            }
         break;

        case STATE_IDIOMA_MENU:
            // execu��o de atividade

            // gest�o da maquina de estado

            // caso seja pressionado o bot�o EV_DOWN, a m�quina vai para o estado STATE_TEMPO_MENU
            if (evento == EV_LEFT) {
                setState(STATE_TEMPO_MENU);
            }

            // caso seja pressionado o bot�o EV_UP, a m�quina vai para o estado STATE_ALARME_1_MENU
            if (evento == EV_RIGHT) {
                setState(STATE_ALARME_1_MENU);
            }

            // caso seja pressionado o bot�o EV_ENTER, a m�quina vai para o estado STATE_IDIOMA
            if (evento == EV_ENTER) {
                setState(STATE_IDIOMA);
            }
        break;

        case STATE_IDIOMA:
            // execu��o de atividade
            // caso seja pressionado o bot�o EV_UP, � somado 1 na vari�vel language
            if (evento == EV_UP) {
                setLanguage(getLanguage() + 1);
            }
            // caso seja pressionado o bot�o EV_DOWN, � subtra�do 1 na vari�vel language
            if (evento == EV_DOWN) {
                setLanguage(getLanguage() - 1);
            }
            
            //gest�o da maquina de estado

            // caso seja pressionado o bot�o EV_LEFT, a m�quina vai para o estado STATE_IDIOMA_MENU
            if (evento == EV_LEFT) {
                setState(STATE_IDIOMA_MENU);
            }
        break;         
    }

    outputPrint(getState(), getLanguage()); // esta fun��o � utilizada para mostrar mensagens no display LCD
}
