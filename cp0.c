// Copyright (c) 2014,ZhaoStudio
// Author:CptZhao<zhaonanyu@gmail.com>
// Created: 2014-09-12
// Description:
// 1st ver of cp cmd

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define BUF 4096
#define CPMODE 0644

void err(char *, char *);

int main(int ac, char *av[])
{
	int in_fd, out_fd, char_len;
	char buf[BUF];
	int write_count = 0;
	int byte_count = 0;

	if(ac!=3)
	{ 
		fprintf(stderr, "usage: %s source destination \n", *av);
		exit(1);
	}

	if((in_fd = open(av[1], O_RDONLY)) == -1)
	{
		err("Cannot open", av[1]);
	}

	if((out_fd = creat(av[2], CPMODE)) == -1)
	{
		err("Cannot create", av[2]);
	}

	while((char_len = read(in_fd, buf, BUF)) > 0)
	{
		if(write(out_fd, buf, char_len) != char_len)
		{
			err("Write error to ", av[2]);
		}
		write_count += 1;
		byte_count += char_len;
		printf("this is the %d time read & write\n",write_count);

	}
	printf("read & write %d times\n",write_count);
	printf("writed %d bytes\n",byte_count);

	if(char_len == -1)
	{
		err("Read error from ", av[1]);
	}

	if(close(in_fd) == -1 || close(out_fd) == -1)
	{
		err("Error closing file","");
	}
}

void err(char *s1, char *s2)
{
	fprintf(stderr, "Error: %s", s1);
	perror(s2);
	exit(1);
}
