	#include<AT89X52.H>		 
	#include<PWM.H>		 
	#include "LCD1602.h"
	
	
	//BUZZ=1灭 
	//BUZZ=0响
	
//主函数
	void main(void)
{	
					TMOD=0X01;
        	TH0= 0XFc;		  //1ms定时
         	TL0= 0X18;
          TR0= 1;
        	ET0= 1;
	        EA = 1;			   //开总中断

	while(1)	//无限循环
	{ 	 
				LCD_ShowChar(1,1,"h");
			 //有信号为0  没有信号为1 IRBZ		if( LeftIRBZ == 0 || RightIRBZ == 0 )  led == 0是说明识别到了
			 	if(Left_1_led==0&&Right_1_led==0)		//黑线在正中间
			   {
				   BUZZ=1;
			     //run();   //调用前进函数	
					 stop();
				 }			              
									//if( LeftIRBZ == 1 && RightIRBZ == 0 )
				else if(Left_1_led==1&&Right_1_led==0)	    //左边检测到黑线
			 	 {
					 BUZZ=1;
				 	 leftrun();		  //调用小车左转  函数
			     }
									
										//if( LeftIRBZ == 0 && RightIRBZ == 1 )
				else if(Right_1_led==1&&Left_1_led==0)		//右边检测到黑线
				  {	  
						BUZZ=1;
				    rightrun();		   //调用小车右转	函数
				  }
								//if( LeftIRBZ == 0 && RightIRBZ == 0 )
				else if(Right_1_led==1&&Left_1_led==1)		//左右都是黑线，小车进入隧道
				  {	  
				    BUZZ=1;
						stop();
				  }

	}	 
	 
}