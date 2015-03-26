// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-26
// Description:
// A sig demo

#include <stdio.h>
#include <signal.h>

int main()
{
	signal( SIGINT, SIG_IGN );
	printf("you can't stop me!\n");
	while(1){
		sleep(1);
		printf("lol\n");
	}
}
