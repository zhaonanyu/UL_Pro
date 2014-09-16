// Copyright (c) 2014,ZhaoStudio
// Author:CptZhao<zhaonanyu@gmail.com>
// Created: 2014-09-10
// Description:
//
//
#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#define SHOWHOST  /*include remote machine on output*/

void showtime(long timeval);

show_info(struct utmp * utbufp)
{
	if(utbufp->ut_type != USER_PROCESS)
		return;
	printf("%-9.9s",utbufp->ut_name);
	printf(" ");
	printf("%-8.8s",utbufp->ut_line);
	printf(" ");
	showtime(utbufp->ut_time);

	#ifdef SHOWHOST
		if(utbufp->ut_host[0]!='\0')
			printf("(%s)",utbufp->ut_host);
	#endif
		printf("\n");
}

void showtime(long timeval)
{
	/*
	char *cp;
	cp = ctime(&timeval);
	printf("%16.12s",cp+4);
	*/
	struct tm *Udate = localtime(&timeval);
	printf("%8d-%2.2d-%2.2d %2.2d:%2.2d ",(1900+Udate->tm_year),(1+Udate->tm_mon),Udate->tm_mday,Udate->tm_hour,Udate->tm_min);
}

int main()
{
	struct utmp current_record;
	int utmpfd;
	int reclen = sizeof(current_record);

	if((utmpfd = open(UTMP_FILE,O_RDONLY)) == -1)
	{
		perror(UTMP_FILE);
		exit(1);
	}

	while(read(utmpfd, &current_record, reclen) == reclen)
	{
		show_info(&current_record);
	}
	close(utmpfd);
	return 0;
}
