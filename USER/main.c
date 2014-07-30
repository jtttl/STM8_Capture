/******************** (C) COPYRIGHT  ���iCreateǶ��ʽ���������� **************
 * �ļ���  ��main.c
 * ����    ��TIM1���벶׽ʵ��   
 * ʵ��ƽ̨�����STM8������
 * ��汾  ��V2.1.0
 * ����    �����  QQ��779814207
 * ����    ��
 * �Ա�    ��http://shop71177993.taobao.com/
 * �޸�ʱ�� ��2012-11-5

  ���STM8������Ӳ������
  �ڲ�128KHzʱ��Դ����--PE0
  TIM1���벶׽ͨ��4-----PC4
  ˵������Ҫͨ���Ű��߽�PE0��PC4���ӣ���TIM1�����벶׽ͨ��1����128KHz���ź�

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

	/* �����ⲿ24M����Ϊϵͳ��ʱ�� */
	SystemClock_Init(HSE_Clock);
			
	/* ʹ�� LSI ʱ�ӣ�PE0�������*/
	//GPIO_Init(GPIOE, GPIO_PIN_0, GPIO_MODE_OUT_OD_LOW_FAST);
	//CLK_CCOConfig(CLK_OUTPUT_LSI);
	//CLK_CCOCmd(ENABLE);
	
	Uart1_Init();
    
    UART1_printf("\rUart initialed!\r\n");
    
	TIM1_Capture_Init();	/* ��ʼ��TIM1���벶��ͨ�� */
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

/******************* (C) COPYRIGHT ���iCreateǶ��ʽ���������� *****END OF FILE****/

