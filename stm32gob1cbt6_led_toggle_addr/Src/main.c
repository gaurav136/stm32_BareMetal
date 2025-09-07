/*
 * PC13 and PC14
 */

#define PERIPH_BASE           	(0x40000000UL)  /*!< Peripheral base address */
#define IOPORT_BASE           	(0x50000000UL)  /*!< IOPORT base address */

/*!< Peripheral memory map */
#define APBPERIPH_BASE        	(PERIPH_BASE)
#define AHBPERIPH_OFFSET		(0x00020000UL)
#define AHBPERIPH_BASE        	(PERIPH_BASE + AHBPERIPH_OFFSET)

#define GPIOC_OFFSET			(0x0800UL)
#define GPIOC_BASE				(IOPORT_BASE + GPIOC_OFFSET)

#define RCC_OFFSET 				(0x1000UL)
#define RCC_BASE				(AHBPERIPH_BASE + RCC_OFFSET)

#define IOPENR_OFFSET 			(0x34UL)
#define RCC_IOPENR				(*(volatile unsigned int *)(RCC_BASE + IOPENR_OFFSET))

#define MODER_OFFSET			(0x00U)
#define GPIOC_MODER				(*(volatile unsigned int *)(GPIOC_BASE + MODER_OFFSET))

#define ODR_OFFSET				(0x14U)
#define GPIOC_ODR				(*(volatile unsigned int *)(GPIOC_BASE + ODR_OFFSET))

#define GPIOCEN					(1U<<2)
#define PIN13					(1U<<13)
#define PIN14					(1U<<14)
#define LED1					PIN13
#define LED2					PIN14


void delay(volatile unsigned int time)
{
    while (time--);
}

int main(void)
{
	RCC_IOPENR |= GPIOCEN;

	GPIOC_MODER |= (1U<<26);
	GPIOC_MODER &= ~(1U<<27);
	GPIOC_MODER |= (1U<<28);
	GPIOC_MODER &= ~(1U<<29);

	while (1)
	{
		GPIOC_ODR |= LED1;
		GPIOC_ODR &= ~LED2;
		delay(1000000);
		GPIOC_ODR &= ~LED1;
		GPIOC_ODR |= LED2;
		delay(1000000);
	}

}

