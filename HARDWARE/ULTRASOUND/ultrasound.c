#include "ultrasound.h"

/**
* @brief 超声波SR04Trig GPIO初始化 
* @param 
* @return 
*/
void SR04_GPIO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	 //使能PG端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	    		 //PG1端口配置, 推挽输出
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOG, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOG,GPIO_Pin_15);
}
