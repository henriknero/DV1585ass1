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
%type  <Node> tableconstr
%type  <Node> lowop
%type  <Node> anything
%type  <Node> optspace
%type  <Node> spaceeater
%type  <Node> var
%token <std::string> NAME
%token <std::string> BLANK
%token <std::string> NL
%token <std::string> NUMERIC
%token <std::string> RAISE
%token <std::string> HIGH_OP
%token <std::string> LOW_OP
%token <std::string> LOGIC
%token <std::string> LEFT_PARA
%token <std::string> RIGHT_PARA
%token <std::string> LCURL
%token <std::string> RCURL
%token <std::string> DOT
%token <std::string> COMMA
%token <std::string> EQUALS
%token <std::string> STRING

%token <std::string> RETURN
%token <std::string> BREAK
%token <std::string> DO
%token <std::string> WHILE
%token <std::string> ENDD
%token <std::string> IF
%token <std::string> TRUE
%token <std::string> FALSE
%token <std::string> THEN
%token <std::string> FOR
%token <std::string> IN
%token END 0 "end of file"

%%
block      : chunk {$$ = $1;
                        root = $$;
                        }
            ;
chunk		: optspace stat {$$ = Node("chunk","",id++);$$.children.push_back($2);}
			| chunk stat 		{$$ = $1;
                                $$.children.push_back($2);
                                root = $$;
                                } 
			;
stat	    : assign {$$ = $1;} 
			| functioncall {$$ = $1;}
			| FOR BLANK NAME optspace EQUALS optspace exp optspace COMMA exp DO block ENDD optspace {
					$$ = Node("for","",id++);
					$$.children.push_back(Node("var",$3,id++));
					$$.children.push_back($7);
					$$.children.push_back($10);
					$$.children.push_back($12);
					}			
			| IF exp THEN block ENDD optspace {$$ = Node("If","",id++); 
														$$.children.push_back($2);
														$$.children.push_back($4);} 
			;

assign		: exp optspace EQUALS optspace explist {$$ = Node("assign",$3,id++);
											  std::cout << "Assigning var to" << std::endl;
											  $$.children.push_back($1);
											  $$.children.push_back($5);
											  }
			| exp optspace EQUALS optspace functioncall {$$ = Node("assign",$3, id++);
															   $$.children.push_back($1);
															   $$.children.push_back($5);}

			;
			

functioncall: exp args optspace {$$ = Node("funccall","",id++); 
												std::cout << "funccall build" << std::endl;
												$$.children.push_back($1); 
												$$.children.push_back($2);}
			;

optspace	: {std::cout << "optspace is called but empty"<< std::endl;}
			| BLANK {std::cout << "optspace is called not empty"<< std::endl;}
			;

explist		: exp {$$ = Node("explist","",id++);$$.children.push_back($1);std::cout << "explist"<< std::endl;}
			| explist COMMA exp {$$ = $1;
								$$.children.push_back($3);}

exp			: lowop {$$ = $1;std::cout << "lowop" << std::endl;}
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

raiseop		: spaceeater			{$$ = $1;}
			| raiseop RAISE spaceeater {$$ = Node("OP",$2,id++); 
									$$.children.push_back($1); 
									$$.children.push_back($3);}
			
			;
spaceeater	: optspace anything optspace {$$ = $2;}
			;

anything	: var {$$ = $1;}
			| STRING {$$ = Node("String",$1,id++);} 
			| NUMERIC {$$ = Node("Number",$1,id++);}
			| LEFT_PARA exp RIGHT_PARA {$$ = $2;std::cout << "prefix params" << std::endl;}
			| tableconstr {$$ = $1;}
			| TRUE {$$ = Node("bool",$1,id++);}
			| FALSE {$$ = Node("bool",$1,id++);}
			;

tableconstr	: LCURL explist RCURL {$$ = Node("list","",id++); $$.children.push_back($2);}
			;

args		: optspace LEFT_PARA optspace RIGHT_PARA {$$ = Node("emptypara","",id++);} 
			| STRING {$$ = Node("String", $1,id++);}
			| optspace LEFT_PARA explist RIGHT_PARA 
														{$$ = Node("args","",id++); 
														$$.children.push_back($3);}
			;

var			: NAME {$$ = Node("var",$1,id++); std::cout << "var is made:" << $1 << std::endl;}
			| var DOT NAME {$$ = $1; $$.children.push_back(Node("var", $3, id++));}
			;
%%
