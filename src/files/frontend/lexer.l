%{
#include "parser.tab.hh"
#include <sstream>
#include <stack>
#include <string.h>


static std::stringstream ss;
static std::stack<int> indent_stack;

%}

%option noyywrap

%option yylineno
%x strlit




%%

%{
    // if stack is empty push 0
if (indent_stack.empty()) {
    indent_stack.push(0);
}
%}





\"                        { BEGIN strlit; ss.str(std::string()); }
<strlit>[^\"\n\\]+     { ss << yytext; }
<strlit>\\\n             { /* ignore backslash at end of line */ }
<strlit>\\\"           { ss << '\"'; }
<strlit>\"            { 

    printf("Found string literal: %s\n", ss.str().c_str()); 
    yylval.strval = strdup(ss.str().c_str());
    BEGIN 0;  
    return STRING_LITERAL;
 
  }



^[ \t]+                  {
                            if (indent_stack.top() < (int)yyleng) {
                                indent_stack.push(yyleng);
                                printf("Found pushing indent from 1\n");
                                printf("Indent size: %d\n", yyleng);
                                return INDENT;
                            } else {
                                while (!indent_stack.empty() && indent_stack.top() != (int)yyleng) {
                                    indent_stack.pop();
                                    printf("Found popping dedent from 1\n");
                                    return DEDENT;
                                }

                                if (indent_stack.empty()) {
                                std::cerr << "Error: Incorrect indentation on line "
                                    << yylineno << std::endl;
                                return 1;
                            
                            }
                          }

                    }   
^[^ \t\n]+     {
            while(indent_stack.top() != 0) {
            indent_stack.pop();
            printf("Found popping dedent from 2\n");
             /* std::cout << "DEDENT" << std::endl; */
            return DEDENT;
            }
              REJECT;

}

\r?\n {
    printf("Found newline --- \n");
    return NEWLINE;
}

<<EOF>> { 

    printf("Found popping dedent from 3\n");

    while (indent_stack.top() != 0) {
        indent_stack.pop();
        printf("Found popping dedent from 2\n");
        return DEDENT;
    }
    

    return 0;

}
 


"True"       { 
    // printf("Found boolean literal %s\n", yytext); 
    yylval.boolval = 1;
    return BOOL_LITERAL; }
"False"       { 
    // printf("Found boolean literal %s\n", yytext); 
    yylval.boolval = 0;
    return BOOL_LITERAL; }
"print"                     { return PRINT; }
"def"                       { return DEF; }
"else"                      { 
    printf("Found else\n");
    return ELSE; }
"if"                        { return IF; }
"elif"                      { return ELIF; }

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
"\\t"                       { return TAB; }
[ \t]+                      { /* ignore whitespace */ }
[a-zA-Z_][a-zA-Z0-9_]*    {
    printf("Found identifier %s\n", yytext);
     yylval.strval = strdup(yytext); return ID;
      }
[0-9]+                      { yylval.intval = atoi(yytext); return INT_LITERAL; }
[0-9]+"."[0-9]+             { yylval.fltval = atof(yytext); return FLOAT_LITERAL; }
.                           { printf("Unrecognized character %c\n", *yytext); }

%%