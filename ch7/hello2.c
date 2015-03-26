// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-26
// Description:
// show how to use curses functions with a loop

#include <stdio.h>
#include <curses.h>

int main()
{
	int i;

	initscr();
	clear();
	printf("%d\n", LINES);
	for(i = 0; i<LINES; i++){
		move(i, i+i);
		if(i%2 ==1)
			standout();
		addstr("Hello, world");
		if(i%2 == 1)
			standend();
	}
	refresh();
	getch();
	endwin();
}
