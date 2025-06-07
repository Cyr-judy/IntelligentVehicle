#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "motor.h"
#include "timer.h"
#include "exti.h"
#include "key.h"
#include "infrared_tube.h"
#include "oled.h"
#include "adc.h"
#include "ultrasound.h"

int g_USART1_FLAG =0;

extern u8  TIM4CH2_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM4CH2_CAPTURE_VAL;	//输入捕获值	
int Mode = 0;

u8 string[10] = {0};	//定义在前面
float pitch =1.2;
int time = 0;
int Distance = 0;

 int main(void)
 {	
	u16 adcx;
	float temp;
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_init();	    //延时函数初始化	  
	uart1_init(115200);
	LED_Init();		  	//初始化与LED连接的硬件接口
	L298N_GPIO_Init();
  EXTIX_Init();
	TCRT5000_Init();
  OLED_Init();
  OLED_Clear();
	SR04_GPIO_Init(); //超声波PA0
	Adc_Init();		  		//ADC初始化
	 
	TIM4_PWM_Init(999,1439);   //舵机PWM 
	 
	TIM2_PWM_Init(1999,359); //电机的PWM 
	TIM3_PWM_Init(1999,359);
	TIM_SetCompare1(TIM3,500);	 
	TIM_SetCompare2(TIM3,500);
	TIM_SetCompare3(TIM2,500);	 
	TIM_SetCompare4(TIM2,500);
	
	TIM4_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计数 
	
	while(1)
	{
    Forward();
    delay_ms(300);
		LED0=~LED0;
		delay_ms(300);
  }
	
//	while(1)
//	{
//		//OLED 显示ADC测量
//		adcx=Get_Adc_Average(ADC_Channel_1,10);
//		temp=(float)adcx*(3.3/4096);
//		sprintf((char *)string,"U:%.2f   ",(temp*5));
//		OLED_ShowString(12,0,string,16);	
//    OLED_Refresh_Gram();	
//		
//		//OLED显示距离功能
//		sprintf((char *)string,"Distance:%d      ",SR04_Distance());
//		OLED_ShowString(12,3,string,16);
//		OLED_Refresh_Gram();
//		
//		//OLED显示模式功能
//		sprintf((char *)string,"Mode:%d   ",Mode);
//		OLED_ShowString(12,6,string,16);
//		OLED_Refresh_Gram();
//		
//		//串口输出
//		UsartPrintf(USART3,"Mode:%d\r\n",Mode);
//		UsartPrintf(USART3,"U:%.2f\r\n",(temp*5));
//		UsartPrintf(USART3,"D:%d \r\n",SR04_Distance());
//		
//		//停止模式
//		if(Mode == 0)
//		{
//			TIM_SetCompare1(TIM3,80);	 //舵机向前 使超声波朝前方 
//			delay_ms(200);
//			IN1_1 =0;
//			IN2_1 =0;
//			IN3_1 =0;
//			IN4_1 =0;	
//      IN1_2 =0;
//			IN2_2 =0;
//			IN3_2 =0;
//			IN4_2 =0;				
//		}	
//		
//		//定距离跟随
//		if(Mode == 1)
//		{
//			if(SR04_Distance()>20)
//			{
//				Forward();
//				delay_ms(50);
//			}
//			if(SR04_Distance()<15)
//			{
//				Backward();
//				delay_ms(50);
//			}
//			IN1_1 =0;
//			IN2_1 =0;
//			IN3_1 =0;
//			IN4_1 =0;	
//      IN1_2 =0;
//			IN2_2 =0;
//			IN3_2 =0;
//			IN4_2 =0;			
//		}
//		
//		//蓝牙遥控
//		if(Mode == 2)
//		{
//			if(g_USART1_FLAG == 1)//前
//			{
//				LED0 = ~LED0;
//				Forward();
//				delay_ms(100);
//			}
//			if(g_USART1_FLAG == 2)//后
//			{
//				LED1 = ~LED1;
//				Backward();
//				delay_ms(100);
//			}
//			if(g_USART1_FLAG == 3)//右
//			{
//				LED0 =~LED0;
//				Rightward();
//				delay_ms(100);	
//			}
//			if(g_USART1_FLAG == 4)//左
//			{
//				LED1 =~LED1;
//				Leftward();
//				delay_ms(100);
//			}
//			if(g_USART1_FLAG == 5)//停止
//			{
//				LED0 = ~LED0;
//				LED1 = ~LED1;
//				IN1_1 =0;
//				IN2_1 =0;
//				IN3_1 =0;
//				IN4_1 =0;	
//				IN1_2 =0;
//				IN2_2 =0;
//				IN3_2 =0;
//				IN4_2 =0;						
//			}
//		}
//		
//		//超声波避障
//		if(Mode == 3)
//		{
//			TIM_SetCompare1(TIM3,80);	 //舵机向前 使超声波朝前方 
//			delay_ms(200);
//			if(SR04_Distance()>25)// 前方无障碍物
//			{
//				Forward();
//				delay_ms(500);
//			}
//			
//			if(SR04_Distance()<25)  //向前有障碍物
//			{
//				TIM_SetCompare1(TIM3,50);	 //舵机向右边转大约30度
//				delay_ms(200);
//				if(SR04_Distance()>25)//右侧无障碍物判断
//				{
//					Rightward();
//					delay_ms(700);
//				}
//				else 
//				{ //右边有障碍物
//					TIM_SetCompare1(TIM3,110); //舵机向左边转大约30度
//					delay_ms(200);
//					if(SR04_Distance()>25)//左侧无障碍物
//					{
//						Leftward();
//						delay_ms(700);	
//					}
//					else
//					{
//						Backward();//后退
//						delay_ms(700);
//						Rightward(); //右转
//						delay_ms(700);
//					}											
//			 }
//			}					
//		}	
//		
//		//红外对管循迹
//		if(Mode == 4)
//		{
//			if(HW_1 == 0 && HW_2 == 0 && HW_3 == 0 && HW_4 == 0)
//			{
//				Forward();
//				delay_ms(50);
//			}
//			if(HW_1 == 0 && HW_2 == 1 && HW_3 == 0 && HW_4 == 0)
//			{
//				Rightward();
//				delay_ms(150);
//			}
//			if(HW_1 == 1 && HW_2 == 0 && HW_3 == 0 && HW_4 == 0)
//			{ 
//				Rightward();
//				delay_ms(250);
//			}
//			if(HW_1 == 1 && HW_2 == 1 && HW_3 == 0 && HW_4 == 0)
//			{
//				Rightward();
//				delay_ms(300);
//			}
//			if(HW_1 == 0 && HW_2 == 0 && HW_3 == 1 && HW_4 == 0)
//			{
//				Leftward();
//				delay_ms(150);
//			}
//			if(HW_1 == 0 && HW_2 == 0 && HW_3 == 0 && HW_4 == 1)
//			{
//				Leftward();
//				delay_ms(250);
//			}
//			if(HW_1 == 0 && HW_2 == 0 && HW_3 == 1 && HW_4 == 1)
//			{
//				Leftward();
//				delay_ms(300);
//			}
//		}
//	}
 }


