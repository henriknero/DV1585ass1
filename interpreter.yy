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
%type  <Node> chunk
%type  <Node> optline
%type  <Node> line
%type  <Node> anything
%type  <Node> spaceeater
%type  <Node> raiseop
%type  <Node> highop
%type  <Node> lowop
%type  <Node> optspace
%token <std::string> VAR
%token <std::string> BLANK
%token <std::string> NL
%token <std::string> NUMERIC
%token <std::string> RAISE
%token <std::string> HIGH_OP
%token <std::string> LOW_OP
%token <std::string> LEFT_PARA
%token <std::string> RIGHT_PARA
%token <std::string> STRING
%token <std::string> EQUALS
%token END 0 "end of file"

%%
chunk      : optline {$$ = Node("chunk","", id++); $$.children.push_back($1);
                        root = $$;
                        }
            |chunk NL optline {$$ = $1;
                                $$.children.push_back($3);
                                root = $$;
                                } 
            ;

optline     : {$$ = Node("emptyline","",id++);} 
            | line {$$ = $1;} 
            ;

line		: lowop {$$ = $1;} 
			| line lowop {$$ = $1; $$.children.push_back($2);}
			;

lowop		: highop {$$ = $1;}
			| lowop LOW_OP highop {$$ = Node("OP",$2,id++);
			                        $$.children.push_back($1);
                                    $$.children.push_back($3);
									}
			;
highop		: raiseop {$$ = $1;}
			| highop HIGH_OP raiseop {$$ = Node("OP",$2,id++);
									$$.children.push_back($1);
									$$.children.push_back($3);
									}
			;

raiseop		: spaceeater {$$ = $1;}
			| raiseop RAISE spaceeater {$$ = Node("OP",$2,id++); 
									$$.children.push_back($1); 
									$$.children.push_back($3);}
			;
spaceeater	: optspace anything optspace {$$ = $2;}
			;

optspace	: {}
			| BLANK {}
			;

anything	: VAR 			{$$ = Node("VAR",$1,id++);}
			| NUMERIC 		{$$ = Node("NUMERIC",$1,id++);}
			| STRING		{$$ = Node("STRING",$1,id++);}
			| LEFT_PARA line RIGHT_PARA {$$ = Node("EXPRES","",id++); $$.children.push_back($2);}
			| VAR LEFT_PARA line RIGHT_PARA {$$ = Node("FUNC",$1,id++); $$.children.push_back($3);}
//			| VAR BLANK EQUALS BLANK line {$$ = Node("ASSIGN","",id++); $$.children.push_back(Node("VAR",$1,id++)); $$.children.push_back($3);}	
			| EQUALS		{$$ = Node("EQUALS",$1,id++);}
			;
