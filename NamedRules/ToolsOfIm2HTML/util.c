/*
 * file name: util.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 22 Feb 2019 08:54:43 PM CST
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "util.h"

void *checked_malloc(int len)
{
	void *m;
	m = malloc(len);
	assert(m);
	return m;
}

char* String(char* s)
{
	char* p = checked_malloc(strlen(s)+1);
	strcpy(p,s);
	return p;
}
