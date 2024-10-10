#include <REGX51.H>
#define LCD_data P2
#define KEY_pad P1

sbit rs = P3^0;
sbit en = P3^1;
unsigned LCD_Curs_pos =0;


void delay (unsigned del);
void LCD_commande (unsigned char ch);
void LCD_display (unsigned char ch);
void LCD_display_str (unsigned char *str);
char KEY_GET (void);
	
void main(void){
	
	char key_value = 0;
	LCD_commande(0x38); // function set 2line 5x7 dote
	LCD_commande(0x0C); // display on cursor off
	
	
	while(1){
		if(LCD_Curs_pos < 16){
			LCD_commande(0x80 + LCD_Curs_pos);
			}
		if(LCD_Curs_pos >= 16){
			LCD_commande(0xC0 + LCD_Curs_pos - 16);
			}
		if(LCD_Curs_pos >= 32){
			LCD_commande(0x01);
			LCD_Curs_pos =0;
			}
		
		key_value = KEY_GET();
		LCD_display(key_value);
		delay(3);
		
		
	}
	}
	


	
	
// Display on LCD
	
void LCD_display (unsigned char ch){
	
	LCD_data = ch;
	rs = 1;
	en = 1;
	delay(3);
	en = 0;
}	
void LCD_display_str (unsigned char *str){
	
	unsigned flag = 0;
	unsigned flag2 =0;
	unsigned loop = 0;
	unsigned loop2 = 0;
	
	for(loop=0;str[loop]!='\0';loop++){
		
		if((loop<16) || (loop2<16)){
			LCD_display(str[loop]);
			loop2+=1;
		}
		else if((loop<32) || (loop2<32)){
			if(flag ==1){LCD_display(str[loop]);loop2+=1;}
			else{
				flag =1;
				LCD_commande(0xC0);
				LCD_display(str[loop]);
				loop2+=1;
			}
		}
		else{
				flag2 =1;
				LCD_commande(0x01);
				LCD_commande(0x80);
				LCD_display(str[loop]);
				loop2 = 1;
				flag =0;
			}			
		
	}	
}
//  keypad commande
char KEY_GET (void){
	
	char key_value = 0;
	
	KEY_pad = 0xFE;
	if(KEY_pad == 0xEE){
		key_value = '1';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xDE){
		key_value = '2';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xBE){
		key_value = '3';
		LCD_Curs_pos++;
		}
	
	KEY_pad = 0xFD;
	if(KEY_pad == 0xED){
		key_value = '4';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xDD){
		key_value = '5';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xBD){
		key_value = '6';
		LCD_Curs_pos++;
		}
	
	KEY_pad = 0xFB;	
	if(KEY_pad == 0xEB){
		key_value = '7';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xDB){
		key_value = '8';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xBB){
		key_value = '9';
		LCD_Curs_pos++;
		}
	
	KEY_pad = 0xF7;
	if(KEY_pad == 0xE7){
		key_value = '*';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xD7){
		key_value = '0';
		LCD_Curs_pos++;
		}
	if(KEY_pad == 0xB7){
		key_value = '#';
		LCD_Curs_pos++;
		}	
	
		return key_value;
	
}	
//  LCD commande
void LCD_commande (unsigned char ch){
	
	LCD_data = ch;
	rs = 0;
	en = 1;
	delay(10);
	en = 0;
}	
	
// DELAY
void delay (unsigned del){
	
	unsigned loop = 0;
	unsigned delay_gen = 0;
	
	for(loop=0;loop<del;loop++){
		for(delay_gen=0;delay_gen<10000;delay_gen++);
	}

}