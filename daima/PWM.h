#ifndef _LED_H_
#define _LED_H_


    //����С������ģ������IO�� 
	sbit IN1=P2^4;
	sbit IN2=P2^5;
	sbit IN3=P2^6;
	sbit IN4=P2^7;
	sbit EN1=P2^1;
	sbit EN2=P2^2;
	

	/***���������߶���*****/
    sbit BUZZ=P2^3;
 
	
    #define data1         P0_6	 //��ѭ��������
		
    #define data2     	  P0_5	 //�м�ѭ��������

    #define data3         P0_4	 //��ѭ��������
			
    #define LeftIRBZ          P3_4	 //����ϴ�����	
	
		#define RightIRBZ         P3_5	 //�ұ��ϴ�����	  
   
		#define Left_moto_pwm	  P2_1	 //PWM�źŶ�

		#define Right_moto_pwm	  P2_2	 //PWM�źŶ�
	
	#define Left_moto_go      {P2_4=1,P2_5=0;}  //������ǰ��
	#define Left_moto_back    {P2_4=0,P2_5=1;} 	//��ߵ�����ת
	#define Left_moto_Stop    {P2_4=0,P2_5=0;}  //��ߵ��ͣת                     
	#define Right_moto_go     {P2_6=1,P2_7=0;}	//�ұߵ����ǰ��
	#define Right_moto_back   {P2_6=0,P2_7=1;}	//�ұߵ�������
	#define Right_moto_Stop   {P2_6=0,P2_7=0;}  //�ұߵ��ͣת   

	unsigned char pwm_val_left  =0;							//��������
	unsigned char push_val_left =0;							// ����ռ�ձ�N/20
	unsigned char pwm_val_right =0;
	unsigned char push_val_right=0;							// �ҵ��ռ�ձ�N/20
	bit Right_moto_stop=1;
	bit Left_moto_stop =1;
	unsigned  int  time=0;
   
/************************************************************************/	
//��ʱ����	
   void delay(unsigned int k)
{    
     unsigned int x,y;
	 for(x=0;x<k;x++) 
	   for(y=0;y<2000;y++);
}
/************************************************************************/
//ǰ��ǰ��
     void  run(void)
{
   push_val_left=5;	 //�ٶȵ��ڱ��� 0-20������0��С��20���
	 push_val_right=5;
	 Left_moto_go ;   //������ǰ��
	 Right_moto_go ;  //�ҵ����ǰ��
}

//���˺��� 
     void  backrun(void)
{
     push_val_left=10;	 //�ٶȵ��ڱ��� 0-20������0��С��20���
	 push_val_right=10;
	 Left_moto_back;   //����������
	 Right_moto_back;  //�ҵ��������
}

//��ת
     void  leftrun(void)
{	 
     push_val_left=0.01;
	 push_val_right=0.01;
	 Right_moto_go ;  //�ҵ����ǰ��
     Left_moto_back   ;  //��������
}

//��ת
     void  rightrun(void)
{ 
	 push_val_left=0.01;
	 push_val_right=0.01;
     Left_moto_go  ;   //������ǰ��
	 Right_moto_back    ;  //�ҵ��������	
}

//ֹͣ
     void  stop(void)
{	 
     
	 Right_moto_Stop ;  //�ҵ��ֹͣ
     Left_moto_Stop  ;  //����ֹͣ
}

/************************************************************************/
/*                    PWM���Ƶ��ת��                                   */
/************************************************************************/
/*                    ��������                                        */
/*����push_val_left��ֵ�ı���ת��,ռ�ձ�            */
		void pwm_out_left_moto(void)
{  
   if(Left_moto_stop)
   {
    if(pwm_val_left<=push_val_left)
	       {
		     Left_moto_pwm=1; 
//		     Left_moto_pwm1=1; 
		   }
	else 
	       {
	         Left_moto_pwm=0;
//		     Left_moto_pwm1=0; 
		   }
	if(pwm_val_left>=20)
	       pwm_val_left=0;
   }
   else    
          {
           Left_moto_pwm=0;
//           Left_moto_pwm1=0; 
		  }
}
/******************************************************************/
/*                    �ҵ������                                  */  
   void pwm_out_right_moto(void)
{ 
  if(Right_moto_stop)
   { 
    if(pwm_val_right<=push_val_right)
	      {
	       Right_moto_pwm=1; 
//		   Right_moto_pwm1=1; 
		   }
	else 
	      {
		   Right_moto_pwm=0;
//		   Right_moto_pwm1=0; 
		  }
	if(pwm_val_right>=20)
	       pwm_val_right=0;
   }
   else    
          {
           Right_moto_pwm=0;
//           Right_moto_pwm1=0; 
	      }
}
       
/***************************************************/
///*TIMER0�жϷ����Ӻ�������PWM�ź�*/
 	void timer0()interrupt 1   using 2
{
     TH0=0XFc;	  //1Ms��ʱ
	 TL0=0X18;
	 time++;
	 pwm_val_left++;
	 pwm_val_right++;
	 pwm_out_left_moto();
	 pwm_out_right_moto();
 }	

/*********************************************************************/	

#endif