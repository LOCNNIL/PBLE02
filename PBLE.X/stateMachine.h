/* 
 * File:   stateMachine.h
 * Author: Avell
 *
 * Created on 18 de Junho de 2017, 22:17
 */

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H


//estados da maquina de Estados

enum {
    STATE_ALARME_1_MENU, //0
    STATE_ALARME_1, //1
    
    STATE_ALARME_2_MENU, //2
    STATE_ALARME_2, //3
    
    STATE_TEMPO_MENU, //4
    STATE_TEMPO, //5
    
    STATE_IDIOMA_MENU, //6
    STATE_IDIOMA, //7   
            
    STATE_FIM //8
};

int getAlarm_Low_High();
void smInit(void);
void smLoop(void);


#endif	/* STATEMACHINE_H */

