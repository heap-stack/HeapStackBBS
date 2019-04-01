/*
 * file name: stack.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 30 Jan 2019 03:02:15 PM CST
 */

#include "stack.h"
#include "exception.h"
#include "allocate.h"
#include <assert.h>

#define T Stack 

struct T {
	dtype_t elem;
	T       next;
};

T STK_new()
{
	T t;
	t = NEW(t);
	if (t == NULL)
		raise_exception(MEMORY_EXCEPTION,
				"(%s: at %d line) Allocate error",
				__FILE__, __LINE__);
	t->next = NULL;
	t->elem = 0;
	return t;
}
int STK_is_empty(T stk)
{
	return stk->next == NULL;
}

void STK_make_empty(T stk)
{
	if (!STK_is_empty(stk))
		while (stk->next != NULL)
			(void)STK_pop(stk);
	else
		raise_exception(STACK_EXCEPTION,
				"(%s: at %d line) Empty stack",
				__FILE__, __LINE__);
}
void STK_push(T stk, dtype_t x)
{
	T t;
	t = NEW(t);
	if (t == NULL)
		raise_exception(MEMORY_EXCEPTION, 
				"(%s: at %d line) Allocate error",
				__FILE__, __LINE__);
	t->elem = x;
	t->next = stk->next;
	stk->next = t;
}

void STK_prints(T stk)
{
	T t;
	if (STK_is_empty(stk)) 
		raise_exception(STACK_EXCEPTION,
				"(%s: at %d line) Empty stack",
				__FILE__, __LINE__);
	t = stk->next;
	while (t != NULL) {
		printf("%s ", t->elem);
		t = t->next;
	}
}
dtype_t STK_pop(T stk)
{
	T tmpnode;
	dtype_t elem;
	if (STK_is_empty(stk)) 
		raise_exception(STACK_EXCEPTION,
				"(%s: at %d line) Empty stack",
				__FILE__, __LINE__);
	tmpnode = stk->next;
	elem = tmpnode->elem;
	stk->next = stk->next->next;
	free(tmpnode);
	return elem;

}

dtype_t STK_get_top(T stk)
{
	return stk->next->elem;
}
