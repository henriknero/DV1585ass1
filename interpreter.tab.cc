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
      case 23: // block
      case 24: // chunk
      case 25: // stat
      case 26: // assign
      case 27: // functioncall
      case 28: // optspace
      case 29: // explist
      case 30: // exp
      case 31: // lowop
      case 32: // highop
      case 33: // raiseop
      case 34: // anything
      case 35: // prefixexp
      case 36: // args
      case 37: // var
        value.move< Node > (that.value);
        break;

      case 3: // NAME
      case 4: // BLANK
      case 5: // NL
      case 6: // NUMERIC
      case 7: // RAISE
      case 8: // HIGH_OP
      case 9: // LOW_OP
      case 10: // LEFT_PARA
      case 11: // RIGHT_PARA
      case 12: // COMMA
      case 13: // EQUALS
      case 14: // STRING
      case 15: // RETURN
      case 16: // BREAK
      case 17: // DO
      case 18: // WHILE
      case 19: // ENDD
      case 20: // IF
      case 21: // THEN
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
      case 23: // block
      case 24: // chunk
      case 25: // stat
      case 26: // assign
      case 27: // functioncall
      case 28: // optspace
      case 29: // explist
      case 30: // exp
      case 31: // lowop
      case 32: // highop
      case 33: // raiseop
      case 34: // anything
      case 35: // prefixexp
      case 36: // args
      case 37: // var
        value.copy< Node > (that.value);
        break;

      case 3: // NAME
      case 4: // BLANK
      case 5: // NL
      case 6: // NUMERIC
      case 7: // RAISE
      case 8: // HIGH_OP
      case 9: // LOW_OP
      case 10: // LEFT_PARA
      case 11: // RIGHT_PARA
      case 12: // COMMA
      case 13: // EQUALS
      case 14: // STRING
      case 15: // RETURN
      case 16: // BREAK
      case 17: // DO
      case 18: // WHILE
      case 19: // ENDD
      case 20: // IF
      case 21: // THEN
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
      case 23: // block
      case 24: // chunk
      case 25: // stat
      case 26: // assign
      case 27: // functioncall
      case 28: // optspace
      case 29: // explist
      case 30: // exp
      case 31: // lowop
      case 32: // highop
      case 33: // raiseop
      case 34: // anything
      case 35: // prefixexp
      case 36: // args
      case 37: // var
        yylhs.value.build< Node > ();
        break;

      case 3: // NAME
      case 4: // BLANK
      case 5: // NL
      case 6: // NUMERIC
      case 7: // RAISE
      case 8: // HIGH_OP
      case 9: // LOW_OP
      case 10: // LEFT_PARA
      case 11: // RIGHT_PARA
      case 12: // COMMA
      case 13: // EQUALS
      case 14: // STRING
      case 15: // RETURN
      case 16: // BREAK
      case 17: // DO
      case 18: // WHILE
      case 19: // ENDD
      case 20: // IF
      case 21: // THEN
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
#line 53 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
                        root = yylhs.value.as< Node > ();
                        }
#line 574 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 57 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("chunk","",id++);yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 580 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 58 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
                                root = yylhs.value.as< Node > ();
                                }
#line 589 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 63 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 595 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 66 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 601 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 67 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("assign","",id++); 
											  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
											  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 609 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 71 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("funccall","",id++); 
												std::cout << "funccall build" << std::endl;
												yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
												yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());}
#line 618 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 77 "interpreter.yy" // lalr1.cc:859
    {std::cout << "optspace is called but empty"<< std::endl;}
#line 624 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 78 "interpreter.yy" // lalr1.cc:859
    {std::cout << "optspace is called not empty"<< std::endl;}
#line 630 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 81 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("explist","",id++);yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 636 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 82 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[4].value.as< Node > ();
													yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 643 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 85 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("String",yystack_[0].value.as< std::string > (),id++);}
#line 649 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 86 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();}
#line 655 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 87 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 661 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 89 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 667 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 90 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[2].value.as< std::string > (),id++);
													yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
													yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
													}
#line 676 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 95 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 682 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 96 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[2].value.as< std::string > (),id++);
									yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
									yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
									}
#line 691 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 102 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 697 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 103 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("OP",yystack_[2].value.as< std::string > (),id++); 
									yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ()); 
									yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 705 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 108 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("Number",yystack_[1].value.as< std::string > (),id++);}
#line 711 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 109 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();}
#line 717 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 113 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();std::cout << "var added to prefix: " << std::endl;}
#line 723 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 114 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 729 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 115 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();}
#line 735 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 117 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("emptypara","",id++);}
#line 741 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 118 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("String", yystack_[1].value.as< std::string > (),id++);}
#line 747 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 120 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("args","",id++); 
														yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());}
