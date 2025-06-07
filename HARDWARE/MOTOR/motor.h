#ifndef __MOTOR_H
#define __MOTOR_H	
#include "sys.h"

#define IN1_1 PFout(0)
#define IN2_1 PFout(1)
#define IN3_1 PFout(2)
#define IN4_1 PFout(3)

#define IN1_2 PFout(4)
#define IN2_2 PFout(5)	
#define IN3_2 PFout(6)
#define IN4_2 PFout(7)

void L298N_GPIO_Init(void);
void Forward(void);
void Backward(void);
void Rightward(void);
void Leftward(void);

#endif
