#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"  
#include "usart2.h"  
#include "timer.h" 
#include "ov2640.h" 
#include "dcmi.h" 
//ALIENTEK ̽����STM32F407������ ʵ��35
//����ͷ ʵ�� -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

u8 ov2640_mode=0;						//����ģʽ:0,RGB565ģʽ;1,JPEGģʽ

#define pic_buf_size 3000//43008  			//
u8 pic_buf[pic_buf_size*4];	//
u8 pic_buf2[4];





//RGB565����
//RGB����ֱ����ʾ��LCD����
void rgb565_test(void)
{ 



	
	
	My_DCMI_Init();			//DCMI����
	//DMA_Memory0BaseAddr:�洢����ַ
	//DMA_BufferSize:�洢������    
	//DMA_MemoryDataSize:�洢��λ�� 
	//DMA_MemoryInc:�洢��������ʽ  
	DCMI_DMA_Init((u32)pic_buf,pic_buf_size,DMA_MemoryDataSize_Word,DMA_MemoryInc_Enable);//DCMI DMA����  
	DCMI_Start();//������ɺ�����֡�ж�DCMI_IRQHandler
	while(1);
	
} 
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	rgb565_test(); 
}
