#include <REGX51.H>

sbit sw = P1^0;
sbit sw1 = P1^1;
sbit sw2 = P1^2;
sbit motor_D1 = P2^0;
sbit motor_D2 = P2^1;
sbit led = P2^4;


void delay (unsigned del);
void motor_clk_Direction (void);
void motor_non_clk_Direction (void);
void motor_stop (void);
void start (void);

void main(void){
	
	
	while(1){
		
		if ( sw == 0){motor_stop();start();motor_clk_Direction(); sw1 = sw2=1;}
		if ( sw1 == 0){motor_stop();start();motor_non_clk_Direction();sw = sw2=1;}
		if ( sw2 == 0){motor_stop(); sw1 = sw =1;}
	}
	
	}
	



void motor_clk_Direction (void){
	motor_D1 = 1;
	motor_D2 = 0;
}

void motor_non_clk_Direction (void){
	  motor_D1 = 0;
	  motor_D2 = 1;
}
void motor_stop (void){
	  motor_D1 = 0;
	  motor_D2 = 0;
}
void start (void){
	unsigned i = 0;
	for(i=0;i<5;i++){
		led = ~led;
		delay(8);
	}
	  
}

void delay (unsigned del){
	
	unsigned loop = 0;
	unsigned delay_gen = 0;
	
	for(loop=0;loop<del;loop++){
		for(delay_gen=0;delay_gen<10000;delay_gen++);
	}

}