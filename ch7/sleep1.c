// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-27
// Description:
// show how sleep works
// sets handler, set alarm, pause, then returns

#include <stdio.h>
#include <signal.h>

#define SHHHH

void wakeup(int signum)
{
#ifndef SHHHH
	printf("Alarm received from kernel\n");
#endif
}

int main()
{
	printf("about to sleep for 4 sec\n");

	//sleep
	signal(SIGALRM, wakeup);
	alarm(4);
	pause();

	printf("Morning so soon?\n");
}
