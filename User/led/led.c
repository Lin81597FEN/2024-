#include "led.h"
// LED0和LED1 阳极均接到3.3V，阴极接IO口
// LED0     接  PF9
// LED1     接  PF10
// LED2 由于作为电源指示灯，阳极接3.3V，阴极接地，当上电时，LED2亮
void Led_Config(void)
{
	//进行任何外设操作前必须先打开相应的时钟，否则无法执行该代码
	/***************      使能GPIO口的时钟      *****************************/
	//由于使用到的是GPIOF，所以打开GPIOF的时钟
	//GPIO口挂载在 AHB1 总线上，AHB1 总线频率为 168M
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//打开GPIOF的时钟
	
	
	//点灯需要用到GPIO口，所以需要先配置GPIO口
	/***************      配置GPIO口      *****************************/
	// 创建结构体变量
	GPIO_InitTypeDef    GPIO_InitStructure;
	// 配置引脚
	GPIO_InitStructure.GPIO_Pin           =      GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_7;
	// 设置为输出模式
	GPIO_InitStructure.GPIO_Mode          =      GPIO_Mode_OUT;
	// IO口电平翻转速度为 100 MHZ
	GPIO_InitStructure.GPIO_Speed         =      GPIO_Speed_100MHz;
	// 配置为推挽模式
	GPIO_InitStructure.GPIO_OType         =      GPIO_OType_PP;
	// 设置上拉
	GPIO_InitStructure.GPIO_PuPd          =      GPIO_PuPd_UP ;
	// 初始化结构体
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}
void LED0(uint16_t x)
{
	if(x)
	{
		// 置低电平
		GPIO_ResetBits(GPIOF,GPIO_Pin_13);
	}
	else 
	{
		// 置高电平
		GPIO_SetBits(GPIOF,GPIO_Pin_13);
	}
}
void LED1(uint16_t x)
{
	if(x)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_14);
	}
	else 
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_14);
	}
}
void LED2(uint16_t x)
{
	if(x)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_7);
	}
	else 
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_7);
	}
}



