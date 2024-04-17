/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_USERS_DEVSOG12_PROJECTS_CSDS337_COMPILER_DESIGN_PROJECT_CMAKE_BUILD_DEBUG_PARSER_TAB_HH_INCLUDED
# define YY_YY_USERS_DEVSOG12_PROJECTS_CSDS337_COMPILER_DESIGN_PROJECT_CMAKE_BUILD_DEBUG_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/files/frontend/parser.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <vector>
  #include <string>
  #include <cstring>
  #include <variant>
  #include <iostream>
  #include "ast.h"
  #include "expressions/call.h"
  #include "expressions/int.h"
  #include "expressions/float.h"
  #include "expressions/string.h"
  #include "expressions/variable.h"
  #include "expressions/addition.h"
  #include "expressions/subtraction.h"
  #include "expressions/multiplication.h"
  #include "expressions/division.h"
  #include "expressions/assignment.h"
  #include "expressions/comparison.h"
  #include "expressions/and.h"
  #include "expressions/or.h"
  #include "statements/block.h"
  #include "statements/for.h"
  #include "statements/while.h"
  #include "statements/if.h"
  #include "statements/return.h"
  #include "types/simple.h"
  extern FILE *yyin;

#line 80 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/cmake-build-debug/parser.tab.hh"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    FLOAT = 261,                   /* FLOAT  */
    EQUALS = 262,                  /* EQUALS  */
    PLUS = 263,                    /* PLUS  */
    MINUS = 264,                   /* MINUS  */
    TIMES = 265,                   /* TIMES  */
    DIVIDEDBY = 266,               /* DIVIDEDBY  */
    EQ = 267,                      /* EQ  */
    NEQ = 268,                     /* NEQ  */
    GT = 269,                      /* GT  */
    GTE = 270,                     /* GTE  */
    LT = 271,                      /* LT  */
    LTE = 272,                     /* LTE  */
    RETURN = 273,                  /* RETURN  */
    INDENT = 274,                  /* INDENT  */
    DEDENT = 275,                  /* DEDENT  */
    NEWLINE = 276,                 /* NEWLINE  */
    IF = 277,                      /* IF  */
    COLON = 278,                   /* COLON  */
    AND = 279,                     /* AND  */
    BREAK = 280,                   /* BREAK  */
    DEF = 281,                     /* DEF  */
    ELIF = 282,                    /* ELIF  */
    ELSE = 283,                    /* ELSE  */
    FOR = 284,                     /* FOR  */
    NOT = 285,                     /* NOT  */
    OR = 286,                      /* OR  */
    WHILE = 287,                   /* WHILE  */
    SEMICOLON = 288,               /* SEMICOLON  */
    LPAREN = 289,                  /* LPAREN  */
    RPAREN = 290,                  /* RPAREN  */
    COMMA = 291                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "src/files/frontend/parser.y"

  float value;
  std::string* str;
  int token;

#line 139 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/cmake-build-debug/parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_USERS_DEVSOG12_PROJECTS_CSDS337_COMPILER_DESIGN_PROJECT_CMAKE_BUILD_DEBUG_PARSER_TAB_HH_INCLUDED  */
