%top{
#include "interpreter.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%x STRING
%%
\^											{return yy::parser::make_RAISE(yytext);}
[*/]										{return yy::parser::make_HIGH_OP(yytext);}
[+%<>\-]|<=|>=|==|~=|and|or|\.\.|#|not 	{return yy::parser::make_LOW_OP(yytext);}
[a-zA-Z_][a-zA-Z0-9_]*						{return yy::parser::make_VAR(yytext);}
[ ]*										{return yy::parser::make_BLANK(yytext);}	
[\n]*										{return yy::parser::make_NL(yytext);}	
[0-9]+										{return yy::parser::make_NUMERIC(yytext);}
[(]											{return yy::parser::make_LEFT_PARA(yytext);}	
[)]											{return yy::parser::make_RIGHT_PARA(yytext);}
[=]											{return yy::parser::make_EQUALS(yytext);}
["]											{BEGIN(STRING);}
<STRING>["]									{BEGIN(0);}
<STRING>[a-zA-Z _:]*						{return yy::parser::make_STRING(yytext);}
<<EOF>>       								return yy::parser::make_END();
%%
