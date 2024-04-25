/*
 * HCALC_prog.c

 *
 *  Created on: Mar 10, 2023
 *      Author: hp
 */
#include"../../LIB/STD_TYPES1.h"
#include "../../MCAL/dio/dio_init.h"
#include "../../HALL/LCD/LCD_init.h"
#include"../../HALL/KDP/KDP_Init.h"
#include"util/delay.h"
#include"CALC_init.h"
void HCALC_vCalculate(void){


	HLCD_vLCDInit();
		u8 maxelem=0;
		u8 arr[50];
	    u8 elem;
	    u8 op=1;


		while(1)
		{
			while(1){
			HKPD_vKDOInit();
			 elem=HKPD_GetPressedKey();
			if(elem==255)
				continue;
			arr[maxelem++]=elem;
			HLCD_vSendData(elem);
	          if(elem=='=')
	          {arr[maxelem++]=elem;
	        	  break;
	          }
			}

			for(int x=1;x<=maxelem;x++)
			{
				if(arr[x]=='-'||arr[x]=='+'||arr[x]=='*'||arr[x]=='/')
	               break;
	            op++;

			}


	           if(arr[op]=='+')
	           {
        	   s32 num1=dig1(arr,op);
	        	  s32 num2=dig2(arr,op);
			 s32 num3=num1+num2;
			 HLCD_vSendNum(num3);
	           }



	           if(arr[op]=='*')
	                      {
	        	         s32 num1=dig1(arr,op);
	        	   		 s32 num2=dig2(arr,op);
	        	   		 s32 num3=num1*num2;
	        	   		 HLCD_vSendNum(num3);
	                      }
	           if(arr[op]=='/')
	                      {
	        	   s32 num1=dig1(arr,op);
	        	           	   		 s32 num2=dig2(arr,op);
	        	           	   		 if(num2==0)
	        	           	   			 HLCD_vSendStr("error");
	        	           	   		 else{
	        	   		 s32 num3=num1/num2;
	        	   		 HLCD_vSendNum(num3);}
	           		            }
	           if(arr[op]=='-')
	                                {
	        	   s32 num1=dig1(arr,op);
	        	           	   		 s32 num2=dig2(arr,op);
	        	   		 s32 num3=num1-num2;
	        	   		 HLCD_vSendNum(num3);
	                     		            }

	          while(1)
	          {HKPD_vKDOInit();
	        	  u8 ke=HKPD_GetPressedKey();
	        	  if(ke==255)
	        	  			continue;
	                if(ke=='c')
	                {
	                  HLCD_vClear();
	                  maxelem=0;
	                  //arr[0]='\0';
	                  elem=255;
	                  op=1;
	                  break;
	     }
	  }
	}
}
s32 dig1(u8 arr[],u8 j)
{
	s32 num1=0;

	if(arr[0]=='-')
	{ num1=num1+(arr[1]-'0');
		for(int i=2;i<j;i++){
			 num1=num1*10;
		 num1=num1+(arr[i]-'0');

		}
		return -num1;
	}

		else
		{num1=num1+(arr[0]-'0');
		for(int i=1;i<j;i++){
			 num1=num1*10;
		 num1=num1+(arr[i]-'0');

		}
		return num1;

		}

}
s32 dig2(u8 arr[],u8 j)
{
	s32 num2=0;
	u8 i=j+1;
	if(arr[i]=='-')
	{num2=num2+(arr[i+1]-'0');
	  while(arr[i+2]!='=')
	  {num2=num2*10;
	   num2=num2+(arr[i+2]-'0');
	   i++;
       }
	  return -num2;
}
else
{

		num2=num2+(arr[i]-'0');
		  while(arr[i+1]!='=')
		  {num2=num2*10;
		   num2=num2+(arr[i+1]-'0');
		   i++;
	       }
		  return num2;

}
}
