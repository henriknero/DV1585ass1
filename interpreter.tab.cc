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
      case 37: // block
      case 38: // chunk
      case 39: // stat
      case 40: // if
      case 41: // else
      case 42: // assign
      case 43: // functioncall
      case 44: // optspace
      case 45: // explist
      case 46: // exp
      case 47: // lowop
      case 48: // highop
      case 49: // raiseop
      case 50: // spaceeater
      case 51: // anything
      case 52: // tableconstr
      case 53: // args
      case 54: // prefixexp
      case 55: // varlist
      case 56: // var
      case 57: // namelist
      case 58: // funcname
      case 59: // laststat
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
      case 15: // LHARD
      case 16: // RHARD
      case 17: // DOT
      case 18: // COMMA
      case 19: // EQUALS
      case 20: // STRING
      case 21: // FUNCTION
      case 22: // RETURN
      case 23: // BREAK
      case 24: // REPEAT
      case 25: // UNTIL
      case 26: // DO
      case 27: // WHILE
      case 28: // ENDD
      case 29: // IF
      case 30: // ELSE
      case 31: // TRUE
      case 32: // FALSE
      case 33: // THEN
      case 34: // FOR
      case 35: // IN
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
      case 37: // block
      case 38: // chunk
      case 39: // stat
      case 40: // if
      case 41: // else
      case 42: // assign
      case 43: // functioncall
      case 44: // optspace
      case 45: // explist
      case 46: // exp
      case 47: // lowop
      case 48: // highop
      case 49: // raiseop
      case 50: // spaceeater
      case 51: // anything
      case 52: // tableconstr
      case 53: // args
      case 54: // prefixexp
      case 55: // varlist
      case 56: // var
      case 57: // namelist
      case 58: // funcname
      case 59: // laststat
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
      case 15: // LHARD
      case 16: // RHARD
      case 17: // DOT
      case 18: // COMMA
      case 19: // EQUALS
      case 20: // STRING
      case 21: // FUNCTION
      case 22: // RETURN
      case 23: // BREAK
      case 24: // REPEAT
      case 25: // UNTIL
      case 26: // DO
      case 27: // WHILE
      case 28: // ENDD
      case 29: // IF
      case 30: // ELSE
      case 31: // TRUE
      case 32: // FALSE
      case 33: // THEN
      case 34: // FOR
      case 35: // IN
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
      case 37: // block
      case 38: // chunk
      case 39: // stat
      case 40: // if
      case 41: // else
      case 42: // assign
      case 43: // functioncall
      case 44: // optspace
      case 45: // explist
      case 46: // exp
      case 47: // lowop
      case 48: // highop
      case 49: // raiseop
      case 50: // spaceeater
      case 51: // anything
      case 52: // tableconstr
      case 53: // args
      case 54: // prefixexp
      case 55: // varlist
      case 56: // var
      case 57: // namelist
      case 58: // funcname
      case 59: // laststat
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
      case 15: // LHARD
      case 16: // RHARD
      case 17: // DOT
      case 18: // COMMA
      case 19: // EQUALS
      case 20: // STRING
      case 21: // FUNCTION
      case 22: // RETURN
      case 23: // BREAK
      case 24: // REPEAT
      case 25: // UNTIL
      case 26: // DO
      case 27: // WHILE
      case 28: // ENDD
      case 29: // IF
      case 30: // ELSE
      case 31: // TRUE
      case 32: // FALSE
      case 33: // THEN
      case 34: // FOR
      case 35: // IN
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
#line 75 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
                        root = yylhs.value.as< Node > ();
                        }
#line 640 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 79 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("chunk","",id++);yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 646 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 80 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
                                root = yylhs.value.as< Node > ();
                                }
#line 655 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 84 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 661 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 85 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 667 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 87 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 673 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 88 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 679 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 89 "interpreter.yy" // lalr1.cc:859
    {
					yylhs.value.as< Node > () = Node("for","",id++);
					yylhs.value.as< Node > ().children.push_back(Node("var",yystack_[11].value.as< std::string > (),id++));
					yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ());
					yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
					yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
					}
#line 691 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 96 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Repeat","",id++); 
										yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
										yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 699 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 99 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();}
#line 705 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 100 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("ifelse","",id++); 
											yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
											yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());}
#line 713 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 103 "interpreter.yy" // lalr1.cc:859
    {
						yylhs.value.as< Node > () = Node("Function", "", id++);
						yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ());
						yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
						yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
						}
#line 724 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 110 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("If","",id++); 
														yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
														yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 732 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 114 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Else","",id++);
							yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
							}
#line 740 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 118 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("assign",yystack_[2].value.as< std::string > (),id++);
											  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
											  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
											  }
#line 749 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 124 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("funccall","",id++); 
												yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
												yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 757 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 129 "interpreter.yy" // lalr1.cc:859
    {}
