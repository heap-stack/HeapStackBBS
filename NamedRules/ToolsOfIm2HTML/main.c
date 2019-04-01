/*
 * file name: main.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 15 Mar 2019 06:48:00 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

FILE *yyin, *out;
extern int yylex();
static void Exception(char *msg, ...)
{
	va_list ap;
	va_start(ap, msg);
	vfprintf(stderr, msg, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(-1);
}

static char *cutsuffix(char *str, char c)
{
	char *p = str;
	while (*p++ != c && *p != '\0');
	return p;
}

int main(int argc, char *argv[])
{
	if (argc != 3) 
		Exception("Usage: %s <*.im> <*.html>", argv[0]);
	char *arg2_suffix = cutsuffix(argv[1], '.');
	char *arg3_suffix = cutsuffix(argv[2], '.');
	if (strcmp(arg2_suffix, "im"))
		Exception("Second arguments type %s not matched", arg2_suffix);
	if (strcmp(arg3_suffix, "html"))
		Exception("Third arguments type %s not matched", arg3_suffix);
	if ((yyin = fopen(argv[1], "r+")) == NULL)
		Exception("%s", strerror(errno));
	if ((out = fopen(argv[2], "w+")) == NULL)
		Exception("%s", strerror(errno));
	yylex();
	fclose(out);
	fclose(yyin);
	return 0;
}
