/*
 * file name: exception.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 09:15:58 AM CST
 */

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "allocate.h"

enum exception {
	NULL_EXCEPTION   = 0,
	MEMORY_EXCEPTION = 256,
	STACK_EXCEPTION,
	QUEUE_EXCEPTION,
	TREE_EXCEPTION,
};
extern void raise_exception(enum exception e, const char *fmt, ...);
extern void do_exception(enum exception e, const char *fmt, va_list ap);
extern char *get_exception_err(enum exception e);
#endif 
