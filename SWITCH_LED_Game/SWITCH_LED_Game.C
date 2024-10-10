#include <REGX51.H>

sbit sw = P1^0;
sbit led = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
sbit led4 = P2^4;

void delay (unsigned del);
void game1 (void);
void game2 (void);
void start (void);

void main(void){
	
	int flag = 1;
	int st =0;
	start();
	while(1){
		
		if ( sw == 0){if(flag==1){start();};flag=0; game2();}
		if ( sw == 1){if(flag==1){start();};flag=0;led=led1=led2=led3=led4=0;game1();}
	}
	
	}
	



void game1 (void){
	
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
		led4 = ~led4;	
		delay(16);
		led4 = ~led4;	
}

void game2 (void){
	  led = ~led ;
		delay(16);
		
		led1 = ~led1 ;
		delay(16);
		
		led2 = ~led2 ;
		delay(16);
		
		led3 = ~led3;
		delay(16);
			
		led4 = ~led4;	
		delay(16);
}
void start (void){
	unsigned i = 0;
	for(i=0;i<5;i++){
		led=led1=led2=led3=led4=1;
		delay(8);
		led=led1=led2=led3=led4=0;
	}
	  
}

void delay (unsigned del){
	
	unsigned loop = 0;
	unsigned delay_gen = 0;
	
	for(loop=0;loop<del;loop++){
		for(delay_gen=0;delay_gen<10000;delay_gen++);
	}

}