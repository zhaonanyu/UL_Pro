// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-24
// Description:
//
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

//struct for misc flags showing
struct flaginfo{
	int fl_value;
	char *fl_name;
};

void showbaud( int thespeed );
void show_misc_flags(struct termios *ttyp );
void show_flagset( int thevalue, struct flaginfo thebitnames[] );

int main()
{
	struct termios ttyinfo;

	if ( tcgetattr(0, &ttyinfo) == -1 ){
		perror("can't get ttyinfo from fd0 AKA stdin");
		exit(1);
	}
	
	//show baud rate
	showbaud( cfgetospeed( &ttyinfo ) );

	//show VERASE
	printf("The erase character in ascii is %d, Ctrl-%c\n",
			ttyinfo.c_cc[VERASE], ttyinfo.c_cc[VERASE] - 1 + 'A');
	//show VKILL
	printf("The line kill character in ascii is %d, Ctrl-%c\n",
			ttyinfo.c_cc[VKILL], ttyinfo.c_cc[VKILL] - 1 + 'A');
	//show misc. flags
	show_misc_flags( &ttyinfo );
}

void showbaud( int thespeed )
{
	printf("the baud rate is");
	switch ( thespeed) {
		case B300: printf("300\n"); break;
		case B600: printf("600\n"); break;
		case B1200: printf("1200\n"); break;
		case B1800: printf("1800\n"); break;
		case B2400: printf("2400\n"); break;
		case B4800: printf("4800\n"); break;
		case B9600: printf("9600\n"); break;
		default: printf("Fast\n"); break;
	}
}


struct flaginfo input_flags[] = {
	IGNBRK, "Ignore break condition",
	BRKINT, "Signal interrupt on break",
	IGNPAR, "Ignore chars with parity errors",
	PARMRK, "Mark parity errors",
	INPCK, "Enable input parity check",
	ISTRIP, "Strip character",
	INLCR, "Map NL to CR on input",
	IGNCR, "Ignore CR",
	ICRNL, "Map CR to NL on input",
	IXON, "Enable start/stop output control",
	IXOFF, "Enable start/stop input control",
	0, NULL
};

struct flaginfo local_flags[] = {
	ISIG, "Enable signals",
	ICANON, "Canonical input(erase and kill)",
	ECHO, "Enable echo",
	ECHOE, "Echo ERASE as BS-SPACE-BS",
	ECHOK, "Echo KILL by starting new line",
	0, NULL
};

void show_misc_flags( struct termios *ttyp)
{
	show_flagset( ttyp->c_iflag, input_flags );
	show_flagset( ttyp->c_lflag, local_flags );
}

void show_flagset( int thevalue, struct flaginfo thebitnames[])
{
	int i;
	for ( i = 0; thebitnames[i].fl_value; i++ ) {
		printf( "%s is", thebitnames[i].fl_name);
		if ( thevalue & thebitnames[i].fl_value )
			printf("ON\n");
		else
			printf("OFF\n");
	}
}

