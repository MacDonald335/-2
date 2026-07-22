#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Timer.h"
#include "Key.h"

    //int main(void)
   // {   //OLED以及LED测试
	// OLED_Init();
	// LED_Init();
	
	// OLED_Printf(0,0,OLED_8X16,"Hello World!");
	// OLED_Printf(0,16,OLED_6X8,"Hello World!");
	// OLED_Update();

	// while (1)
	// {
	// 	LED_ON();
	// 	Delay_ms(500);
	// 	LED_OFF();
	// 	Delay_ms(500);
	// 	LED_Turn();
	// 	Delay_ms(500);
	// 	LED_Turn();
	// 	Delay_ms(500);
	// }



// //定时器测试

// uint16_t Count;

// int main(void)
// {
// 	OLED_Init();
// 	Timer_Init();



// 	while (1)
// 	{

// 		OLED_Printf(0,0,OLED_8X16,"Count:%05d",Count);
// 		OLED_Update();
// 	}


// }

// void TIM1_UP_IRQHandler(void)
// {
// 	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
// 	{
// 		Count++;

// 		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
// 	}
// }



//定时器测试

uint16_t Count;
uint8_t KeyNum,Num;
int main(void)
{
	OLED_Init();
	Timer_Init();
	Key_Init();



	while (1)
	{
		KeyNum = Key_GetNum();
		if (KeyNum == 1)
		{
			Num ++;
		}

		if (KeyNum == 2)
		{
			Num --;
		}

		if (KeyNum == 3)
		{
			Num +=10;
		}

		if (KeyNum == 4)
		{
			Num -=10;
		}

		OLED_Printf(0,0,OLED_8X16,"Count:%05d",Count);
		OLED_Printf(0,16,OLED_8X16,"Num:%03d",Num);
		OLED_Update();
	}


}

void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Count++;

		Key_Tick();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}











