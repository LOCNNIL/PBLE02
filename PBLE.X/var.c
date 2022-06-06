#include "var.h"
#include "memoria.h"

//variáveis a serem armazenadas
static char state;
static char language;
static int time;
static int alarmLevelLow1;
static int alarmLevelLow2;
static int alarmLevelHigh1;
static int alarmLevelHigh2;

void varInit(void) {
    state = 0; // estado inicial da máquina
//    //time = 500; // tempo de atraso de atualização
//    //alarmLevelLow1 = 100; // nível baixo do alarme 1
//    MEMwrite(0,3,20);
//    //alarmLevelLow2 = 100; // nível baixo do alarme 2
//    MEMwrite(0,4,20);
//    //alarmLevelHigh1 = 200; // nível alto do alarme 1
//    MEMwrite(0,5,100);
//    //alarmLevelHigh2 = 200; // nível alto do alarme 2
//    MEMwrite(0,6,100);
//    MEMwrite(0,1,20);
//    MEMwrite(0,2,0);
}

// obtem o número(ponto) da máquina de estado
char getState(void) {
    return state;
}

// é usado para setar o número(ponto) da máquina de estado
void setState(char newState) {
    state = newState;
}

// obtem o número para o atraso do loop principal (main)
int getTime(void) {
    return MEMread(0,1);
}

// é usado para setar o número de atraso do loop pricipal
void setTime(int newTime) {
    if(newTime > 254) // segurança para o valor não passar o limite 0 a 255
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
// obtém do valor do nível alto do alarme 1
int getAlarmLevelHigh1(void) {
    return MEMread(0,5);
}

// é usado para setar o valor do nível alto do alarme 1
void setAlarmLevelHigh1(int newAlarmLevelHigh1) {
    if(newAlarmLevelHigh1 > 254) // segurança para o valor não passar o limite 0 a 255
    {
        newAlarmLevelHigh1 = 254;
    }
    MEMwrite(0,5,newAlarmLevelHigh1);
}

//Limite superior ALARME 2
// obtém do valor do nível alto do alarme 2
int getAlarmLevelHigh2(void) {
    return (MEMread(0,6));
}

// é usado para setar o valor do nível alto do alarme 2
void setAlarmLevelHigh2(int newAlarmLevelHigh2) {
    if(newAlarmLevelHigh2 > 254) // segurança para o valor não passar o limite 0 a 255
    {
        newAlarmLevelHigh2 = 254;
    }
    MEMwrite(0,6,newAlarmLevelHigh2);
}

//Limite inferior ALARME 1
// obtém do valor do nível baixo do alarme 1
int getAlarmLevelLow1(void) {
    return MEMread(0,3);
}
// é usado para setar o valor do nível baixo do alarme 1
void setAlarmLevelLow1(int newAlarmLevelLow1) {
    if(newAlarmLevelLow1 < 0) // segurança para o valor não passar o limite 0 a 255
    {
        newAlarmLevelLow1 = 0;
    }
    MEMwrite(0,3,newAlarmLevelLow1);
}

//Limite inferior ALARME 2
// obtém do valor do nível baixo do alarme 2
int getAlarmLevelLow2(void) {
    return MEMread(0,4);
}
// é usado para setar o valor do nível baixo do alarme 2
void setAlarmLevelLow2(int newAlarmLevelLow2) {
    if(newAlarmLevelLow2 < 0) // segurança para o valor não passar o limite 0 a 255
    {
        newAlarmLevelLow2 = 0;
    }
    MEMwrite(0,4,newAlarmLevelLow2);
}

// obtem o numero que representa a linguagem
char getLanguage(void){
    return MEMread(0,2);
}

// é usado para setar o valor da linguagem, para assim modificá-la
void setLanguage(char newLanguage){
    if(newLanguage > 1)
    {
        newLanguage = 0;
    }
    else if(newLanguage < 0)
    {
        newLanguage = 1;
    }
    //só tem 2 linguas
    //usando resto pra evitar colocar valor errado
    MEMwrite(0,2,newLanguage);
}