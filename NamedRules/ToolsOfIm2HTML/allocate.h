/*
 * file name: allocate.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 09:14:13 AM CST
 */

#ifndef _ALLOCATE_H
#define _ALLOCATE_H
#include "exception.h"
#include <stdlib.h>

#define MAXBUF 		4096
#define NEW(x) 		((__typeof(x)) malloc(sizeof(*x)))

#endif 
