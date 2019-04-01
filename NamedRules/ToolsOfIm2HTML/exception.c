/*
 * file name: exception.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 09:17:28 AM CST
 */

#include "exception.h"

void raise_exception(enum exception e, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	do_exception(e, fmt, ap); 
	va_end(ap);
	putchar('\n');
	exit(-1);
}

void do_exception(enum exception e, const char *fmt, va_list ap)
{
	char buf[MAXBUF];
	int len = 0;
	if (e) {
		char *estr = get_exception_err(e);
		len = strlen(estr);
		snprintf(buf, MAXBUF - 1, 
				"%s", estr);
	}
	vsnprintf(buf + len, MAXBUF - 1, fmt, ap);
	fputs(buf, stderr);
	fflush(stdout);
}

char *get_exception_err(enum exception e)
{
	char *buf = NEW(buf);
	switch (e) {
	case MEMORY_EXCEPTION:
		buf = "Memory allocate exception: ";
		break;
	case STACK_EXCEPTION:
		buf = "Stack error: ";
		break;
	case QUEUE_EXCEPTION:
		buf = "Queue error: ";
		break;
	case TREE_EXCEPTION:
		buf = "Tree error: ";
		break;
	default:
		buf = "Unknown's exception: ";
		break;
	}
	return buf;
}
