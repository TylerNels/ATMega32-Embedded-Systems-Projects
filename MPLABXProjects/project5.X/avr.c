/**
 * avr.c
 * Copyright (C) 2001-2020, Tony Givargis
 */

#include "avr.h"

void
avr_wait(unsigned int msec)
{
	TCCR0 = 2;
	while (msec--) {
		TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 8) * 0.0001);
		SET_BIT(TIFR, TOV0);
		while (!GET_BIT(TIFR, TOV0));
	}
	TCCR0 = 0;
}