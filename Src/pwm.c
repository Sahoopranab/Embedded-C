#include "pwm.h"
#include <stm32f4xx.h>

void PWM_init(void)
{
    RCC->APB1ENR |= (1<<1);  // Enable clock for TIM2
    RCC->AHB1ENR |= (1<<2);  // Enable clock for GPIOC

    GPIOC->MODER |= (1<<13);  // Set PC6 to alternate function mode
    GPIOC->MODER &= ~(1<<12);

    GPIOC->AFR[0] &= ~(0xF << 24);  // Clear alternate function settings for PC6
    GPIOC->AFR[0] |= (1<<25);       // Set PC6 to AF2 (TIM3_CH1)

    TIM3->PSC = 1600 - 1;       // Set prescaler to 1600 (10kHz PWM frequency)
    TIM3->ARR = 100 - 1;        // Set auto-reload value to 99 (100Hz PWM frequency)
    TIM3->CCMR1 |= (6 << 4);    // PWM mode 1
    TIM3->CCMR1 |= (1 << 3);    // Enable preload register on TIM3_CCR1
    TIM3->CCER |= (1 << 0);     // Enable capture/compare 1 output
    TIM3->CR1 |= (1 << 7);      // Enable auto-reload preload
    TIM3->CR1 |= (1 << 0);      // Enable counter
}

void PWM_set_duty_cycle(uint32_t duty_cycle)
{
    TIM3->CCR1 = duty_cycle;  // Set duty cycle
}
