/* 
 * File:   main.c
 * Author: Tyler
 *
 * Created on February 15, 2022, 6:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avr.h"
#include "lcd.h"
#include <math.h>


struct note{
    int duration;
    int freq;
};

int get_sample(){
    SET_BIT(ADMUX, 6);
    ADMUX &= ~(10100000);
    ADCSRA |= 11000000;
    while (GET_BIT(ADCSRA, 6));
    return ADC;
}

int main(int argc, char** argv) {
    lcd_init();
    char str[40];
    int s, max, min, cnt;
    long long total;
    max = 0;
    min = 1023;
    total = 0;
    cnt = 0;
    
    while (1){
        s = get_sample();
        if (s < min)
            min = s;
        if (s > max)
            max = s;
        total += s;
        cnt++;
        
        
        if (get_key_val() == 1){
            while (get_key_val() == 1)
                avr_wait(500); 
            while (get_key_val() != 1)
                if (get_key_val() == 2){
                    max = 0;
                    min = 1023;
                    total = 0;
                    cnt = 0;
                    
                    lcd_clr();
                    lcd_pos(0,0);
                    sprintf(str, "In:---- Av:----", (s/1023.0)*5, ((total/cnt)/1023.0)*5);
                    lcd_puts(str);

                    lcd_pos(1,0);
                    sprintf(str, "Mn:---- Mx:----f", (min/1023.0)*5, (max/1023.0)*5);
                    lcd_puts(str);
                }
                avr_wait(500);
        }
        else if (get_key_val() == 2){
            max = 0;
            min = 1023;
            total = 0;
            cnt = 0;
            
            lcd_clr();
            lcd_pos(0,0);
            sprintf(str, "In:%4.2f Av:----", (s/1023.0)*5, ((total/cnt)/1023.0)*5);
            lcd_puts(str);

            lcd_pos(1,0);
            sprintf(str, "Mn:---- Mx:----", (min/1023.0)*5, (max/1023.0)*5);
            lcd_puts(str);
        }
        else
        {
            lcd_clr();
            lcd_pos(0,0);
            sprintf(str, "In:%4.2f Av:%4.2f", (s/1023.0)*5, ((total/cnt)/1023.0)*5);
            lcd_puts(str);

            lcd_pos(1,0);
            sprintf(str, "Mn:%4.2f Mx:%4.2f", (min/1023.0)*5, (max/1023.0)*5);
            lcd_puts(str);
        }
        
        
        avr_wait(500);
    }
    
    return (EXIT_SUCCESS);
}

