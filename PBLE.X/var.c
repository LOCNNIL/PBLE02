#include "var.h"
#include "memoria.h"

//vari�veis a serem armazenadas
static char state;
static char language;
static int time;
static int alarmLevelLow1;
static int alarmLevelLow2;
static int alarmLevelHigh1;
static int alarmLevelHigh2;

void varInit(void) {
    state = 0; // estado inicial da m�quina
//    //time = 500; // tempo de atraso de atualiza��o
//    //alarmLevelLow1 = 100; // n�vel baixo do alarme 1
//    MEMwrite(0,3,20);
//    //alarmLevelLow2 = 100; // n�vel baixo do alarme 2
//    MEMwrite(0,4,20);
//    //alarmLevelHigh1 = 200; // n�vel alto do alarme 1
//    MEMwrite(0,5,100);
//    //alarmLevelHigh2 = 200; // n�vel alto do alarme 2
//    MEMwrite(0,6,100);
//    MEMwrite(0,1,20);
//    MEMwrite(0,2,0);
}

// obtem o n�mero(ponto) da m�quina de estado
char getState(void) {
    return state;
}

// � usado para setar o n�mero(ponto) da m�quina de estado
void setState(char newState) {
    state = newState;
}

// obtem o n�mero para o atraso do loop principal (main)
int getTime(void) {
    return MEMread(0,1);
}

// � usado para setar o n�mero de atraso do loop pricipal
void setTime(int newTime) {
    if(newTime > 254) // seguran�a para o valor n�o passar o limite 0 a 255
    {
        newTime = 254;
    }
    else if(newTime < 1)
    {
        newTime = 1;
    }
    MEMwrite(0,1,newTime);
}

//Limite superior ALARME 1
// obt�m do valor do n�vel alto do alarme 1
int getAlarmLevelHigh1(void) {
    return MEMread(0,5);
}

// � usado para setar o valor do n�vel alto do alarme 1
void setAlarmLevelHigh1(int newAlarmLevelHigh1) {
    if(newAlarmLevelHigh1 > 254) // seguran�a para o valor n�o passar o limite 0 a 255
    {
        newAlarmLevelHigh1 = 254;
    }
    MEMwrite(0,5,newAlarmLevelHigh1);
}

//Limite superior ALARME 2
// obt�m do valor do n�vel alto do alarme 2
int getAlarmLevelHigh2(void) {
    return (MEMread(0,6));
}

// � usado para setar o valor do n�vel alto do alarme 2
void setAlarmLevelHigh2(int newAlarmLevelHigh2) {
    if(newAlarmLevelHigh2 > 254) // seguran�a para o valor n�o passar o limite 0 a 255
    {
        newAlarmLevelHigh2 = 254;
    }
    MEMwrite(0,6,newAlarmLevelHigh2);
}

//Limite inferior ALARME 1
// obt�m do valor do n�vel baixo do alarme 1
int getAlarmLevelLow1(void) {
    return MEMread(0,3);
}
// � usado para setar o valor do n�vel baixo do alarme 1
void setAlarmLevelLow1(int newAlarmLevelLow1) {
    if(newAlarmLevelLow1 < 0) // seguran�a para o valor n�o passar o limite 0 a 255
    {
        newAlarmLevelLow1 = 0;
    }
    MEMwrite(0,3,newAlarmLevelLow1);
}

//Limite inferior ALARME 2
// obt�m do valor do n�vel baixo do alarme 2
int getAlarmLevelLow2(void) {
    return MEMread(0,4);
}
// � usado para setar o valor do n�vel baixo do alarme 2
void setAlarmLevelLow2(int newAlarmLevelLow2) {
    if(newAlarmLevelLow2 < 0) // seguran�a para o valor n�o passar o limite 0 a 255
    {
        newAlarmLevelLow2 = 0;
    }
    MEMwrite(0,4,newAlarmLevelLow2);
}

// obtem o numero que representa a linguagem
char getLanguage(void){
    return MEMread(0,2);
}

// � usado para setar o valor da linguagem, para assim modific�-la
void setLanguage(char newLanguage){
    if(newLanguage > 1)
    {
        newLanguage = 0;
    }
    else if(newLanguage < 0)
    {
        newLanguage = 1;
    }
    //s� tem 2 linguas
    //usando resto pra evitar colocar valor errado
    MEMwrite(0,2,newLanguage);
}