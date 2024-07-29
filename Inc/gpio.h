/*
 * gpio.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Pranab Kumar Sahoo
 */

#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>

void gpio_init(void);
uint8_t read_button_state(void);

#endif /* GPIO_H_ */
