// Copyright (c) 2015, ZhaoStudio
// Author: CptZhao<zhaonanyu@gmail.com>
// Created: 2015-03-25
// Description:
// map a->b b->c ... z->a
#include <stdio.h>
#include <ctype.h>

int main()
{
	int c;
	while (( c = getchar()) != EOF ) {
		if ( c == 'z')
			c = 'a';
		else if ( islower(c) )
			c++;
		putchar(c);
	}
}
