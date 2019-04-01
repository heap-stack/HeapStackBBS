/*
 * file name: stack.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 02:51:48 PM CST
 */

#ifndef _STACK_H
#define _STACK_H

typedef char *dtype_t;
#define T 	Stack
typedef struct T *T;

extern T       STK_new();
extern int     STK_is_empty(T stk);
extern void    STK_make_empty(T stk);
extern void    STK_push(T stk, dtype_t x);
extern dtype_t STK_pop(T stk);
extern dtype_t STK_get_top(T stk);
extern void    STK_prints(T stk);

#undef T 

#endif
