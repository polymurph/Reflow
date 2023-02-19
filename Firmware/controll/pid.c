#include "pid.h"

void pid_init(
    pid_t* pid,
    float P,
    float I,
    float D,
    float f_sample)
{
    pid->smaple_frequency = f_sample;
    pid->nyquist_frequency = f_sample / 2;
    pid->K_P = P;
    pid->K_I = I;
    pid->K_D = D / pid->nyquist_frequency;
    pid->w_I = 0.0;
    pid->w_D = 0.0;
    pid->u = 0;
}

float pid_calc(
    pid_t* pid,
    float error)
{
    float temp;

    // proportional calculations
    pid->u = pid->K_P * error;

    // integral calculations
    temp = error + pid->w_I;
    pid->u+= pid->K_I * (temp - pid->w_I);
    pid->w_I = temp;

    // differential calculations
    temp = error - pid->w_D;
    pid->u += pid->K_D * (temp - pid->w_D);
    pid->w_D = temp;

    return pid->u;
}

void pid_reset(pid_t* pid)
{
    pid->u = 0;
    pid->w_I = 0;
    pid->w_D = 0;
}