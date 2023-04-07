
%{
#include "calc.tab.h"
extern YYSTYPE yylval;
%}
%%
[0-9]+ {yylval.val = atoi(yytext);
return NUMBER;}
[\t]+ ; /* ignore whitespaces */
[a-zA-Z] {yylval.var = yytext[0];
return NAME;}
\n return 0; /* logical EOF */
. return yytext[0];
%%
