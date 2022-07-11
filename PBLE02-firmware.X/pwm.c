#include <xc.h>
#include <stdint.h>

#include "pwm.h"

static uint8_t pwm_duty_cycle;

void pwmInit(uint32_t frequency){
    //Garante que a frequencia esta dentro dos limites
    if(frequency > PWM_MAX_FREQ){
        frequency = PWM_MAX_FREQ;
    }
    else if(frequency < PWM_MIN_FREQ){
        frequency = PWM_MIN_FREQ;
    }
    //Periodo do timer
    CCP1PR = ((8000000/frequency)-1);
    //Limpa o timer
    CCP1TMR = 0;
    //Confuigura o duty cycle inicial
    pwm_duty_cycle = 50;
    CCP1RA = 0;
    CCP1RB = (pwm_duty_cycle*(CCP1PR+1))/100;
    //Configura o modo de operação
    CCP1CON1bits.MOD = 0b0101;
    //Configura o prescaler como 1
    CCP1CON1bits.TMRPS = 0;
    //Habilita o pino para pwm
    CCP1CON2bits.OCAEN = 1;
    //Habilita o restart automatico do pwm
    CCP1CON2bits.PWMRSEN = 1;
    //Modo de saida do PWM
    CCP1CON3bits.OUTM = 0;
    //Habilita o modulo CCP
    CCP1CON1bits.ON = 1;
}

void pwmSetDC(uint8_t new_duty_cycle){
    pwm_duty_cycle = new_duty_cycle;
    CCP1RB = (pwm_duty_cycle*(CCP1PR+1))/100;
}

uint8_t pwmGetDC(){
    return pwm_duty_cycle;
}