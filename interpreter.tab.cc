// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "interpreter.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "interpreter.tab.hh"

// User implementation prologue.

#line 51 "interpreter.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 9 "interpreter.yy" // lalr1.cc:413

	Node root;
	int id = 0;
	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;

#line 60 "interpreter.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 127 "interpreter.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 31: // block
      case 32: // chunk
      case 33: // stat
      case 34: // assign
      case 35: // functioncall
      case 36: // optspace
      case 37: // explist
      case 38: // exp
      case 39: // lowop
      case 40: // highop
      case 41: // raiseop
      case 42: // spaceeater
      case 43: // anything
      case 44: // tableconstr
      case 45: // args
      case 46: // var
        value.move< Node > (that.value);
        break;

      case 3: // NAME
      case 4: // BLANK
      case 5: // NL
      case 6: // NUMERIC
      case 7: // RAISE
      case 8: // HIGH_OP
      case 9: // LOW_OP
      case 10: // LOGIC
      case 11: // LEFT_PARA
      case 12: // RIGHT_PARA
      case 13: // LCURL
      case 14: // RCURL
      case 15: // DOT
      case 16: // COMMA
      case 17: // EQUALS
      case 18: // STRING
      case 19: // RETURN
      case 20: // BREAK
      case 21: // DO
      case 22: // WHILE
      case 23: // ENDD
      case 24: // IF
      case 25: // TRUE
      case 26: // FALSE
      case 27: // THEN
      case 28: // FOR
      case 29: // IN
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 31: // block
      case 32: // chunk
      case 33: // stat
      case 34: // assign
      case 35: // functioncall
      case 36: // optspace
      case 37: // explist
      case 38: // exp
      case 39: // lowop
      case 40: // highop
      case 41: // raiseop
      case 42: // spaceeater
      case 43: // anything
      case 44: // tableconstr
      case 45: // args
      case 46: // var
        value.copy< Node > (that.value);
        break;

      case 3: // NAME
      case 4: // BLANK
      case 5: // NL
      case 6: // NUMERIC
      case 7: // RAISE
      case 8: // HIGH_OP
      case 9: // LOW_OP
      case 10: // LOGIC
      case 11: // LEFT_PARA
      case 12: // RIGHT_PARA
      case 13: // LCURL
      case 14: // RCURL
      case 15: // DOT
      case 16: // COMMA
      case 17: // EQUALS
      case 18: // STRING
      case 19: // RETURN
      case 20: // BREAK
      case 21: // DO
      case 22: // WHILE
      case 23: // ENDD
      case 24: // IF
      case 25: // TRUE
      case 26: // FALSE
      case 27: // THEN
      case 28: // FOR
      case 29: // IN
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 31: // block
      case 32: // chunk
      case 33: // stat
      case 34: // assign
      case 35: // functioncall
      case 36: // optspace
      case 37: // explist
      case 38: // exp
      case 39: // lowop
      case 40: // highop
      case 41: // raiseop
      case 42: // spaceeater
      case 43: // anything
      case 44: // tableconstr
      case 45: // args
      case 46: // var
        yylhs.value.build< Node > ();
        break;

      case 3: // NAME
      case 4: // BLANK
      case 5: // NL
      case 6: // NUMERIC
      case 7: // RAISE
      case 8: // HIGH_OP
      case 9: // LOW_OP
      case 10: // LOGIC
      case 11: // LEFT_PARA
      case 12: // RIGHT_PARA
      case 13: // LCURL
      case 14: // RCURL
      case 15: // DOT
      case 16: // COMMA
      case 17: // EQUALS
      case 18: // STRING
      case 19: // RETURN
      case 20: // BREAK
      case 21: // DO
      case 22: // WHILE
      case 23: // ENDD
      case 24: // IF
      case 25: // TRUE
      case 26: // FALSE
      case 27: // THEN
      case 28: // FOR
      case 29: // IN
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 63 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
                        root = yylhs.value.as< Node > ();
                        }
