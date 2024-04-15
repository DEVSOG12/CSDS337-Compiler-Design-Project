%{
#include "parser.tab.hh"
#include <sstream>

static std::stringstream ss;
%}

%option noyywrap

%x strlit

%{
#include <string.h>
%}

%%
"if"                        { return IF; }
"elif"                      { return ELIF; }
"else"                      { return ELSE; }
"while"                     { return WHILE; }
"or"                        { return LOGICAL_OR; }
"and"                       { return LOGICAL_AND; }
"not"                       { return LOGICAL_NOT; }
"=="                        { return RELOP_EQ; }
"!="                        { return RELOP_NE; }
"<"                         { return RELOP_LT; }
">"                         { return RELOP_GT; }
"<="                        { return RELOP_LE; }
">="                        { return RELOP_GE; }
"="                         { return EQUALS_SIGN; }
"+"                         { return ARITH_PLUS; }
"-"                         { return ARITH_MINUS; }
"*"                         { return ARITH_MULT; }
"/"                         { return ARITH_DIV; }
"%"                         { return ARITH_MOD; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
":"                         { return COLON; }
","                         { return COMMA; }
"="                         { return ASSIGNMENT; }
"\n"                        { return NEWLINE; }
"\\n"                       { return NEWLINE; }
"\\t"                       { return TAB; }
"[ \t]+"                    { /* Ignore whitespace */ }
"\"[^\"\\n]*"               { BEGIN strlit; ss.str(std::string()); }
<strlit>[^\\"\n]*           { ss << yytext; }
<strlit>\\n                 { ss << '\n'; }
<strlit>\\t                 { ss << '\t'; }
<strlit>\\[\\"]             { ss << yytext[1]; /*escaped quote or backslash*/ }
<strlit>\"                  { yylval.strval = strdup((char *) ss.str().c_str()); BEGIN 0; return STRING_LITERAL; }
<strlit>\\.                 { printf("Invalid escape character '%s'\n", yytext); }
<strlit>\n                  { printf("Found newline in string\n"); }
[_a-zA-Z][_a-zA-Z0-9]*     { yylval.strval = strdup(yytext); return NAME; }
[0-9]+                      { yylval.intval = atoi(yytext); return NUMBER; }
[0-9]+"."[0-9]+             { yylval.fltval = atof(yytext); return NUMBER; }
.                           { printf("Unrecognized character %c\n", *yytext); }

%%