#line 754 "interpreter.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 124 "interpreter.yy" // lalr1.cc:859
    {yylhs.value.as< Node > () = Node("var",yystack_[0].value.as< std::string > (),id++);std::cout << "var created" << yystack_[0].value.as< std::string > () << std::endl;}
#line 760 "interpreter.tab.cc" // lalr1.cc:859
    break;


#line 764 "interpreter.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -11;

  const signed char parser::yytable_ninf_ = -26;

  const signed char
  parser::yypact_[] =
  {
      -1,   -11,    26,    35,    -1,   -11,   -11,     1,     0,   -11,
     -11,    36,   -11,   -11,    27,    26,    38,    26,    26,   -11,
     -11,    -1,    26,     8,    28,     4,   -11,     0,   -11,    23,
      26,   -11,   -11,     0,    37,    49,    51,    55,   -11,   -11,
      26,   -11,    36,   -11,   -11,    26,    26,    26,     7,    26,
      50,    50,    50,   -11,    26,    52,    28,     4,   -11,    36,
     -11
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    30,     9,     0,     2,     3,     5,     6,     9,    24,
      10,     0,     1,     4,    10,     9,     0,     9,     9,    13,
      25,     0,     9,    15,    16,    18,    20,     9,    28,     0,
       9,     8,    22,     9,     0,     0,     0,     0,    23,    27,
       9,    11,     0,    14,    26,     9,     9,     9,     0,     9,
       0,     0,     0,    29,     9,     7,    17,    19,    21,     0,
      12
  };

  const signed char
  parser::yypgoto_[] =
  {
     -11,   -11,   -11,    59,   -11,    57,    -2,    24,   -10,   -11,
      15,    16,    17,     3,   -11,   -11
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,     6,    20,    21,    40,    41,    23,
      24,    25,    26,    27,    17,     9
  };

  const signed char
  parser::yytable_[] =
  {
      11,    22,     1,     8,    14,   -25,    16,     8,    10,     2,
      15,    -9,    10,    29,   -25,    31,    32,    -9,    53,    54,
      34,    35,    36,    37,    33,    38,     1,    10,    42,    18,
      10,    43,    10,     2,    39,    12,    -9,    19,    48,     1,
      10,    28,    18,    50,    51,    52,     2,    55,    44,    60,
      19,    30,    59,     1,    36,    37,    18,     7,    45,    46,
       2,     7,    47,    13,    54,    56,    49,    57,     0,    58
  };

  const signed char
  parser::yycheck_[] =
  {
       2,    11,     3,     0,     4,     4,     8,     4,     4,    10,
      10,     7,     4,    15,    13,    17,    18,     9,    11,    12,
      22,    23,    24,    25,    21,    27,     3,     4,    30,     6,
       4,    33,     4,    10,    11,     0,     8,    14,    40,     3,
       4,    14,     6,    45,    46,    47,    10,    49,    11,    59,
      14,    13,    54,     3,    56,    57,     6,     0,     9,     8,
      10,     4,     7,     4,    12,    50,    42,    51,    -1,    52
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    10,    23,    24,    25,    26,    27,    35,    37,
       4,    28,     0,    25,     4,    10,    28,    36,     6,    14,
      27,    28,    30,    31,    32,    33,    34,    35,    14,    28,
      13,    28,    28,    35,    28,    28,    28,    28,    28,    11,
      29,    30,    28,    28,    11,     9,     8,     7,    28,    29,
      28,    28,    28,    11,    12,    28,    32,    33,    34,    28,
      30
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    22,    23,    24,    24,    25,    26,    26,    27,    28,
      28,    29,    29,    30,    30,    30,    31,    31,    32,    32,
      33,    33,    34,    34,    35,    35,    35,    36,    36,    36,
      37
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     6,     3,     0,
       1,     1,     5,     1,     3,     1,     1,     5,     1,     5,
       1,     5,     2,     2,     1,     1,     5,     3,     2,     5,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NAME", "BLANK", "NL",
  "NUMERIC", "RAISE", "HIGH_OP", "LOW_OP", "LEFT_PARA", "RIGHT_PARA",
  "COMMA", "EQUALS", "STRING", "RETURN", "BREAK", "DO", "WHILE", "ENDD",
  "IF", "THEN", "$accept", "block", "chunk", "stat", "assign",
  "functioncall", "optspace", "explist", "exp", "lowop", "highop",
  "raiseop", "anything", "prefixexp", "args", "var", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    53,    53,    57,    58,    63,    66,    67,    71,    77,
      78,    81,    82,    85,    86,    87,    89,    90,    95,    96,
     102,   103,   108,   109,   113,   114,   115,   117,   118,   119,
     124
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
#line 1078 "interpreter.tab.cc" // lalr1.cc:1167
#line 126 "interpreter.yy" // lalr1.cc:1168

