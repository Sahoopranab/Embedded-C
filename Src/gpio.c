#include <stm32f4xx.h>

void gpio_init(void)
{
    RCC->AHB1ENR |= (1<<0);  // Enable clock for GPIOA
    RCC->AHB1ENR |= (1<<2);  // Enable clock for GPIOC

    GPIOA->MODER &= ~(1<<11);  // Clear mode bits for PA5
    GPIOA->MODER |= (1<<10);   // Set PA5 as output

    GPIOC->MODER &= ~(1<<13);  // Clear mode bits for PC6
    GPIOC->MODER |= (1<<12);   // Set PC6 as output

    GPIOC->MODER &= ~(1<<26);  // Clear mode bits for PC13
    GPIOC->PUPDR |= (1<<27);   // Enable pull-up for PC13
}

uint8_t read_button_state(void)
{
    return (GPIOC->IDR & (1<<13)) == 0;  // Return 1 if button is pressed
}

