#include "timer.h"
#include <stm32f4xx.h>

void Timer_init(void)
{
    RCC->APB1ENR |= (1<<0);  // Enable clock for TIM2
    TIM2->PSC = 16000;       // Set prescaler to 16000
    TIM2->ARR = 1000-1;      // Set auto-reload value to 999
    TIM2->CNT = 0;           // Reset counter
    TIM2->CR1 |= (1<<0);     // Enable Timer 2
}

void Tim2_DELAY(uint32_t delay)
{
    TIM2->ARR = delay - 1;  // Update generation
    while(!(TIM2->SR & (1<<0)));  // Wait until update interrupt flag is set
    TIM2->SR &= ~(1<<0);          // Clear update interrupt flag
    TIM3->EGR |= (1<<0);


}
