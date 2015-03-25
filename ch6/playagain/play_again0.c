// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-25
// Description:
// purpose: ask if user wants another transaction
// eliminate need to press return

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

int get_response( char * );

int main()
{
	int response;
	response = get_response(QUESTION);
	return response;
}

int get_response( char *question )
{
	printf("%s (y/n)", question);
	while(1){
		switch( getchar() ){
			case 'y':
			case 'Y': return 0;
			case 'n':
			case 'N':
			case EOF: return 1;
		}
	}
}
