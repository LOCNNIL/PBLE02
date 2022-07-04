#include "memory.h"
#include "Utils.h"
#include "lcd.h"

#define STATE_ADDR 0x00
#define ALARM_HIGH_1 0x01
#define ALARM_LOW_1 0x03
#define ALARM_HIGH_2 0x05
#define ALARM_LOW_2 0x07
#define TIMER_ADDR 0x09
#define LANGUAGE_ADDR 0x0D

uint8_t getState(void){
    uint8_t state[1];
    readMem(STATE_ADDR, state, 1);
    return state[0];
}
void setState(uint8_t state){
    uint8_t pstate[1];
    pstate[0] = state;
    writeMem(STATE_ADDR, pstate, 1);
}

uint16_t getAlarmHigh1(void){
    uint8_t alarmHigh1[2];
    readMem(ALARM_HIGH_1, alarmHigh1, 2);
    uint16_t LSB = alarmHigh1[0];
    uint16_t MSB = alarmHigh1[1];
    MSB = MSB << 8;
    uint16_t o = MSB+LSB;
    return o;
};
void setAlarmHigh1(uint16_t alarmHigh1){
    uint8_t palarmHigh1[2];
    palarmHigh1[0] = alarmHigh1&0xFF;
    palarmHigh1[1] = alarmHigh1 >> 8;
    writeMem(ALARM_HIGH_1, palarmHigh1, 2);
}

uint16_t getAlarmLow1(void){
    uint8_t alarmLow1[2];
    readMem(ALARM_LOW_1, alarmLow1, 2);
    uint16_t LSB = alarmLow1[0];
    uint16_t MSB = alarmLow1[1];
    MSB = MSB << 8;
    uint16_t o = MSB+LSB;
    return o;
}
void setAlarmLow1(uint16_t alarmLow1){
    uint8_t palarmLow1[2];
    palarmLow1[0] = alarmLow1&0xFF;
    palarmLow1[1] = alarmLow1>>8;
    writeMem(ALARM_LOW_1, palarmLow1, 2);
}

uint16_t getAlarmHigh2(void){
    uint8_t alarmHigh2[2];
    readMem(ALARM_HIGH_2, alarmHigh2, 2);
    uint16_t LSB = alarmHigh2[0];
    uint16_t MSB = alarmHigh2[1];
    MSB = MSB << 8;
    uint16_t o = MSB+LSB;
    return o;
};
void setAlarmHigh2(uint16_t alarmHigh2){
    uint8_t palarmHigh2[2];
    palarmHigh2[0] = alarmHigh2&0xFF;
    palarmHigh2[1] = alarmHigh2>>8;
    writeMem(ALARM_HIGH_2, palarmHigh2, 2);
}

uint16_t getAlarmLow2(void){
    uint8_t alarmLow2[2];
    readMem(ALARM_LOW_2, alarmLow2, 2);
    uint16_t LSB = alarmLow2[0];
    uint16_t MSB = alarmLow2[1];
    MSB = MSB << 8;
    uint16_t o = MSB+LSB;
    return o;
}
void setAlarmLow2(uint16_t alarmLow2){
    uint8_t palarmLow2[2];
    palarmLow2[0] = alarmLow2&0xFF;
    palarmLow2[1] = alarmLow2>>8;
    writeMem(ALARM_LOW_2, palarmLow2, 2);
}

uint32_t getTimer(void){
    uint8_t timer[4];
    readMem(TIMER_ADDR, timer, 4);
    uint32_t by0 = timer[0];
    uint32_t by1 = timer[1];
    uint32_t by2 = timer[2];
    uint32_t by3 = timer[3];
    by1 = by1 << 8;
    by2 = by2 << 16;
    by3 = by3 << 24;
    uint32_t o = by0+by1+by2+by3;
    return o;
}

void setTimer(uint32_t timer){
    uint8_t ptimer[4];
    ptimer[0] = timer&0xFF;
    ptimer[1] = timer>>8;
    ptimer[2] = timer>>16;
    ptimer[3] = timer>>24;
    writeMem(TIMER_ADDR, ptimer, 4);
}

uint8_t getLanguage(void){
    uint8_t language[1];
    readMem(LANGUAGE_ADDR, language, 1);
    return language[0];
}

void setLanguage(uint8_t language){
    uint8_t planguage[1];
    planguage[0] = language;
    writeMem(LANGUAGE_ADDR, planguage, 1);
}