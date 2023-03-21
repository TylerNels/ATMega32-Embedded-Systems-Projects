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

#define p -1
#define a4 220
#define as4 233
#define b4 246
#define c4 261
#define cs4 277
#define d4 293
#define ds4 311
#define e4 329
#define f4 349
#define fs4 370
#define g4 392
#define gs4 415
#define a5 440
#define as5 466
#define b5 493
#define c5 523
#define cs5 554
#define d5 587
#define ds5 622
#define e5 659
#define f5 698
#define fs5 740
#define g5 784
#define gs5 836
#define a6 880
#define as6 932
#define b6 987
#define c6 1046
#define cs6 1108
#define d6 1174

#define W 8
#define H 4
#define Q 2
#define E 1

struct note{
    int duration;
    int freq;
};

void Playsong(const struct note *song, int N){
    char str[40];
    int i;
    for (i = 0; (i < N) ; ++i){
                
        Playnote(song[i]);
        
        
        if (get_key_val() == 14){
            while (get_key_val() == 14)
                avr_wait(50); 
            while (get_key_val() != 14)
                avr_wait(50);
            while (get_key_val() == 14)
                avr_wait(50);
        }
        
    }
    avr_wait(5000);
}

void Playnote(const struct note n){
    if (n.freq == -1)
    {
        avr_wait(n.duration*1000*2);
        return;
    }
    int TH = ceil(10000/2/n.freq);
    int k = n.duration * n.freq / 10*2;
    
    
    for (long long i=0; i < k; ++i){
        SET_BIT(PORTB, 3);
        avr_wait(TH);
        CLR_BIT(PORTB, 3);
        avr_wait(TH);
    }
}


int main(int argc, char** argv) {
    SET_BIT(DDRB, 3);
    lcd_init();
    lcd_clr();
    struct note SONG[] = {{E, d5},{E, d5},{Q, e5},{Q, d5}, {Q, g5}, {H, f5}, {E, d5},{E, d5},{Q, e5},{Q, d5}, {Q, a6}, {H, g5}, {E, d5}, {E, d5},{Q, d6}, {Q, b6}, {Q, g5}, {Q, fs5}, {Q, e5}, {E, c6}, {E, c6}, {Q, b6}, {Q, g5}, {Q, a6}, {H, g5}};
    while (1){
        char str[40] = "HAPPY BIRTHDAY";
        lcd_pos(0,0);
        lcd_puts(str);
        Playsong(SONG, 25);
    }
    
    return (EXIT_SUCCESS);
}