#line 601 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 67 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("chunk","",id++);yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 607 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 68 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
                                root = yylhs.value.as< Node > ();
                                }
#line 616 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 73 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 622 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 74 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 628 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 75 "interpreter.yy" // lalr1.cc:859
    {
					yylhs.value.as< Node > () = Node("for","",id++);
					yylhs.value.as< Node > ().children.push_back(Node("var",yystack_[11].value.as< std::string > (),id++));
					yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ());
					yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
					yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
					}
#line 640 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 82 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("If","",id++); 
														yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
														yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());}
#line 648 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 87 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("assign",yystack_[2].value.as< std::string > (),id++);
											  std::cout << "Assigning var to" << std::endl;
											  yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
											  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
											  }
#line 658 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 92 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("assign",yystack_[2].value.as< std::string > (), id++);
															   yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
															   yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 666 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 99 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("funccall","",id++); 
												std::cout << "funccall build" << std::endl;
												yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
												yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 675 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 105 "interpreter.yy" // lalr1.cc:859
    {std::cout << "optspace is called but empty"<< std::endl;}
#line 681 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 106 "interpreter.yy" // lalr1.cc:859
    {std::cout << "optspace is called not empty"<< std::endl;}
#line 687 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 109 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("explist","",id++);yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());std::cout << "explist"<< std::endl;}
#line 693 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 110 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
								yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 700 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 113 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();std::cout << "lowop" << std::endl;}
#line 706 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 115 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 712 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 116 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++);
													yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
													yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
													}
#line 721 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 121 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 727 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 122 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++);
									yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
									yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
									}
#line 736 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 128 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 742 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 129 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++); 
									yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
									yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 750 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 134 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();}
#line 756 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 137 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 762 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 138 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("String",yystack_[0].value.as< std::string > (),id++);}
#line 768 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 139 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Number",yystack_[0].value.as< std::string > (),id++);}
#line 774 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 140 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();std::cout << "prefix params" << std::endl;}
#line 780 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 141 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 786 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 142 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("bool",yystack_[0].value.as< std::string > (),id++);}
#line 792 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 143 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("bool",yystack_[0].value.as< std::string > (),id++);}
#line 798 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 146 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("list","",id++); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 804 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 149 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("emptypara","",id++);}
#line 810 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 150 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("String", yystack_[0].value.as< std::string > (),id++);}
#line 816 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 152 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("args","",id++); 
														yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 823 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 156 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("var",yystack_[0].value.as< std::string > (),id++); std::cout << "var is made:" << yystack_[0].value.as< std::string > () << std::endl;}
#line 829 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 157 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("var", yystack_[0].value.as< std::string > (), id++));}
#line 835 "interpreter.tab.cc" // lalr1.cc:859
    break;


