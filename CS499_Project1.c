#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LED PORTD
#define TOGGLE 1
#define OFF 0
#define LED_PIN 0b00000001
#define SPACE ' '
#define TIME_UNIT 500
#define THREE TIME_UNIT*3
#define SEVEN TIME_UNIT*7

//Function prototype declarations
void lng();
void shrt();
void space();
char * get_morse(char letter);

int main(void){
	//define the string that will be translated to morse code.
	char* str = "computer boys are back";
	//Set our led pin to output and make sure it's off to start
	DDRD = LED_PIN;
	LED = OFF;
	//Main program loop
	for(;;){
		int count = 0;
		//Loop through chars in str
		while(*(str + count) != '\0'){
			//if it's a space call space() which pauses for 7 units
			if (*(str + count) == SPACE){
				space();
				count++;
			}//otherwise blink the appropriate letter in morse
			else{
				char* code = get_morse(*(str + count));
				int pos = 0;
				//Loop through sequence from get_morse
				while(*(code + pos) != '\0'){
					//if the it's a long blink call lng()
					if (*(code + pos) == 'l'){
						lng();
					}//else it's a short blink, call shrt()
					else{
						shrt();
					}
					//decide pause time depending if last blink
					//of the sequence. 
					if (*(code + pos + 1) != '\0'){
						shrt();
					}else{
						lng();
					}
					//increment 
					pos++;
				}
				count++;
			}
		}
	}
	return 0;
}
//toggle and delay long
void lng(){
	LED ^= TOGGLE;
	_delay_ms(THREE);
}
//toggle and delay short
void shrt(){
	LED ^= TOGGLE;
	_delay_ms(TIME_UNIT);
}
//delay for space between words
void space(){
	_delay_ms(SEVEN);
}
//return appropriate sequence of long and short blinks for each letter.
char* get_morse(char letter){
	switch(letter){
		case 'a':
			return "sl";
		case 'b':
			return "lsss";
		case 'c':
			return "lsls";
		case 'd':
			return "lss";
		case 'e':
			return "s";
		case 'f':
			return "ssls";
		case 'g':
			return "lls";
		case 'h':
			return "ssss";
		case 'i':
			return "ss";
		case 'j':
			return "slll";
		case 'k':
			return "lsl";
		case 'l':
			return "slss";
		case 'm':
			return "ll";
		case 'n':
			return "ls";
		case 'o':
			return "lll";
		case 'p':
			return "slls";
		case 'q':
			return "llsl";
		case 'r':
			return "sls";
		case 's': 
			return "sss";
		case 't':
			return "l";
		case 'u':
			return "ssl";
		case 'v':
			return "sssl";
		case 'w':
			return "sll";
		case 'x':
			return "lssl";
		case 'y':
			return "lsll";
		case 'z':
			return "llss";
	}
	return "lllll";
}
	
