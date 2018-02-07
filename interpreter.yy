%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code requires{
	#include "Node.hh"
	#include <string>
}
%code{
	Node root;
	int id = 0;
	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;
}
%type  <Node> stream
%type  <Node> optline
%type  <Node> line
%type  <Node> anything
%type  <Node> spaceeater
%type  <Node> operator
%type  <Node> optspace
%token <std::string> VAR
%token <std::string> BLANK
%token <std::string> NL
%token <std::string> NUMERIC
%token <std::string> OP
%token <std::string> LEFT_PARA
%token <std::string> RIGHT_PARA
%token END 0 "end of file"

%%
stream      : optline {$$= $1;
                        root = $$;
                        }
            |stream NL optline {$$ = $1;
                                $$.children.push_back($3);
                                root = $$;
                                } 
            ;

optline     : {$$ = Node("emptyline","",id++);} 
            | line {$$ = $1;} 
            ;

line		: operator {$$ = $1;} 
			| line operator {$$ = $1; $$.children.push_back($2);}

operator	: spaceeater {$$ = $1;}
			| operator OP spaceeater {$$ = Node("OP",$2,id++); 
									$$.children.push_back($1); 
									$$.children.push_back($3);}

spaceeater	: optspace anything optspace {$$ = $2;}
			;

optspace	: {}
			| BLANK {}
			;

anything 	: //This is a rule
			| VAR 			{$$ = Node("VAR ",$1,id++);}
			| NUMERIC 		{$$ = Node("NUMERIC ",$1,id++);}
			| LEFT_PARA line RIGHT_PARA {$$ = Node("EXPRES","",id++); $$.children.push_back($2);}
			;
