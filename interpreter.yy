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
%type  <Node> block
%type  <Node> chunk
%type  <Node> stat
%type  <Node> functioncall
%type  <Node> exp
%type  <Node> prefixexp
%type  <Node> args
%type  <Node> raiseop
%type  <Node> highop
%type  <Node> assign
%type  <Node> lowop
%type  <Node> anything
%type  <Node> optspace
%type  <Node> var
%token <std::string> NAME
%token <std::string> BLANK
%token <std::string> NL
%token <std::string> NUMERIC
%token <std::string> RAISE
%token <std::string> HIGH_OP
%token <std::string> LOW_OP
%token <std::string> LEFT_PARA
%token <std::string> RIGHT_PARA
%token <std::string> EQUALS
%token <std::string> STRING

%token <std::string> RETURN
%token <std::string> BREAK
%token <std::string> DO
%token <std::string> WHILE
%token <std::string> ENDD
%token <std::string> IF
%token <std::string> THEN
%token END 0 "end of file"

%%
block      : chunk {$$ = $1;
                        root = $$;
                        }
            ;
chunk		: stat {$$ = Node("chunk","",id++);$$.children.push_back($1);}
			| chunk stat 		{$$ = $1;
                                $$.children.push_back($2);
                                root = $$;
                                } 
			;
stat	    : assign {$$ = $1;} 
            ;

assign		: functioncall {$$ = $1;}
			| var optspace EQUALS optspace exp optspace {$$ = Node("assign","",id++); 
											  $$.children.push_back($1);
											  $$.children.push_back($5);} 
			;
functioncall: prefixexp optspace args optspace	{$$ = Node("funccall","",id++); 
												$$.children.push_back($1); 
												$$.children.push_back($3);}
			;

optspace	: {}
			| BLANK {}
			;

exp			: STRING {$$ = Node("String",$1,id++);}
			| optspace prefixexp optspace {$$ = $2;}
			| lowop {$$ = $1;}
			;	
lowop		: highop {$$ = $1;}
			| lowop optspace LOW_OP optspace highop {$$ = Node("OP",$3,id++);
													$$.children.push_back($1);
													$$.children.push_back($5);
													}
			;
highop		: raiseop {$$ = $1;}
			| highop optspace HIGH_OP optspace raiseop {$$ = Node("OP",$3,id++);
									$$.children.push_back($1);
									$$.children.push_back($5);
									}
			;

raiseop		: anything			{$$ = $1;}
			| raiseop optspace RAISE optspace anything {$$ = Node("OP",$3,id++); 
									$$.children.push_back($1); 
									$$.children.push_back($5);}
			
			;
anything	: optspace NUMERIC optspace {$$ = Node("Number",$2,id++);}
			| optspace prefixexp optspace {$$ = $2;}
			
			;

prefixexp	: LEFT_PARA optspace exp optspace RIGHT_PARA {$$ = $3;}
			| var {$$ = $1;}
			;
args		:LEFT_PARA RIGHT_PARA {} 
			|LEFT_PARA optspace exp optspace RIGHT_PARA {$$ = Node("args","",id++); 
														$$.children.push_back($3);}
			;

var			: NAME			{$$ = Node("var",$1,id++);}
			;
