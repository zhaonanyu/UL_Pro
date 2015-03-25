// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-25
// Description:
// ask if user wants another transaction
// set tty into char-by-char mode
// read char and immediately return the result without sending a return

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"
int get_response( char *question);
void set_crmode();
void tty_mode();

int main()
{
	int response;
	tty_mode(0);
	set_crmode();
	response = get_response(QUESTION);
	tty_mode(1);
	return response;
}

int get_response(char *question)
{
	printf("%s (y/n)", question);
	while(1){
		switch( getchar() ){
			case 'y':
			case 'Y': return 0;
			case 'n':
			case 'N': 
			case EOF: return 1;
			default:
				printf("\ncannot understand");
				printf("Please type y or n\n");
		}
	}

	/**
	 * version on the book
	int input;
	printf("%s (y/n)", question);
	while(1){
		switch( input = getchar() ){
			case 'y':
			case 'Y': return 0;
			case 'n': 
			case 'N':
			case EOF: return 1;
			default:
				printf("\nconnot understand %c", input);
				printf("Please type y or n\n");
		}
	}
	*/
}

void set_crmode()
{
	struct termios ttystate;
	tcgetattr(0, &ttystate);
	ttystate.c_lflag &= ~ICANON;	/* set no buffering */
	ttystate.c_cc[VMIN] =1;			/* get 1 char a time */
	tcsetattr(0, TCSANOW, &ttystate);
}

void tty_mode(int how)
{
	static struct termios original_mode;
	if ( how == 0 )
		tcgetattr(0, &original_mode);
	else
		return tcsetattr(0, TCSANOW, &original_mode);
}
