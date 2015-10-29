

#include "reg51.h"
#include "intrins.h"

#define uint unsigned int
#define uchar unsigned char

sbit K1=P1^4;
sbit K2=P1^5;
sbit K3=P1^6;
sbit K4=P1^7;

void DelayMS(uint presetTime){		//An inner Interface avoid for incorrect operation
	uchar i;
	while(presetTime--){
		for (i = 0; i < 120; ++i)
		{
			/* code */
		}
	}
}

void matchStatus(P1Status){		//An interface Match to key status,feedback led status
	switch (P1Status)
		 {
		 	case  0xef:{P0=_cror_(P0,1);}	 break;
		    case  0xdf:{P0=_crol_(P0,1);}	 break;
			case  0xbf:{P2=_cror_(P2,1);}	 break;
			case  0x7f:{P2=_crol_(P2,1);}	 
		 }
}

void main(int argc, char const *argv[])
{
	/* code */
	P0=0xfe;	//initiate port(p0&p2)
	P2=0xfe;
	P1=0xff;	//initiate port(p1):set ReadyStatus

	while(1){
		matchStatus(P1);
		DelayMS(150);
	}
}