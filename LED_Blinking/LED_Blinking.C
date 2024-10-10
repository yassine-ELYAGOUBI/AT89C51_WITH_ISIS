#include <REGX51.H>
sbit led = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;

void delay (unsigned del);


void main(void){
	
	led=led1=led2=led3=0;
	
	while(1){
	led = ~led ;
	delay(16);
	led = ~led ;	
	led1 = ~led1 ;
	delay(16);
	
	led1 = ~led1 ;
	led2 = ~led2 ;
	delay(16);
	
	led2 = ~led2 ;
	led3 = ~led3;
	delay(16);
	led3 = ~led3;
		
		
	
	}
	
}



void delay (unsigned del){
	
	unsigned loop = 0;
	unsigned delay_gen = 0;
	
	for(loop=0;loop<del;loop++){
		for(delay_gen=0;delay_gen<10000;delay_gen++);
	}

}