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
//ALIENTEK 探索者STM32F407开发板 实验35
//摄像头 实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

u8 ov2640_mode=0;						//工作模式:0,RGB565模式;1,JPEG模式

#define pic_buf_size 3000//43008  			//
u8 pic_buf[pic_buf_size*4];	//
u8 pic_buf2[4];





//RGB565测试
//RGB数据直接显示在LCD上面
void rgb565_test(void)
{ 



	
	
	My_DCMI_Init();			//DCMI配置
	//DMA_Memory0BaseAddr:存储器地址
	//DMA_BufferSize:存储器长度    
	//DMA_MemoryDataSize:存储器位宽 
	//DMA_MemoryInc:存储器增长方式  
	DCMI_DMA_Init((u32)pic_buf,pic_buf_size,DMA_MemoryDataSize_Word,DMA_MemoryInc_Enable);//DCMI DMA配置  
	DCMI_Start();//传输完成后会进入帧中断DCMI_IRQHandler
	while(1);
	
} 
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	rgb565_test(); 
}
