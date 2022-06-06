/* 
 * File:   alarme.h
 * Author: Avell
 *
 * Created on 14 de Junho de 2017, 16:10
 */

#ifndef VAR_H
#define	VAR_H

void varInit(void);

char getState(void);
void setState(char newState);

int getTime(void);
void setTime(int newTime);

int getAlarmLevelHigh1(void);
void setAlarmLevelHigh1(int newAlarmLevelHigh1);

int getAlarmLevelHigh2(void);
void setAlarmLevelHigh2(int newAlarmLevelHigh2);

int getAlarmLevelLow1(void);
void setAlarmLevelLow1(int newAlarmLevelLow1);

int getAlarmLevelLow2(void);
void setAlarmLevelLow2(int newAlarmLevelLow2);

char getLanguage(void);
void setLanguage(char newLanguage);
#endif	/* VAR_H */
