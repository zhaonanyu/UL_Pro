// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-25
// Description:
// ask if user wants another transactioni
// set echo mode off
// immideately respond after input

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

void tty_mode( int how );
void set_cr_noecho_mode();
int get_response( char *question );

int main()
{
	int response;

	tty_mode(0);	/* save current tty settings */
	set_cr_noecho_mode();
	response = get_response(QUESTION);
	tty_mode(1);	/* restore original tty setting */

	return response;
}

void tty_mode(int how)
{
	static struct termios original_mode;
	if ( how == 0 )
		tcgetattr(0, &original_mode);
	else
		return tcsetattr(0, TCSANOW, &original_mode);
}

void set_cr_noecho_mode()
{
	struct termios ttystate;

	tcgetattr(0, &ttystate);
	ttystate.c_lflag &= ~ICANON;	/* set no buffering */
	ttystate.c_lflag &= ~ECHO;		/* set no echo mode */
	ttystate.c_cc[VMIN] = 1;		/* get 1 char a time */
	tcsetattr(0, TCSANOW, &ttystate);/* set tty setting */
}

int get_response(char *question)
{
	/**
	 * no echo mode will allow apps to
	 * response only to n N EOF y Y
	 * because user's typing will not echo to the terminal
	 * you don't need to write codes to respond those illeagle chars
	 * so it doesn't respond any illeagle chars
	 * compare to the playagain1.c
	 * lol to that
	 */
	printf("%s (y/n)", question);
	while(1){
		switch( getchar() ){
			case 'n':
			case 'N':
			case EOF: return 1;
			case 'y':
			case 'Y': return 0;
		}
	}
}
