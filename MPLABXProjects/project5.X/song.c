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
    SET_BIT(DDRB, 3);
    int i;
    for (i = 0; (i < N) ; ++i){  
        Playnote(song[i]);        
    }
}

void PlaySongUnlock(){
    struct note SONG[] = {{E, c5}, {E, d5}, {E, e5}};
    Playsong(SONG, 3);
}

void PlaySongLock(){
    struct note SONG[] = {{E, e5}, {E, d5}, {E, c5}};
    Playsong(SONG, 3);
}

void PlaySongFail(){
    struct note SONG[] = {{H, a4}};
    Playsong(SONG, 1);
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
