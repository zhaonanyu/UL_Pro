// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-04-03
// Description:
// blocks ^\ while handling ^C
// does not reset ^C handler, so two kill

#include <stdio.h>
#include <signal.h>
#define INPUTLEN 100

void inthandler(int s);

int main()
{
	struct sigaction newhandler;
	sigset_t blocked;
	void inthandler();
	char x[INPUTLEN];

	/* load members */
	newhandler.sa_handler = inthandler;
	newhandler.sa_flags = SA_RESETHAND | SA_RESTART;

	sigemptyset(&blocked);				/* clear all bits */
	sigaddset(&blocked, SIGQUIT);		/* add SIGQUIT to list */
	newhandler.sa_mask = blocked;		/* stroe blockmask */

	if ( sigaction(SIGINT, &newhandler, NULL) == -1 )
		perror("sigaction");
	else
		while(1){
			fgets(x, INPUTLEN, stdin);
			printf("input: %s", x);
		}
}

void inthandler(int s)
{
	printf("Called with signal %d\n", s);
	sleep(s);
	printf("done handling signal %d\n", s);
}
