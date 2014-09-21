// Copyright (c) 2014,ZhaoStudio
// Author:CptZhao<zhaonanyu@gmail.com>
// Created: 2014-09-21
// Description:
// this version do have some problems
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

void show_stat_info(char* filename, struct stat stat_info);

int main(int ac, char* av[])
{
	struct stat stat_info;

	if(ac > 1)
	{
		if(stat(av[1], &stat_info) == -1)
			perror(av[1]);
		else
		{
			show_stat_info(av[1], stat_info);
			return 0;
		}
	}
	return 1;
}

void show_stat_info(char* filename, struct stat stat_info)
{
	char* mtime;
	mtime = ctime(stat_info.st_mtime);
	printf("   mode: %o\n", stat_info.st_mode);
	printf("  links: %ld\n", stat_info.st_nlink);
	printf("   user: %d\n", stat_info.st_uid);
	printf("  group: %d\n", stat_info.st_gid);
	printf("   size: %ld\n", stat_info.st_size);
	printf("modtime: %s\n",mtime);
	printf("   name: %s\n", filename);
}