#line 839 "interpreter.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -35;

  const signed char parser::yytable_ninf_ = -13;

  const signed char
  parser::yypact_[] =
  {
       9,   -35,    16,     5,     2,   -35,     9,    19,   -35,   -35,
     -35,    61,     4,    -6,    -4,    13,   -35,   -35,     7,    28,
     -35,   -35,     9,     9,   -35,   -35,   -35,     9,   -35,    20,
     -35,     8,     9,     9,     9,     9,     9,     9,    29,    26,
     -35,   -35,    42,     9,     9,   -35,    -4,    13,   -35,    23,
      30,   -35,   -35,     9,   -35,    65,    -1,     9,     9,     9,
     -35,   -35,   -35,   -35,    33,     3,   -35,     9,    39,     9,
      35,     9,    32,     9,    31,     9,   -35
  };

  const unsigned char
  parser::yydefact_[] =
  {
      12,    13,     0,    12,    12,     1,    12,     0,     4,     5,
       6,     0,    12,    16,    17,    19,    21,     3,     0,     0,
      35,    26,    12,    12,    25,    29,    30,    12,    28,    24,
      33,     0,    12,    12,    12,    12,    12,    12,     0,     0,
      14,    23,     0,    12,    12,    11,    18,    20,    22,     0,
       0,    27,    31,    12,    36,     0,     0,    12,    12,    12,
      15,    32,    34,    10,     9,    14,     8,    12,     0,    12,
       0,    12,     0,    12,     0,    12,     7
  };

  const signed char
  parser::yypgoto_[] =
  {
     -35,   -34,   -35,    51,   -35,     6,     0,   -33,    -5,   -35,
      24,    22,    25,   -35,   -35,   -35,   -35
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     9,    10,    11,    39,    12,    13,
      14,    15,    16,    27,    28,    32,    29
  };

  const signed char
  parser::yytable_[] =
  {
       4,    18,    49,    33,    34,    -2,     1,     1,     1,     1,
      56,    62,    31,     1,   -12,    53,     5,    38,    40,    43,
      35,    30,    30,    19,    64,    44,     6,    41,    -2,     6,
       7,    37,    45,     7,    36,    42,     4,    50,    40,    74,
      52,    51,    53,    55,    57,    54,    58,    59,    60,    53,
      43,    71,    65,    73,    75,    17,    47,    46,    66,    67,
      48,     0,    69,    63,    20,    68,    72,    21,    20,    70,
       0,    21,    22,     4,    23,    76,    22,    61,    23,    24,
       0,     0,     0,    24,     0,     0,    25,    26,     0,     0,
      25,    26
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     6,    36,     9,     8,     0,     4,     4,     4,     4,
      43,    12,    12,     4,    11,    16,     0,    22,    23,    11,
       7,    18,    18,     4,    57,    17,    24,    27,    23,    24,
      28,     3,    32,    28,    27,    15,    36,    37,    43,    73,
      14,    12,    16,    43,    44,     3,    23,    17,    53,    16,
      11,    16,    57,    21,    23,     4,    34,    33,    58,    59,
      35,    -1,    67,    57,     3,    65,    71,     6,     3,    69,
      -1,     6,    11,    73,    13,    75,    11,    12,    13,    18,
      -1,    -1,    -1,    18,    -1,    -1,    25,    26,    -1,    -1,
      25,    26
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    31,    32,    36,     0,    24,    28,    33,    34,
      35,    36,    38,    39,    40,    41,    42,    33,    38,     4,
       3,     6,    11,    13,    18,    25,    26,    43,    44,    46,
      18,    36,    45,     9,     8,     7,    27,     3,    38,    37,
      38,    36,    15,    11,    17,    36,    40,    41,    42,    31,
      36,    12,    14,    16,     3,    36,    37,    36,    23,    17,
      38,    12,    12,    35,    37,    38,    36,    36,    36,    38,
      36,    16,    38,    21,    31,    23,    36
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    30,    31,    32,    32,    33,    33,    33,    33,    34,
      34,    35,    36,    36,    37,    37,    38,    39,    39,    40,
      40,    41,    41,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    45,    45,    45,    46,    46
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     1,    14,     6,     5,
       5,     3,     0,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     4,     1,     4,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NAME", "BLANK", "NL",
  "NUMERIC", "RAISE", "HIGH_OP", "LOW_OP", "LOGIC", "LEFT_PARA",
  "RIGHT_PARA", "LCURL", "RCURL", "DOT", "COMMA", "EQUALS", "STRING",
  "RETURN", "BREAK", "DO", "WHILE", "ENDD", "IF", "TRUE", "FALSE", "THEN",
  "FOR", "IN", "$accept", "block", "chunk", "stat", "assign",
  "functioncall", "optspace", "explist", "exp", "lowop", "highop",
  "raiseop", "spaceeater", "anything", "tableconstr", "args", "var", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    63,    63,    67,    68,    73,    74,    75,    82,    87,
      92,    99,   105,   106,   109,   110,   113,   115,   116,   121,
     122,   128,   129,   134,   137,   138,   139,   140,   141,   142,
     143,   146,   149,   150,   151,   156,   157
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1163 "interpreter.tab.cc" // lalr1.cc:1167
#line 159 "interpreter.yy" // lalr1.cc:1168

