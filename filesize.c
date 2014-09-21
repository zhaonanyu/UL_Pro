// Copyright (c) 2014,ZhaoStudio
// Author:CptZhao<zhaonanyu@gmail.com>
// Created: 2014-09-21
// Description:
//
#include<stdio.h>
#include<sys/stat.h>

int main()
{
	struct stat stat_buf;

	if(stat("who3.c", &stat_buf) == -1)
		perror("who3.c");
	else
	{
		printf("the size of who3.c is %ld\n", stat_buf.st_size);
	}
}
