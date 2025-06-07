#include "stm32f10x.h"
#include "sys.h" 
#include "infrared_tube.h"


/**
* @brief 红外循迹四个GPIO的初始化
* @param 
* @return 
*/
void TCRT5000_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);//使能PORTF时钟
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12| GPIO_Pin_13| GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //默认下拉	  
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
