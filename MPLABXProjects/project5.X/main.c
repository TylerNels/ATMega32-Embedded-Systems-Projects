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
#include "song.h"
#include "keypad.h"
#include <math.h>


int main(int argc, char** argv) {
    int pass[3] = {0, 0, 0};
    int input = 0 ;
    int input_len = 0;
    int wrong_pass = 0;
    char str[20];
    
    lcd_init();
    
    lcd_clr();
    lcd_pos(0,0); 
    lcd_puts("Unlocked");
    
    while (1){
        int key = get_key_val();
        if (key == 15){
            lcd_pos(0,0);
            lcd_puts("New Password:");

            input = 0;
            input_len = 0;
            
            while (1){        
                int num = get_key_val();
                
                if (0 <= num && num <= 9){
                    input = input*10 + num;
                    input_len += 1;

                    sprintf(str, "%0*d_", input_len, input);
                    lcd_pos(1,0);
                    lcd_puts(str);

                    avr_wait(2500);
                }
                if (input_len >= 4) {
                    if (input == pass[0] || input == pass[1] || input == pass[2]){
                        lcd_clr();
                        lcd_pos(0,0);
                        lcd_puts("No Repeat Pass:");
                        
                        avr_wait(10000);

                        lcd_clr();
                        lcd_pos(0,0); 
                        lcd_puts("Unlocked");
                        break;
                    }
                    else
                    {
                        lcd_clr();
                        lcd_pos(0,0);
                        lcd_puts("New Pass Set:");
                        lcd_pos(1,0);
                        sprintf(str, "%0*d", input_len, input);
                        lcd_puts(str);

                        pass[2] = pass[1];
                        pass[1] = pass[0];
                        pass[0] = input;

                        avr_wait(10000);

                        lcd_clr();
                        lcd_pos(0,0); 
                        lcd_puts("Unlocked");
                        break;
                    }
                   
                }
            }
        }
        if (key == 14)
        {
            lcd_clr();
            lcd_pos(0,0);
            lcd_puts("Locked");
            PlaySongLock();
            
            
            input = 0;
            input_len = 0;
            wrong_pass = 0;
            
            while (1){
                int num = get_key_val();
                if (0 <= num && num <= 9){
                    input = input*10 + num;
                    input_len += 1;

                    sprintf(str, "%0*d_", input_len, input);
                    lcd_pos(1,0);
                    lcd_puts(str);

                    avr_wait(2500);
                }
                if (input_len >= 4)
                {
                    if (input == pass[0]){
                        lcd_clr();
                        lcd_pos(0,0); 
                        lcd_puts("Unlocked");
                        PlaySongUnlock();
                        break;
                    }
                    else {
                        input = 0;
                        input_len = 0;
                        wrong_pass += 1;
                        
                        lcd_clr();
                        lcd_pos(0,0); 
                        lcd_puts("Incorrect");
                        
                        PlaySongFail();
                        avr_wait(5000);
                        
                        if (wrong_pass == 3){
                            wrong_pass = 0;
                            lcd_clr();
                            lcd_puts("Too Many");
                            lcd_pos(1,0);
                            lcd_puts("Wrong Passcode");
                            for (int i = 0; i < 80; i++)
                                avr_wait(5000);
                        }
                        
                        lcd_clr();
                        lcd_pos(0,0);
                        lcd_puts("Locked");
                        
                        continue;
                    } 
                        
                }
            }
        }
            
    }
       
//    long long input1 = 0;
//    long long input2 = 0;
    
    
    
//    while (1){
//        lcd_pos(0,0);
//        
//        int key1 = get_key_val();
//        
//        if (0 <= key1 && key1 <= 9){
//            input1 = input1*10 + key1;
//                                
//            sprintf(str1, "%lld_", input1);
//            lcd_puts(str1);
//            avr_wait(300);
//        }
//        else if (10 <= key1){
//            if (key1 == 14){
//                input1 = 0;
//                lcd_clr();
//                continue;
//            }
//            else if (key1 == 10){
//                sprintf(str1, "%lld+", input1);
//            }
//            else if (key1 == 11){
//                sprintf(str1, "%lld-", input1);
//            }
//            else if (key1 == 12){
//                sprintf(str1, "%lld*", input1);
//            }
//            else if (key1 == 13){
//                sprintf(str1, "%lld/", input1);
//            }
//            lcd_puts(str1);
//            avr_wait(300);
//            
//            while (1){
//                lcd_pos(1,0);
//                
//                int key2 = get_key_val();
//                
//                if (0 <= key2 && key2 <= 9){
//                    input2 = input2*10 + key2;
//
//                    sprintf(str2, "%lld_", input2);
//                    lcd_puts(str2);
//                    avr_wait(300);
//                }
//                else if (10 <= key2){
//                    if (key2 == 14){
//                        input1 = 0;
//                        input2 = 0;
//                        lcd_clr();
//                        break;
//                    }
//                    else if (key2 == 15){
//                        if (key1 == 10){
//                            input1 += input2;
//                        }
//                        else if (key1 == 11){
//                            input1 -= input2;
//                        }
//                        else if (key1 == 12){
//                            input1 *= input2;
//                        }
//                        else if (key1 == 13){
//                            input1 /= input2;
//                        }
//                        
//                        input2 = 0;
//                        
//                        lcd_clr();
//                        
//                        lcd_pos(0,0);
//                        sprintf(str1, "%lld_", input1);
//                        lcd_puts(str1);
//                        break;
//                    }
////                    else {
////                        if (key2 == 10){
////                            sprintf(str2, "%lld+", input2);
////                        }
////                        else if (key2 == 11){
////                            sprintf(str2, "%lld-", input2);
////                        }
////                        else if (key2 == 12){
////                            sprintf(str2, "%lld*", input2);
////                        }
////                        else if (key2 == 13){
////                            sprintf(str2, "%lld/", input2);
////                        }
////                        lcd_puts(str2);
////                        avr_wait(300);
////                    }
//                }
//            }
//        }
//    }
    
    return (EXIT_SUCCESS);
}

