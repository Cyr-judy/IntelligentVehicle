#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"


extern 	int time ;
extern 	int Distance ;
	

void TIM3_Int_Init(u16 arr,u16 psc);
void TIM2_PWM_Init(u16 arr,u16 pac);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM4_PWM_Init(u16 arr,u16 pac);
void TIM4_Cap_Init(u16 arr,u16 psc);
int SR04_Distance(void);


#endif
