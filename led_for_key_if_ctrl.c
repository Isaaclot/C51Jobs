
#include "reg51.h"
#include "intrins.h"

#define uint unsigned int 
#define uchar unsigned char

sbit   k1=P1^4;	 //Define key match to port
sbit   k2=P1^5;
sbit   k3=P1^6;
sbit   k4=P1^7;

void DelayMS(uint presetTime){		//An inner Interface avoid for incorrect operation
	uchar i;
	while(presetTime--){
		for (i = 0; i < 120; ++i)
		{
			/* code */
		}
	}
}


void main(int argc, char const *argv[])
{
	/* code */
	P0=0xfe;	//initiate port(p0&p2)
	P2=0xfe;
	P1=0xff;	//initiate port(p1):set ReadyStatus


	while(1){
		/*Get focus on loop*/
		if (k1==0)
		{
			/* code */
			DelayMS(10);	//Earn more time Guarantee your correct operaion
			if (k1==0)
			{
				/* code */
				P0=_cror_(P0,1);	//Move to right
			}
		}
		if (k2==0)
		{
			/* code */
			DelayMS(10);
			if (k2==0)
			{
				/* code */
				P0=_crol_(P0,1);	//Move to left
			}
		}
		if (k3==0)
		{
			/* code */
			DelayMS(10);
			if (k3==0)
			{
				/* code */
				P2=_cror_(P2,1);	//Move to right
			}
		}
		if (k4==0)
		{
			/* code */
			DelayMS(10);
			if (k4==0)
			{
				/* code */
				P2=_crol_(P2,1);	//Move to left
			}
		}


	}

}