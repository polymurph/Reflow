/**
 * @file pid.h
 * @author Edwin Koch and Kerem Yollu
 * @brief PID controller
 * @date 2023-02-19
 */
#ifndef _PID_H_
#define _PID_H_

/**
 * @struct pid_t
 * PID class
 * 
 * @var pid_t::sample_frequency
 *   Sample frequency on which the PID runs.
 * @var pid_t::nyquist_frequency
 *   Nyquist frequency.
 * @var pid_t::K_P
 *   Proportional factor.
 * @var pid_t::K_I
 *   Integral factor.
 * @var pid_t::K_D
 *   Derivative factor.
 * @var pid_t::w_I
 *   Internal integral state.
 * @var pid_t::w_D
 *   Internal derivative state.
 * @var pid_t::u
 *   PID output value
 */
typedef struct {
    float smaple_frequency;
    float nyquist_frequency;
    float K_P;
    float K_I;
    float K_D;
    float w_I;
    float w_D;
    float u;
} pid_t;

/**
 * @brief PID initializer
 * 
 * Initializes the PID object.
 * 
 * @param pid pointer to pid object
 * @param P proportional factor
 * @param I integral factor
 * @param D  derivative factor
 * @param f_sample sample frequency
 */
void pid_init(
    pid_t* pid,
    float P,
    float I,
    float D,
    float f_sample);

/**
 * @brief Controll Calculator
 * 
 * The PID controller is executed.
 * All the needed calculations are done here.
 * The setvalue of the PID is returned.
 * 
 * @param pid pointer to PID object
 * @param error error
 * @return float PID output controll value
 */
float pid_calc(
    pid_t* pid,
    float error);

/**
 * @brief PID resetter
 * 
 * Resets the PID internal states.
 * 
 * @param pid pointer to PID object
 */
void pid_reset(pid_t* pid);

#endif // _PID_H_
