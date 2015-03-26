// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-26
// Description:
// ask if user wants another transaction
// using non blocking fcntl function by O_NDELAY flag

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define QUESTION "Do you want another transaction"
#define TRIES 3				/* maxmium tries */
#define SLEEPTIME 2			/* time per try for time out */
#define BEEP putchar('\a')	/* alert for time out*/

int get_response( char *question, int maxtries );
void tty_mode( int how );
void set_cr_noecho_mode();
void set_nodelay_mode();
char get_ok_char();

int main()
{
	int response;
	
	tty_mode(0);
	set_cr_noecho_mode();
	set_nodelay_mode();
	response = get_response(QUESTION, TRIES);
	tty_mode(1);

	return response;
}

int get_response( char *question, int maxtries )
{
	int input;
	printf("%s(y/n)?", question);

	fflush(stdout);								/* force output */

	while(1){
		sleep(SLEEPTIME);

		input = tolower( get_ok_char() );		/* let Y or N to lower char */
		if ( input == 'y' )
			return 0;
		if ( input == 'n' )
			return 1;
		if ( maxtries-- == 0 )
			return 2;							/* time out */
		BEEP;
	}
}

char get_ok_char()
{
	int c;
	while ( ( c = getchar() ) != EOF && strchr("yYnN", c) == NULL )
		;										/* blocking waiting for the input */
	return c;
}

void set_cr_noecho_mode()
{
	struct termios ttystate;
	tcgetattr(0, &ttystate);
	ttystate.c_lflag &= ~ICANON;				/* set buffering off */
	ttystate.c_lflag &= ~ECHO;					/* set echo off */
	ttystate.c_cc[VMIN] = 1;					/* get 1 char a time */
	tcsetattr(0, TCSANOW, &ttystate);			/* TCSANOW means change occurs immediately */
}

void set_nodelay_mode()
{
	int termflags;
	termflags = fcntl(0, F_GETFL);
	termflags |= O_NDELAY;						/* flip on nodelay bit */
	fcntl(0, F_SETFL, termflags);
}

void tty_mode(int how)
{
	static struct termios original_mode;
	static int original_flags;
	if ( how == 0 ) {
		tcgetattr(0, &original_mode);
		original_flags = fcntl(0, F_GETFL);
	}else{
		tcsetattr(0, TCSANOW, &original_mode);
		fcntl(0, F_SETFL, original_flags);
	}
}
