#######################################################################
# file name: Makefile
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Fri 15 Mar 2019 06:44:25 PM CST
#######################################################################

OBJ := lex.yy.o util.o stack.o exception.o main.o
FILEDIRS := ../
FILE := $(FILEDIRS)basic
Im2Html: $(OBJ)
	$(CC) $^ -o $@
	./$@ $(FILE).im $(FILE).html 
$(OBJ): lex.yy.c util.c stack.c exception.c main.c
lex.yy.c: Im2Html.lex 
	lex Im2Html.lex  
clean:
	rm -rf *.o lex.yy.c y.tab.c y.tab.h Im2Html
