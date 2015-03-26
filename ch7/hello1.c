// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-26
// Description:
// Print Hello,World in the middle of the screen

#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();				/* turn on screen */

	clear();				/* clear screen */
	move(10, 20);
	addstr("Hello, world");
	move(LINES-1, 0);
	refresh();
	getch();
	endwin();
}
