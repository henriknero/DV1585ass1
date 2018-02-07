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
	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;
}
%type  <Node> stream
%type  <Node> optline
%type  <Node> line
%type  <Node> anything
%token <std::string> VAR
%token <std::string> BLANK
%token <std::string> NL
%token <std::string> NUMERIC
%token <std::string> OP
%token <std::string> LEFT_PARA
%token <std::string> RIGHT_PARA
%token END 0 "end of file"

%%
stream      : optline {$$ = Node("stream", "");
                        $$.children.push_back($1);
                        root = $$;
                        }
            |stream NL optline {$$ = $1;
                                $$.children.push_back($3);
                                root = $$;
                                } 
            ;

optline     : {$$ = $1}
            | line {$$ = $1);
                    $$.children.push_back($1);} 
            ;

line		: anything {$$ = $1;}
			| line anything {$$ = $1; $$.children.push_back($2);}
anything : //This is a rule
			| BLANK
			| VAR 			{$$ = Node("VAR ",$1);}
			| NUMERIC 		{$$ = Node("NUMERIC ",$1);}
			| OP 			{$$ = Node("OP ",$1);}
			| LEFT_PARA stream RIGHT_PARA {$$ = Node("EXPRES",""); $$.children.push_back($2);}
			;
