/***************** (C) COPYRIGHT  风驰iCreate嵌入式开发工作室 ******************
 * 文件名  ：tim1_ic.c
 * 描述    ：输入捕捉TIM1配置库
 * 实验平台：iCreate STM8开发板
 * 库版本  ：V2.1.0
 * 作者    ：风驰  QQ:779814207
 * 博客    ：
 * 修改时间 ：2011-12-20
*******************************************************************************/

/* 包含系统头文件 */

/* 包含自定义头文件 */
#include "tim1_ic.h"
/* 自定义新类型 */

/* 自定义宏 */

/* 全局变量定义 */
/*******************************************************************************
 * 名称: TIM1_Capture_Init
 * 功能: TIM1输入捕捉初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void TIM1_Capture_Init(void)
{
    TIM1_DeInit();          //复位
     
    TIM1->CR1   |= 0x01;    //向上计数；使能计数器

    TIM1->SMCR  |= 0X64;    //选源触发源ti2fp2  
                            //上升沿时计数器清0  
    TIM1->CCMR1 |= 0x02;    //ch2映射到ti2fp1
    TIM1->CCMR2 |= 0x01;    //ch2映射到ti2fp2
     
    TIM1->CCER1 |= 0x13;    //IC1和IC2捕获使能；ti2fp2上升沿；ti2fp1下降沿  
    TIM1->IER   |= 0x06;    //允许CC1和CC2捕获中断
     
    TIM1_Cmd(ENABLE);
}

int average(int values[], u8 len)
{
    int sum = 0;
    int i;
    
    for(i = 0; i < len; i++)
        sum += values[i];   
    
    return sum / len;
}

