/* 
 * File:   keypad.h
 * Author: Tyler
 *
 * Created on February 16, 2022, 5:10 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

int is_pressed(int r, int c);

int get_key();

int key_to_val(int key);

int get_key_val();

#endif	/* KEYPAD_H */

