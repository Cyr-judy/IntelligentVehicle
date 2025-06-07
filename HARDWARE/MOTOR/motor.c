#include "motor.h"

/**
* @brief 初始2个L298N的 IN1 IN2 IN3 IN4
* @param 
* @return 
*/
void L298N_GPIO_Init(void)
{ 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);	 //使能PF端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;	    		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOF, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7); 						
}


/**
* @brief 向前无延时
* @param 
* @return 
*/
void Forward(void)
{
		IN1_1 =1;
		IN2_1 =0;
	  IN3_1 =1;
		IN4_1 =0;
		IN1_2 =1;
		IN2_2 =0;
	  IN3_2 =1;
		IN4_2 =0;
		TIM_SetCompare1(TIM3,1500);	 
	  TIM_SetCompare2(TIM3,1500);
	  TIM_SetCompare3(TIM2,1500);	 
	  TIM_SetCompare4(TIM2,1500);
}	


/**
* @brief 向后无延时
* @param 
* @return 
*/
void Backward(void)
{
		IN1_1 =0;
		IN2_1 =1;
	  IN3_1 =0;
		IN4_1 =1;
		IN1_2 =0;
		IN2_2 =1;
	  IN3_2 =0;
		IN4_2 =1;
		TIM_SetCompare1(TIM3,1500);	 
	  TIM_SetCompare2(TIM3,1500);
	  TIM_SetCompare3(TIM2,1500);	 
	  TIM_SetCompare4(TIM2,1500);
}	


/**
* @brief 向右无延时
* @param 
* @return 
*/
void Rightward(void)
{
		IN1_1 =1;
		IN2_1 =0;
	  IN3_1 =1;
		IN4_1 =0;
		IN1_2 =0;
		IN2_2 =1;
	  IN3_2 =0;
		IN4_2 =1;
		TIM_SetCompare1(TIM3,1500);	 
	  TIM_SetCompare2(TIM3,1500);
	  TIM_SetCompare3(TIM2,1500);	 
	  TIM_SetCompare4(TIM2,1500);
}	


/**
* @brief 向左无延时
* @param 
* @return 
*/
void Leftward(void)
{
		IN1_1 =0;
		IN2_1 =1;
	  IN3_1 =0;
		IN4_1 =1;
		IN1_2 =1;
		IN2_2 =0;
	  IN3_2 =1;
		IN4_2 =0;
	  TIM_SetCompare1(TIM3,1500);	 
	  TIM_SetCompare2(TIM3,1500);
	  TIM_SetCompare3(TIM2,1500);	 
	  TIM_SetCompare4(TIM2,1500);
}	
