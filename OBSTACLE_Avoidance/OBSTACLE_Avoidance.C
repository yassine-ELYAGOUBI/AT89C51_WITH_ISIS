#include <REGX51.H>

sbit R_sensor = P1^0;
sbit F_sensor = P1^1;
sbit L_sensor = P1^2;
sbit motorR_D1 = P2^0;
sbit motorR_D2 = P2^1;
sbit motorL_D1 = P2^2;
sbit motorL_D2 = P2^3;
sbit led = P2^4;


void delay (unsigned del);
void motorR_clk_Direction (void);
void motorR_non_clk_Direction (void);
void motorR_stop (void);
void motorL_clk_Direction (void);
void motorL_non_clk_Direction (void);
void motorL_stop (void);
void start (void);

void main(void){
	
	R_sensor = 0;
	F_sensor = 0;
	L_sensor = 0;
	
	while(1){
		
		if ( R_sensor == 0 && L_sensor == 1 && F_sensor == 0){
			
			motorR_clk_Direction();
			motorL_stop();
		}
		if ( R_sensor == 1 && L_sensor == 0 && F_sensor == 0){
			
			motorL_clk_Direction();
			motorR_stop();
		}
		
		if ((R_sensor == 0 && L_sensor == 0 && F_sensor == 0) || (R_sensor == 1 && L_sensor == 1 && F_sensor == 0)){
			
			motorR_clk_Direction();
			motorL_clk_Direction();
		}
		if ( (R_sensor == 0 && L_sensor == 0 && F_sensor == 1) || ( R_sensor == 0 && L_sensor == 1 && F_sensor == 1)){
			
			
			motorL_stop();
			motorR_clk_Direction();			
		}
		
		if ( R_sensor == 1 && L_sensor == 0 && F_sensor == 1){
			
			motorR_stop();
			
			
			motorL_clk_Direction();
		}
		if ( R_sensor == 1 && L_sensor == 1 && F_sensor == 1){
			
			motorR_stop();
			motorL_stop();
			start();
		}
		
	}
	}
	


//  RIGHT MOTOR
void motorR_clk_Direction (void){
	motorR_D1 = 1;
	motorR_D2 = 0;
}
void motorR_non_clk_Direction (void){
	  motorR_D1 = 0;
	  motorR_D2 = 1;
}
void motorR_stop (void){
	  motorR_D1 = 0;
	  motorR_D2 = 0;
}


//  LEFT MOTOR
void motorL_clk_Direction (void){
	motorL_D1 = 1;
	motorL_D2 = 0;
}
void motorL_non_clk_Direction (void){
	  motorL_D1 = 0;
	  motorL_D2 = 1;
}
void motorL_stop (void){
	  motorL_D1 = 0;
	  motorL_D2 = 0;
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