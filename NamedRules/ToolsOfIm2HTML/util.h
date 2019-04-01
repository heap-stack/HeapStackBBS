/*
 * file name: include/util.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 22 Feb 2019 06:25:02 PM CST
 */

#ifndef _UTIL_H
#define _UTIL_H
typedef int   bool;
enum {
	FALSE, TRUE,
};
extern void *checked_malloc(int len);
extern char* String(char* s);

#define ARRLENG(x)	(sizeof((x)) / sizeof(*(x)))

#endif
