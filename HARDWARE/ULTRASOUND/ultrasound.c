#include "ultrasound.h"

/**
* @brief ������SR04Trig GPIO��ʼ�� 
* @param 
* @return 
*/
void SR04_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	 //ʹ��PG�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	    		 //PG1�˿�����, �������
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOG, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(GPIOG,GPIO_Pin_15);
}