#line 763 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 130 "interpreter.yy" // lalr1.cc:859
    {}
#line 769 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 133 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 775 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 134 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
								yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 782 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 137 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 788 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 139 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 794 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 140 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++);
													yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
													yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
													}
#line 803 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 145 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 809 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 146 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++);
									yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
									yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
									}
#line 818 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 152 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 824 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 153 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++); 
									yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
									yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 832 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 158 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();}
#line 838 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 161 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 844 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 162 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("String",yystack_[0].value.as< std::string > (),id++);}
#line 850 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 163 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Number",yystack_[0].value.as< std::string > (),id++);}
#line 856 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 164 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();}
#line 862 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 165 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 868 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 166 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("bool",yystack_[0].value.as< std::string > (),id++);}
#line 874 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 167 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("bool",yystack_[0].value.as< std::string > (),id++);}
#line 880 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 168 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[1].value.as< std::string > (),id++); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 886 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 171 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("list","",id++); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 892 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 174 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("emptypara","",id++);}
#line 898 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 175 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("String", yystack_[0].value.as< std::string > (),id++);}
#line 904 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 177 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("args","",id++); 
														yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 911 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 181 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 917 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 182 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 923 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 184 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("varlist","",id++);yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 929 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 185 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 935 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 187 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("var",yystack_[0].value.as< std::string > (),id++);}
#line 941 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 188 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("var", yystack_[0].value.as< std::string > (), id++));}
#line 947 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 189 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Array","",id++); 
									yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
									yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 955 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 193 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Namelist","",id++); yylhs.value.as< Node > ().children.push_back(Node("Name", yystack_[0].value.as< std::string > (), id++));}
#line 961 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 194 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); 
													yylhs.value.as< Node > ().children.push_back(Node("Name",yystack_[0].value.as< std::string > (),id++));}
#line 968 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 197 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("funcname",yystack_[0].value.as< std::string > (),id++);}
#line 974 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 198 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("subfunc",yystack_[0].value.as< std::string > (),id++));}
#line 980 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 200 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Return","",id++); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 986 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 201 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Break","",id++);}
#line 992 "interpreter.tab.cc" // lalr1.cc:859
    break;


