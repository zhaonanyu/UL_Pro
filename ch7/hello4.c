// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-27
// Description:
// show how to use erase, time, and draw for animation

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
		refresh();
		sleep(1);
		move(i, i+i);
		addstr("                       ");	/* erase line */
	}
	endwin();
}
