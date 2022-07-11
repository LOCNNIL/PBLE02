#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define PWM_MAX_FREQ    1000000
#define PWM_MIN_FREQ    100

//Inicializa o pwm com a frequencia desejada
void pwmInit(uint32_t frequency);

//Configura o duty cyle do pwm
void pwmSetDC(uint8_t new_duty_cycle);

//Retorna o duty cycle atual do pwm
uint8_t pwmGetDC();

#endif //PWM_H