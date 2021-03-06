// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-27
// Description:
// using refresh and sleep for animated effects
// outline initialize, draw stuff, wrap up

#include <stdio.h>
#include <curses.h>

int main()
{
	int i;

	initscr();
	clear();

	for(i=0; i<LINES; i++){
		move(i, i+i);
		if(i%2 == 1)
			standout();
		addstr("Hello world");
		if(i%2 == 1)
			standend();
		sleep(1);
		refresh();
	}
	endwin();
}
