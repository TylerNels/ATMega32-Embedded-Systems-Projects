
#include <stdio.h>
#include <stdlib.h>
#include "keypad.h"
#include "avr.h"

int is_pressed(int r, int c) {
    PORTC = 0;
    DDRC = 0;

	SET_BIT(PORTC, r);
	SET_BIT(DDRC, (c+4)); 
    avr_wait(15);
	return (!GET_BIT(PINC, r));
}

int get_key() {
	int r, c;
	for (r = 0; r < 4; ++r) {
		for (c = 0; c < 4; ++c) {
			if(is_pressed(r, c)) {
				return (4 * r) + c + 1;
			}
		}
	}
	return 0;
}

int key_to_val(int key){
    if (5 <= key && key <= 7)
        return key-1;
    else if (9 <= key && key <= 11)
        return key-2;
    else if (key == 4)
        return 10;
    else if (key == 8)
        return 11;
    else if (key == 12)
        return 12;
    else if (key == 16)
        return 13;
    else if (key == 13)
        return 14;
    else if (key == 14)
        return 0;
    else if (key == 15)
        return 15;
    else if (key == 0)
        return -1;
    else return key;
}

int get_key_val(){
    return key_to_val(get_key());
}
