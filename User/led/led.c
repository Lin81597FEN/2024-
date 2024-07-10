#include "led.h"
// LED0��LED1 �������ӵ�3.3V��������IO��
// LED0     ��  PF9
// LED1     ��  PF10
// LED2 ������Ϊ��Դָʾ�ƣ�������3.3V�������ӵأ����ϵ�ʱ��LED2��
void Led_Config(void)
{
	//�����κ��������ǰ�����ȴ���Ӧ��ʱ�ӣ������޷�ִ�иô���
	/***************      ʹ��GPIO�ڵ�ʱ��      *****************************/
	//����ʹ�õ�����GPIOF�����Դ�GPIOF��ʱ��
	//GPIO�ڹ����� AHB1 �����ϣ�AHB1 ����Ƶ��Ϊ 168M
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//��GPIOF��ʱ��
	
	
	//�����Ҫ�õ�GPIO�ڣ�������Ҫ������GPIO��
	/***************      ����GPIO��      *****************************/
	// �����ṹ�����
	GPIO_InitTypeDef    GPIO_InitStructure;
	// ��������
	GPIO_InitStructure.GPIO_Pin           =      GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_7;
	// ����Ϊ���ģʽ
	GPIO_InitStructure.GPIO_Mode          =      GPIO_Mode_OUT;
	// IO�ڵ�ƽ��ת�ٶ�Ϊ 100 MHZ
	GPIO_InitStructure.GPIO_Speed         =      GPIO_Speed_100MHz;
	// ����Ϊ����ģʽ
	GPIO_InitStructure.GPIO_OType         =      GPIO_OType_PP;
	// ��������
	GPIO_InitStructure.GPIO_PuPd          =      GPIO_PuPd_UP ;
	// ��ʼ���ṹ��
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}
void LED0(uint16_t x)
{
	if(x)
	{
		// �õ͵�ƽ
		GPIO_ResetBits(GPIOF,GPIO_Pin_13);
	}
	else 
	{
		// �øߵ�ƽ
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



