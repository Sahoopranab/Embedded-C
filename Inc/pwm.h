/*
 * pwm.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Pranab Kumar Sahoo
 */

#ifndef PWM_H_
#define PWM_H_
#include <stdint.h>

void PWM_init(void);
void PWM_set_duty_cycle(uint32_t duty_cycle);

#endif /* PWM_H_ */
