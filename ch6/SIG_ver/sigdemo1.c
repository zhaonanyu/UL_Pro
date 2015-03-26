// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-26
// Description:
// A demo of sig

#include <stdio.h>
#include <signal.h>

void f( int signum );

int main()
{
	int i;
	signal( SIGINT, f );
	for (i = 0; i<5; i++){
		printf("hello\n");
		sleep(1);
	}
}

void f(int signum)
{
	printf("OUCH!\n");
}
