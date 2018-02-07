%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code{
  #include <string>
  std::string output = "";
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
}
%type <std::string> line
%token <std::string> VAR
%token <std::string> BLANK
%token <std::string> NUMERIC
%token <std::string> OP
%token <std::string> LEFT_PARA
%token <std::string> RIGHT_PARA
%token END 0 "end of file"
%%
line : //This is a rule
| line BLANK 
| line VAR {std::cout << "VAR: " << $2 << std::endl;}
| line NUMERIC {std::cout << "NUMERIC: " << $2 << std::endl;}
| line OP {std::cout << "OP: " << $2 << std::endl;}
| line LEFT_PARA {std::cout << "LEFT_PARA: " << $2 << std::endl;}
| line RIGHT_PARA {std::cout << "RIGHT_PARA: " << $2 << std::endl;} 
;
