#include "stm32g0xx.h"


#define GPIOCEN					(1U<<2)
#define PIN13					(1U<<13)
#define PIN14					(1U<<14)
#define LED1					PIN13
#define LED2					PIN14

int main()
{
	RCC		-> 	IOPENR 	|= 	GPIOCEN;
	GPIOC	-> 	MODER 	|= 	(1U<<26);;  //  Set bit 10 to 1
	GPIOC	-> 	MODER 	&=~	(1U<<27); 	//  Set bit 11 to 0

	while(1)
	{
		GPIOC -> ODR ^= LED1;

		for(uint32_t i = 0; i< 100000; i++){};
	}
}
