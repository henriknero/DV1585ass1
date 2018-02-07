%top{
#include "interpreter.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%
[+*/%<>\-\^]|<=|>=|==|~=|and|or|\.\.|#|not 	{return yy::parser::make_OP(yytext);}
[a-zA-Z_][a-zA-Z0-9_]*						{return yy::parser::make_VAR(yytext);}
[ \t\n]*									{return yy::parser::make_BLANK(yytext);}	
[0-9]+										{return yy::parser::make_NUMERIC(yytext);}
[(]											{return yy::parser::make_LEFT_PARA(yytext);}	
[)]											{return yy::parser::make_RIGHT_PARA(yytext);}
<<EOF>>       								return yy::parser::make_END();
%%
