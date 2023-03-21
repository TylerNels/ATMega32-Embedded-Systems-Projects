/* 
 * File:   main.c
 * Author: Tyler
 *
 * Created on January 26, 2022, 3:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avr.h"
#include "lcd.h"
#include <time.h>
#include <math.h>

struct tm time_init(){
    struct tm start_time;

    start_time.tm_year = 2019-1900;
    start_time.tm_mon = 11;
    start_time.tm_mday = 31;
    start_time.tm_hour = 23;
    start_time.tm_min = 59;
    start_time.tm_sec = 55;
    start_time.tm_isdst = -1;

    return start_time;
}



int is_pressed(int r, int c) {
    PORTC = 0;
    DDRC = 0;

	SET_BIT(PORTC, r);
	SET_BIT(DDRC, (c+4)); 
    avr_wait(20);
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
    else if (key == 16)
        return 13;
    else if (key == 13)
        return 16;
    else if (key == 14)
        return 0;
    else if (key == 0)
        return -1;
    else return key;
}

void setTime(struct tm* thyme) {
    char str[20];
    long long input = 0 ;
    int input_len = 0;
    
    lcd_clr();
    lcd_pos(0,0);
    lcd_puts("MM/DD/YYYY");
    
    while (1){
        int key = key_to_val(get_key());
        if (0 <= key && key <= 9){
            input = input*10 + key;
            input_len += 1;
            
            lcd_clr();
                    
            lcd_pos(0,0);
            lcd_puts("MM/DD/YYYY");
            
            lcd_pos(1,0);
            sprintf(str, "%0*lld_", input_len, input);
            lcd_puts(str);
            
            avr_wait(500);
        }
        if (input_len >= 8)
        {
            int month = input/1000000;
            int day = input/10000%100;
            int year = input%10000;
            input = 0;
            input_len = 0;
            
            if (year < 1970){
                lcd_clr();                
                lcd_pos(0,0);
                lcd_puts("INVALID YEAR");
                
                avr_wait(1000);
                
                lcd_clr();
                lcd_pos(0,0);
                lcd_puts("MM/DD/YYYY");
                
                continue;
            }
            if (month < 0 || month > 12){
                lcd_clr();                
                lcd_pos(0,0);
                lcd_puts("INVALID MONTH");
                
                avr_wait(1000);
                
                lcd_clr();
                lcd_pos(0,0);
                lcd_puts("MM/DD/YYYY");
                
                continue;
            }
            else if (day < 0 || day > 31){
                lcd_clr();                
                lcd_pos(0,0);
                lcd_puts("INVALID DAY");
                
                avr_wait(1000);
                
                lcd_clr();
                lcd_pos(0,0);
                lcd_puts("MM/DD/YYYY");
                
                continue;
            }
            thyme->tm_year = year-1900;
            thyme->tm_mon = month-1;
            thyme->tm_mday = day;
            break;
        }
    }
    
    lcd_clr();
    lcd_pos(0,0);
    lcd_puts("HH/MM/SS");
    while (1){
        int key = key_to_val(get_key());
        if (0 <= key && key <= 9){
            input = input*10 + key;
            input_len += 1;
            
            lcd_clr();
                    
            lcd_pos(0,0);
            lcd_puts("HH/MM/SS");
            
            lcd_pos(1,0);
            sprintf(str, "%0*lld_", input_len, input);
            lcd_puts(str);
            
            avr_wait(500);
        }
        if (input_len >= 6)
        {
            int hour = input/10000;
            int min = input/100%100;
            int sec = input%100;
            input = 0;
            input_len = 0;
            
            if (hour < 0 || hour > 23){
                lcd_clr();                
                lcd_pos(0,0);
                lcd_puts("INVALID HOUR");
                
                avr_wait(1000);
                
                lcd_clr();
                lcd_pos(0,0);
                lcd_puts("HH/MM/SS");
                
                continue;
            }
            else if (min < 0 || min > 59){
                lcd_clr();                
                lcd_pos(0,0);
                lcd_puts("INVALID MINUTE");
                
                avr_wait(1000);
                
                lcd_clr();
                lcd_pos(0,0);
                lcd_puts("HH/MM/SS");
                
                continue;
            }
            else if (sec < 0 || sec > 59){
                lcd_clr();                
                lcd_pos(0,0);
                lcd_puts("INVALID SECOND");
                
                avr_wait(1000);
                
                lcd_clr();
                lcd_pos(0,0);
                lcd_puts("HH/MM/SS");
                
                continue;
            }
            
            thyme->tm_hour = hour;
            thyme->tm_min = min;
            thyme->tm_sec = sec;
            break;
        }
    } 
    
}


int main(int argc, char** argv) {
    lcd_init();
    lcd_clr();
    
    struct tm thyme = time_init();
    char AM = 0;
    
    char str[30];
//    struct tm old_info;
    

    while(1){
        int key = key_to_val(get_key());
        if (key == 16){
            setTime(&thyme);
        }
        else if (key == 10){
            AM = 1-AM;
        }
      
        lcd_clr();
         
        lcd_pos(0,0);
        sprintf(str, "Date:%02d/%02d/%02d", thyme.tm_mon+1, thyme.tm_mday, thyme.tm_year+1900);
        lcd_puts(str);

        lcd_pos(1,0);
        if (!AM)
            sprintf(str, "Time:%02d:%02d:%02d", thyme.tm_hour, thyme.tm_min, thyme.tm_sec);
        else if (1 <= thyme.tm_hour && thyme.tm_hour <= 12)
            sprintf(str, "Time:%02d:%02d:%02dAM", thyme.tm_hour, thyme.tm_min, thyme.tm_sec);
        else if (13 <= thyme.tm_hour && thyme.tm_hour <= 23)
            sprintf(str, "Time:%02d:%02d:%02dPM", (thyme.tm_hour % 12), thyme.tm_min, thyme.tm_sec);
        else if (thyme.tm_hour == 0)
            sprintf(str, "Time:12:%02d:%02dPM", thyme.tm_min, thyme.tm_sec);
        lcd_puts(str);

        thyme.tm_sec++;
        mktime(&thyme);
        
        avr_wait(1000);
    }
    return (EXIT_SUCCESS);
}