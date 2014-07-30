/******************** (C) COPYRIGHT  风驰iCreate嵌入式开发工作室 **************
 * 文件名  ：main.c
 * 描述    ：TIM1输入捕捉实验   
 * 实验平台：风驰STM8开发板
 * 库版本  ：V2.1.0
 * 作者    ：风驰  QQ：779814207
 * 博客    ：
 * 淘宝    ：http://shop71177993.taobao.com/
 * 修改时间 ：2012-11-5

  风驰STM8开发板硬件连接
  内部128KHz时钟源引脚--PE0
  TIM1输入捕捉通道4-----PC4
  说明：需要通过杜邦线将PE0与PC4连接，用TIM1的输入捕捉通道1来测128KHz的信号

*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "sysclock.h"
#include "tim1_ic.h"
#include "uart1.h"


/* Private defines -----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
unsigned int IC2Value,IC1Value;

u16 channel = 1;

int main(void)
{

	/* 设置外部24M晶振为系统主时钟 */
	SystemClock_Init(HSE_Clock);
			
	/* 使能 LSI 时钟，PE0引脚输出*/
	//GPIO_Init(GPIOE, GPIO_PIN_0, GPIO_MODE_OUT_OD_LOW_FAST);
	//CLK_CCOConfig(CLK_OUTPUT_LSI);
	//CLK_CCOCmd(ENABLE);
	
	Uart1_Init();
    
    UART1_printf("\rUart initialed!\r\n");
    
	TIM1_Capture_Init();	/* 初始化TIM1输入捕获通道 */
    UART1_printf("\rTimer initialed!\r\n");
    
    UART1_printf("\r3\r\n");
    UART1_printf("\r2\r\n");
    UART1_printf("\r1\r\n");
    UART1_printf("\rLoading..........\r\n");
    UART1_printf("\rReady.\r\n");

    UART1_printf("\rWaiting for task.\r\n");

	enableInterrupts(); 
	while(1)
        ;
}




#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    
    /* Infinite loop */
    while (1)
    {
    }
}
#endif

/******************* (C) COPYRIGHT 风驰iCreate嵌入式开发工作室 *****END OF FILE****/

