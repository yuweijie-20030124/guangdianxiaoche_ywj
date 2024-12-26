	#include<AT89X52.H>		 
	#include<PWM.H>		 
	#include "LCD1602.h"
	
	//BUZZ=1灭 
	//BUZZ=0响
	
void Delay200us()		//@11.0592MHz
{
	unsigned char i;

	i = 89;
	while (--i);
}

	
						int trees_num=0;
						int tunnel_dis=0;

void Tracking()
{	
	if(data1 == 0&&data2 == 0&&data3 == 0||data1 == 1&&data2 == 0&&data3 == 1||data1 == 1&&data2 == 1&&data3 == 1)
	{
		run();
	}
	else
	{
		if(data1 == 0&&data2 == 1&&data3 == 0)
		{
			stop();	
		}
	 	if(data1 == 1&&data2 == 0&&data3 == 0||data1 == 1&&data2 == 1&&data3 == 0)
		{
			rightrun();
		}
		if(data1 == 0&&data2 == 0&&data3 == 1||data1 == 0&&data2 == 1&&data3 == 1)
		{
			leftrun();
		}
		
	}
}

//主函数
	void main(void)
{	
					TMOD=0X01;
        	TH0= 0XFc;		  //1ms定时
         	TL0= 0X18;
          TR0= 1;
        	ET0= 1;
	        EA = 1;			   //开总中断
					LCD_Init();

					LCD_ShowString(1,1,"trees:");
					LCD_ShowString(2,1,"t_dis:");
					LCD_ShowString(2,9,"cm");

	while(1)	//无限循环
	{ 	 	
				LCD_ShowNum(1,7,trees_num,2);	
				LCD_ShowNum(2,7,tunnel_dis,2);
		
				if(LeftIRBZ==0)			
		{		
				Delay200us();
				while(LeftIRBZ==0);	
				trees_num++;
				Delay200us();
		}
				if(RightIRBZ==0)			
		{		
				Delay200us();
				while(RightIRBZ==0);	
				trees_num++;
				Delay200us();
		}

		Tracking();
									
	}	 
	 
}