#line 996 "interpreter.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -42;

  const signed char parser::yytable_ninf_ = -44;

  const signed char
  parser::yypact_[] =
  {
      11,   -42,    47,     3,     3,   -42,   -42,    49,    11,   -42,
      11,    11,    52,   -42,   -10,   -42,    10,    18,    31,    29,
     -42,   -42,   -42,    56,   116,    43,   -42,    53,    55,    65,
     -42,    59,    41,    74,    11,    11,    50,   -42,    69,    11,
      11,    11,    11,    82,   -42,   -42,    -4,   -42,    11,    11,
      11,   -42,   -42,   -42,   -42,    11,   -42,    32,    68,    11,
      11,    11,    11,    11,    11,    11,   -42,   -42,    11,    11,
     -42,    84,    11,    72,   -42,    86,    89,   -42,    30,    -2,
     -42,   -42,    55,    65,   -42,   -42,   -42,    75,   -42,    70,
      33,    29,    43,   -42,   -42,    -1,   -42,   -42,   -42,    11,
     -42,   -42,   -42,    11,    78,    11,    76,    11,    11,    11,
      90,    80,   -42,   -42,    11,    79,    11,    83,    11,   -42
  };

  const unsigned char
  parser::yydefact_[] =
  {
      18,    19,     0,     2,     0,     1,    46,     0,    18,    54,
      18,    18,     0,     4,     0,     7,     8,    18,    42,    18,
       6,     3,     5,     0,     0,    53,    20,    22,    23,    25,
      27,     0,     0,     0,    18,    18,     0,    40,     0,    18,
      18,    18,    18,     0,    44,    51,     0,    32,    18,    18,
      18,    31,    35,    36,    43,    18,    34,    30,    42,    18,
      18,    18,    18,    18,    18,    18,    11,    15,    18,    18,
      17,     0,    18,     0,    47,     0,     0,    37,     0,     0,
      29,    21,    24,    26,    28,    10,    14,     0,    12,     0,
       0,    18,    16,    48,    49,    18,    52,    33,    38,    18,
      39,    41,    45,    18,     0,    18,     0,    18,    18,    18,
       0,     0,    13,    50,    18,     0,    18,     0,    18,     9
  };

  const signed char
  parser::yypgoto_[] =
  {
     -42,    -6,   -42,    96,   -42,   -42,   -42,   -23,     0,   -41,
      12,   -42,    46,    51,    58,   -42,   -42,   -42,   -22,   -19,
      42,   -42,   -42,   110
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    13,    14,    36,    15,    16,    24,    25,
      26,    27,    28,    29,    30,    55,    56,    39,    17,    18,
      19,    95,    46,    20
  };

  const signed char
  parser::yytable_[] =
  {
       4,    54,    57,     1,    31,    58,     6,    75,    78,    79,
       4,   103,    98,    76,   -43,     1,    59,    38,    34,    44,
      35,   -43,     1,    32,     7,     8,     9,    10,    90,    67,
     -43,    92,    11,     1,    66,     4,     1,    12,    37,    70,
      71,    72,    97,   -18,    42,   101,    43,     5,    59,    40,
      41,    59,    37,    23,    73,    80,    33,    38,    86,    45,
      77,    59,    60,    61,     4,    87,    54,    57,    88,    89,
      58,    81,    62,     6,    64,    85,    47,    65,    68,    48,
      69,    49,   100,    50,    63,    74,    40,     6,    93,    94,
      51,   102,    96,   113,    99,   104,   107,   106,   114,   105,
      21,    52,    53,     4,   109,   116,    82,   110,   111,   112,
     117,   118,    83,    91,    22,     0,     4,   108,   119,     6,
      84,     0,    47,     0,     0,    48,   115,    49,     0,    50,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53
  };

  const signed char
  parser::yycheck_[] =
  {
       0,    24,    24,     4,    10,    24,     3,    11,    49,    50,
      10,    12,    14,    17,     4,     4,    18,    17,    28,    19,
      30,    11,     4,    11,    21,    22,    23,    24,    69,    35,
      20,    72,    29,     4,    34,    35,     4,    34,    20,    39,
      40,    41,    12,    11,    15,    12,    17,     0,    18,    18,
      19,    18,    20,     4,    42,    55,     4,    57,    64,     3,
      48,    18,     9,     8,    64,    65,    89,    89,    68,    69,
      89,    59,     7,     3,    33,    63,     6,     3,    28,     9,
      11,    11,    12,    13,    25,     3,    18,     3,    16,     3,
      20,    91,     3,     3,    19,    95,    18,   103,    18,    99,
       4,    31,    32,   103,    28,    26,    60,   107,   108,   109,
     116,    28,    61,    71,     4,    -1,   116,   105,   118,     3,
      62,    -1,     6,    -1,    -1,     9,   114,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    37,    38,    44,     0,     3,    21,    22,    23,
      24,    29,    34,    39,    40,    42,    43,    54,    55,    56,
      59,    39,    59,     4,    44,    45,    46,    47,    48,    49,
      50,    37,    46,     4,    28,    30,    41,    20,    44,    53,
      18,    19,    15,    17,    44,     3,    58,     6,     9,    11,
      13,    20,    31,    32,    43,    51,    52,    54,    55,    18,
       9,     8,     7,    25,    33,     3,    44,    37,    28,    11,
      44,    44,    44,    46,     3,    11,    17,    46,    45,    45,
      44,    46,    48,    49,    50,    46,    37,    44,    44,    44,
      45,    56,    45,    16,     3,    57,     3,    12,    14,    19,
      12,    12,    44,    12,    44,    44,    37,    18,    46,    28,
      44,    44,    44,     3,    18,    46,    26,    37,    28,    44
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    38,    38,    39,    39,    39,
      39,    39,    39,    39,    40,    41,    42,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    58,    58,    59,    59
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     1,     1,    14,
       4,     3,     4,     9,     4,     2,     4,     3,     0,     1,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     1,     1,     3,     1,     1,     1,     2,     3,     4,
       1,     4,     1,     1,     2,     5,     1,     3,     4,     1,
       5,     1,     3,     2,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NAME", "BLANK", "NL",
  "NUMERIC", "RAISE", "HIGH_OP", "LOW_OP", "LOGIC", "LEFT_PARA",
  "RIGHT_PARA", "LCURL", "RCURL", "LHARD", "RHARD", "DOT", "COMMA",
  "EQUALS", "STRING", "FUNCTION", "RETURN", "BREAK", "REPEAT", "UNTIL",
  "DO", "WHILE", "ENDD", "IF", "ELSE", "TRUE", "FALSE", "THEN", "FOR",
  "IN", "$accept", "block", "chunk", "stat", "if", "else", "assign",
  "functioncall", "optspace", "explist", "exp", "lowop", "highop",
  "raiseop", "spaceeater", "anything", "tableconstr", "args", "prefixexp",
  "varlist", "var", "namelist", "funcname", "laststat", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    75,    75,    79,    80,    84,    85,    87,    88,    89,
      96,    99,   100,   103,   110,   114,   118,   124,   129,   130,
     133,   134,   137,   139,   140,   145,   146,   152,   153,   158,
     161,   162,   163,   164,   165,   166,   167,   168,   171,   174,
     175,   176,   181,   182,   184,   185,   187,   188,   189,   193,
     194,   197,   198,   200,   201
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
#line 1352 "interpreter.tab.cc" // lalr1.cc:1167
#line 202 "interpreter.yy" // lalr1.cc:1168

