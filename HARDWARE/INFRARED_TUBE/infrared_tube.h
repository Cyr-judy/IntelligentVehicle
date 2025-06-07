#ifndef __INFRARED_TUBE_H
#define __INFRARED_TUBE_H
#include "sys.h"

#define HW_1  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12)//读取红外对管
#define HW_2  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_13)//读取红外对管
#define HW_3  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_14)//读取红外对管
#define HW_4  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15)//读取红外对管

void TCRT5000_Init(void);

#endif
