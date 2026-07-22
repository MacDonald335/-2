#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"

int main(void)
{
	OLED_Init();
	LED_Init();
	
	OLED_Printf(0,0,OLED_8X16,"Hello World!");
	OLED_Printf(0,16,OLED_6X8,"Hello World!");
	OLED_Update();

	while (1)
	{
		LED_ON();
		Delay_ms(500);
		LED_OFF();
		Delay_ms(500);
		LED_Turn();
		Delay_ms(500);
		LED_Turn();
		Delay_ms(500);
	}
}
