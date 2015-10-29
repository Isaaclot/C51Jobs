
#include "reg51.h"
#include "intrins.h"

#define uchar unsigned char
#define uint  unsigned char



sbit K1=P1^0;
sbit K2=P1^1;
sbit K3=P1^2;
sbit K4=P1^3;

void DelayMS(uint presetTime){		//An inner Interface avoid for incorrect operation
	uchar i;
	while(presetTime--){
		for (i = 0; i < 120; ++i)
		{
			/* code */
		}
	}
}

void keyInteration(uint status){	//Search the Status of key, feedback status on LED
	switch(status){
		case 0xef:{P0=_cror_(P0,1);} break;	//Move to the right
		case 0xdf:{P0=_crol_(P0,1);} break;
		case 0xbf:{P2=_cror_(P2,1);} break;	//Move to the left
		case 0x7f:{P2=_crol_(P2,1);} ;

	}
}

void main(){  	//Interface
	P0=0xfe;	//initiate port(p0&p2)
	P2=0xfe;
	P1=0xff;	//initiate port(p1):set ReadyStatus

	while(1){
		keyInteration(P1);
		DelayMS(150);
	}
	
}