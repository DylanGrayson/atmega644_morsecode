#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LED PORTD
#define TOGGLE 1
#define TIME_UNIT 500
#define THREE TIME_UNIT*3
#define SEVEN TIME_UNIT*7

struct Morse {
	char letter;
	unsigned char code[5];
};

void lng();
void shrt();
void space();
char * get_morse(char letter);

int main(void){

	char* str = "computer boys";
	DDRD = 1;
	LED = 0;
	for(;;){
		int count = 0;
		while(*(str + count) != '\0'){
			if (*(str + count) == ' '){
				space();
				count++;
			}else{
				char* code = get_morse(*(str + count));
				int pos = 0;
				while(*(code + pos) != '\0'){
					if (*(code + pos) == 'l'){
						lng();
						if (*(code + pos + 1) != '\0'){
							shrt();
						}else{
							lng();
						}
					}else{
						shrt();
						if (*(code + pos + 1) != '\0'){
							shrt();
						}else{
							lng();
						}
					}
					pos++;
				}
				count++;
			}
		}
	}
	return 0;
}

void lng(){
	LED ^= TOGGLE;
	_delay_ms(THREE);
}
void shrt(){
	LED ^= TOGGLE;
	_delay_ms(TIME_UNIT);
}
void space(){
	_delay_ms(SEVEN);
}

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
	
