#include "stm32f4xx.h"
#include "./led/led.h"
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
  void delay(uint32_t xms)
  {
	while(xms--);
  }
int main(void)
{
	Led_Config();
	while(1)
	{
		LED0(0);
		LED1(0);
		LED2(0);
	
	}
	
}

/*********************************************END OF FILE**********************/

