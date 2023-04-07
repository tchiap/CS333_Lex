%{
#include <stdio.h>
%}

%union {
int val; 
char var;
}

%token <val> NUMBER
%token <var> NAME

%type <val> expr
%type <var> expr2
%type <var> stmt

%right '('
%left '-' '+'

%%

stmt:  
	expr { $$ = $1 ; printf('%d\n', $1); }
;

expr:
	'(' expr2 ')' { $$ = $2 ; } | 
	NUMBER { $$ = $1 ; }
;

expr2: 
	expr { $$ = $1 ; } |
	'+' expr expr { $$ = $2 + $3 ; } | 
	'-' expr expr { $$ = $2 - $3 ; } |
	'*' expr expr { $$ = $2 * $3 ; }
;


%%

main()
{
	return yyparse();
}

int yyerror(char *s)
{
	printf("%s\n", s);
	return 0;
}
	

