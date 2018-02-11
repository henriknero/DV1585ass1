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
%type  <Node> explist
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
%token <std::string> COMMA
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
			| prefixexp optspace EQUALS optspace explist optspace {$$ = Node("assign","",id++); 
											  $$.children.push_back($1);
											  $$.children.push_back($5);} 
			;
functioncall: prefixexp args optspace {$$ = Node("funccall","",id++); 
												std::cout << "funccall build" << std::endl;
												$$.children.push_back($1); 
												$$.children.push_back($2);}
			;

optspace	: {std::cout << "optspace is called but empty"<< std::endl;}
			| BLANK {std::cout << "optspace is called not empty"<< std::endl;}
			;

explist		: exp {$$ = Node("explist","",id++);$$.children.push_back($1);}
			| explist optspace COMMA optspace exp {$$ = $1;
													$$.children.push_back($5);}

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
anything	: NUMERIC optspace {$$ = Node("Number",$1,id++);}
			| prefixexp optspace {$$ = $1;}
			
			;

prefixexp	: var {$$ = $1;std::cout << "var added to prefix: " << std::endl;}
			| functioncall {$$ = $1;}
			| LEFT_PARA optspace exp optspace RIGHT_PARA {$$ = $3;}
			;
args		:LEFT_PARA optspace RIGHT_PARA {$$ = Node("emptypara","",id++);} 
			|BLANK STRING {$$ = Node("String", $1,id++);}
			|LEFT_PARA optspace explist optspace RIGHT_PARA 
														{$$ = Node("args","",id++); 
														$$.children.push_back($3);}
			;

var			: NAME {$$ = Node("var",$1,id++);std::cout << "var created" << $1 << std::endl;}
			;
%%
