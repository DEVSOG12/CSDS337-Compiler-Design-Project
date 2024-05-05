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
  //all of these includes are done as relative paths starting from the build/ directory, since that's where CMake places parser.tab.cc
#include "../src/files/ast.h"
#include "../src/files/expressions/call.h"
#include "../src/files/expressions/int.h"
#include "../src/files/expressions/float.h"
#include "../src/files/expressions/string.h"
#include "../src/files/expressions/variable.h"
#include "../src/files/expressions/addition.h"
#include "../src/files/expressions/subtraction.h"
#include "../src/files/expressions/multiplication.h"
#include "../src/files/expressions/division.h"
#include "../src/files/expressions/assignment.h"
#include "../src/files/expressions/comparison.h"
#include "../src/files/expressions/and.h"
#include "../src/files/expressions/or.h"
#include "../src/files/statements/block.h"
#include "../src/files/statements/while.h"
#include "../src/files/statements/for.h"
#include "../src/files/statements/if.h"
#include "../src/files/statements/return.h"
#include "../src/files/types/simple.h"
extern FILE *yyin;
 

#line 82 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/cmake-build-debug/parser.tab.hh"

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
    FLOAT = 259,                   /* FLOAT  */
    INTEGER = 260,                 /* INTEGER  */
    BOOLEAN = 261,                 /* BOOLEAN  */
    INDENT = 262,                  /* INDENT  */
    DEDENT = 263,                  /* DEDENT  */
    NEWLINE = 264,                 /* NEWLINE  */
    AND = 265,                     /* AND  */
    BREAK = 266,                   /* BREAK  */
    DEF = 267,                     /* DEF  */
    ELIF = 268,                    /* ELIF  */
    ELSE = 269,                    /* ELSE  */
    FOR = 270,                     /* FOR  */
    IF = 271,                      /* IF  */
    NOT = 272,                     /* NOT  */
    OR = 273,                      /* OR  */
    RETURN = 274,                  /* RETURN  */
    WHILE = 275,                   /* WHILE  */
    ASSIGN = 276,                  /* ASSIGN  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    TIMES = 279,                   /* TIMES  */
    DIVIDEDBY = 280,               /* DIVIDEDBY  */
    EQ = 281,                      /* EQ  */
    NEQ = 282,                     /* NEQ  */
    GT = 283,                      /* GT  */
    GTE = 284,                     /* GTE  */
    LT = 285,                      /* LT  */
    LTE = 286,                     /* LTE  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    COMMA = 289,                   /* COMMA  */
    COLON = 290                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "src/files/frontend/parser.y"

  bool boolval;
  int intval;
  double fltval;
  char *strval;
  struct node *nodeval;
  ASTFunctionParameter *var;
  std::vector<ASTFunctionParameter *> *vars;
  ASTStatement *stmt;
  std::vector<ASTStatement *> *stmtVec;
  ASTExpression *exp;
  std::vector<ASTExpression *> *exprVec;
  VarType *type;
  ASTExpressionComparisonType rel;

#line 150 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/cmake-build-debug/parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;


int yypush_parse (yypstate *ps,
                  int pushed_char, YYSTYPE const *pushed_val);

yypstate *yypstate_new (void);
void yypstate_delete (yypstate *ps);


#endif /* !YY_YY_USERS_DEVSOG12_PROJECTS_CSDS337_COMPILER_DESIGN_PROJECT_CMAKE_BUILD_DEBUG_PARSER_TAB_HH_INCLUDED  */
