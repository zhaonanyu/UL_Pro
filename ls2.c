// Copyright (c) 2014,ZhaoStudio
// Author:CptZhao<zhaonanyu@gmail.com>
// Created: 2014-09-21
// Description:
//

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

struct link_node
{
	int* next;
	char[] data;
}

void list_add(*at, *next)

void do_ls(char[]);

main(int ac, char* av[])
{
	if(ac == 1)
		do_ls(".");
	else
	{
		while(--ac)
		{
			printf("%s:\n", *++av);
			do_ls(*av);
		}
	}
}

void do_ls(char dirname[])
{
	DIR* dir_ptr;
	struct dirent* direntp;

	if((dir_ptr = opendir(dirname)) == NULL)
		fprintf(stderr, "ls2: cannot open file %s\n", dirname);
	else
	{
		while((direntp = readdir(dir_ptr)) != NULL)
			printf("%s\n", direntp->d_name);
		closedir(dir_ptr);
	}
}
