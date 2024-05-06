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

#ifndef YY_YY_MNT_C_USERS_KILLC_ONEDRIVE_DESKTOP_PG4_1_PG4_BUILD_PARSER_TAB_HH_INCLUDED
# define YY_YY_MNT_C_USERS_KILLC_ONEDRIVE_DESKTOP_PG4_1_PG4_BUILD_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/frontend/parser.y"

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
#include "../src/files/expressions/bool.h"
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
 

#line 83 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.hh"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NAME = 258,                    /* NAME  */
    NEWLINE = 259,                 /* NEWLINE  */
    INDENT = 260,                  /* INDENT  */
    DEDENT = 261,                  /* DEDENT  */
    COLON = 262,                   /* COLON  */
    PRINT = 263,                   /* PRINT  */
    FOR = 264,                     /* FOR  */
    ID = 265,                      /* ID  */
    BOOL_TYPE = 266,               /* BOOL_TYPE  */
    INT_TYPE = 267,                /* INT_TYPE  */
    FLOAT_TYPE = 268,              /* FLOAT_TYPE  */
    STRING_TYPE = 269,             /* STRING_TYPE  */
    VOID_TYPE = 270,               /* VOID_TYPE  */
    SEMICOLON = 271,               /* SEMICOLON  */
    LPAREN = 272,                  /* LPAREN  */
    RPAREN = 273,                  /* RPAREN  */
    COMMA = 274,                   /* COMMA  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    IF = 277,                      /* IF  */
    ELIF = 278,                    /* ELIF  */
    ASSIGNMENT = 279,              /* ASSIGNMENT  */
    TAB = 280,                     /* TAB  */
    ELSE = 281,                    /* ELSE  */
    WHILE = 282,                   /* WHILE  */
    BREAK = 283,                   /* BREAK  */
    RETURN = 284,                  /* RETURN  */
    EQUALS_SIGN = 285,             /* EQUALS_SIGN  */
    LOGICAL_OR = 286,              /* LOGICAL_OR  */
    LOGICAL_AND = 287,             /* LOGICAL_AND  */
    LOGICAL_NOT = 288,             /* LOGICAL_NOT  */
    RELOP_GT = 289,                /* RELOP_GT  */
    RELOP_LT = 290,                /* RELOP_LT  */
    RELOP_GE = 291,                /* RELOP_GE  */
    RELOP_LE = 292,                /* RELOP_LE  */
    RELOP_EQ = 293,                /* RELOP_EQ  */
    RELOP_NE = 294,                /* RELOP_NE  */
    ARITH_PLUS = 295,              /* ARITH_PLUS  */
    ARITH_MINUS = 296,             /* ARITH_MINUS  */
    ARITH_MULT = 297,              /* ARITH_MULT  */
    ARITH_DIV = 298,               /* ARITH_DIV  */
    ARITH_MOD = 299,               /* ARITH_MOD  */
    VARIADIC = 300,                /* VARIADIC  */
    BOOL_LITERAL = 301,            /* BOOL_LITERAL  */
    INT_LITERAL = 302,             /* INT_LITERAL  */
    FLOAT_LITERAL = 303,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 304,          /* STRING_LITERAL  */
    EOL = 305,                     /* EOL  */
    DEF = 306                      /* DEF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "src/files/frontend/parser.y"

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
  ASTStatementBlock *stmtBlock;

#line 168 "/Users/devsog12/Projects/CSDS337-Compiler-Design-Project/build/parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MNT_C_USERS_KILLC_ONEDRIVE_DESKTOP_PG4_1_PG4_BUILD_PARSER_TAB_HH_INCLUDED  */
