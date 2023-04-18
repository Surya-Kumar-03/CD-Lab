%option noyywrap
%{
	#include<stdio.h>
	void yyerror(char*);
%}
operator [-+*=]
digit [0-9]
letter [a-zA-Z]
%%
else|int|float|if {printf("%s is a keyword\n", yytext);}
{letter}({letter}|{digit})* {printf("%s is an identifier\n",yytext);}
{digit}+ {printf("%s is a digit\n", yytext);}
{operator} {printf("%s is an operator\n", yytext);}
%%
void yyerror(char* c)
{
	printf("%s\n", c);
}
int main()
{
	yylex();
	return 0;
}