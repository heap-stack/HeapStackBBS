%{
#include "util.h"
#include "stack.h"

int yywrap(void)
{
	return 1;
}
extern FILE *out;
Stack stk;

%}

ws 		[\ ]
char 		[a-zA-Z]
string 		{char}+
ext_char 	[a-zA-Z\.=\\]
ext_string 	{ext_char}+
%%

{ws}+ 		{
			char *s = STK_get_top(stk);
			if (!strcmp(s, "PREDEF")
			|| !strcmp(s, "H1") || !strcmp(s, "H2") || !strcmp(s, "H3")
			|| ! strcmp(s, "H4") || !strcmp(s, "H5") || !strcmp(s, "H6")
			|| !strcmp(s, "PARAGRAPH") || !strcmp(s, "TITLE") || !strcmp(s, "HYPERLINK"))
				fprintf(out, " ");
			continue;
		}
\t		{
			continue;
		}
\n		{continue;}
BEGIN 		{
			stk = STK_new(); 
			STK_push(stk, String(yytext));
			fprintf(out, "<html");
			continue;
		}
TITLE		{
			STK_push(stk, String(yytext));
			fprintf(out, "<head><title");
			continue;

		}
SECTION 	{
			STK_push(stk, String(yytext)); 
			fprintf(out, "<section");
			continue;
		}
PARAGRAPH	{
			STK_push(stk, String(yytext)); 
			fprintf(out, "<p");
			continue;
		}
BODY	 	{
			STK_push(stk, String(yytext)); 
			fprintf(out, "<body");
			continue;
		}
PREDEF		{
			STK_push(stk, String(yytext)); 
			fprintf(out, "<pre");
			continue;
		}
H[1-6]		{
			STK_push(stk, String(yytext)); 
			fprintf(out, "<%s", yytext);
			continue;
		}
HYPERLINK	{
			STK_push(stk, String(yytext));
			fprintf(out, "<a");
			continue;
		}
"{"		{
			fprintf(out, ">");
			continue;
		}
"}" 		{
			char *s = STK_pop(stk);
			if (!strcmp(s, "BEGIN"))
				fprintf(out, "</html>");
			else if (!strcmp(s, "SECTION"))
				fprintf(out, "</section>");
			else if (!strcmp(s, "BODY"))
				fprintf(out, "</body>");
			else if (!strcmp(s, "TITLE"))
				fprintf(out, "</title><head>");
			else if (!strcmp(s, "PREDEF"))
				fprintf(out, "</pre>");
			else if (!strcmp(s, "H1"))
				fprintf(out, "</H1>");
			else if (!strcmp(s, "H2"))
				fprintf(out, "</H2>");
			else if (!strcmp(s, "H3"))
				fprintf(out, "</H3>");
			else if (!strcmp(s, "H4"))
				fprintf(out, "</H4>");
			else if (!strcmp(s, "H5"))
				fprintf(out, "</H5>");
			else if (!strcmp(s, "H6"))
				fprintf(out, "</H6>");
			else if (!strcmp(s, "PARAGRAPH"))
				fprintf(out, "</p>");
			else if (!strcmp(s, "HYPERLINK"))
				fprintf(out, "</a>");
			continue;
		}
";"		{
			fprintf(out, "</br>");
			continue;
		}
"["		{fprintf(out, " ");continue;}
"]"		{continue;}

{string}\=\"{ext_string}\"	{fprintf(out, "%s", yytext);}

.		{
			fprintf(out, "%s", yytext); continue; 
		}
