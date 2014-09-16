// Copyright (c) 2014,ZhaoStudio
// Author:CptZhao<zhaonanyu@gmail.com>
// Created: 2014-09-13
// Description:
// 3rd version of who cmd

#include <stdio.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <utmplib.h>

#define SHOWHOST

void show_info(struct utmp *);
void show_time(time_t);

int main()
{
	struct utmp * utbufp, * utmp_next();

	if(utmp_open(UTMP_FILE) == -1)
	{
		perror(UTMP_FILE);
		exit(1);
	}

	while((utbufp = utmp_next()) != ((struct utmp *)NULL))
	{
		show_info(utbufp);
	}
	utmp_close();
	return 0;
}

void show_info(struct utmp * utbufp)
{
	if(utbufp->ut_type != USER_PROCESS)
		return;
	printf("%-9.9s", utbufp->ut_name);
	printf(" ");
	printf("%-8.8s", utbufp->ut_line);
	printf(" ");
	show_time(utbufp->ut_time);

	#ifdef SHOWHOST
		if(utbufp->ut_host[0] != '\0')
			printf("(%s)", utbufp->ut_host);
	#endif
		printf("\n");
}

void show_time(long timeval)
{
	struct tm *Udate = localtime(&timeval);
	printf("%8d-%2.2d-%2.2d %2.2d:%2.2d ", (1900+Udate->tm_year),(1+Udate->tm_mon),Udate->tm_mday, Udate->tm_hour, Udate->tm_min);
}
