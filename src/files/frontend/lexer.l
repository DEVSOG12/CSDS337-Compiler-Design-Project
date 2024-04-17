

%{
#include <iostream>
#include <stack>
#include <cstdlib>

#include "parser.tab.hh"

std::stack<int> _indent_stack;
%}

%option noyywrap
%option yylineno

%%

%{
  /*
   * We only want to initialize the indentation level stack once by pushing a 0 onto it    */
  if (_indent_stack.empty()) {
    _indent_stack.push(0);
  }

  /*
   * We also want to initialize a parser state to be sent to the parser on
   * each push parse call.
   */
  yypstate* pstate = yypstate_new();

  YYSTYPE yylval;
  YYLTYPE loc;

  #define PUSH_TOKEN(token, text) do {                         \
    yylval.str = text ? new std::string(text) : NULL;              \
    loc.first_line = loc.last_line = yylineno;                 \
    int status = yypush_parse(pstate, token, &yylval, &loc);   \
    if (status != YYPUSH_MORE) {                               \
      yypstate_delete(pstate);                                 \
      return status;                                           \
    }                                                          \
  } while (0)
%}

^[ \t]*\r?\n   { /* Skip blank lines */ }

^[ \t]*#.*\r?\n    { /* Skip whole-line comments. */ }

#.*$        { /* Skip comments on the same line as a statement. */ }

^[ \t]+     {
              /*  Handle indentation  */
              if (_indent_stack.top() < (int)yyleng) {
                               
                _indent_stack.push(yyleng);
                /* std::cout << "INDENT" << std::endl; */
                PUSH_TOKEN(INDENT, NULL);
              } else {
                
                while (!_indent_stack.empty() && _indent_stack.top() != (int)yyleng) {
                  _indent_stack.pop();
                  /* std::cout << "DEDENT" << std::endl; */
                  PUSH_TOKEN(DEDENT, NULL);
                }

                
                if (_indent_stack.empty()) {
                  std::cerr << "Error: Incorrect indentation on line "
                    << yylineno << std::endl;
                  return 1;
                }
              }
            }

^[^ \t\n]+  {
              
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                /* std::cout << "DEDENT" << std::endl; */
                PUSH_TOKEN(DEDENT, NULL);
              }
              REJECT;
            }

\r?\n       {
              /* std::cout << "NEWLINE" << std::endl; */
              PUSH_TOKEN(NEWLINE, NULL);
            }

<<EOF>>     {
             
              while(_indent_stack.top() != 0) {
                _indent_stack.pop();
                PUSH_TOKEN(DEDENT, "");
              }
              int status = yypush_parse(pstate, 0, NULL, NULL);
              yypstate_delete(pstate);
              return status;
            }

[ \t]       { /* Ignore spaces that haven't been handled above. */ }

"and"       { PUSH_TOKEN(AND, NULL); }
"break"     { PUSH_TOKEN(BREAK, NULL); }
"def"       { PUSH_TOKEN(DEF, NULL); }
"elif"      { PUSH_TOKEN(ELIF, NULL); }
"else"      { PUSH_TOKEN(ELSE, NULL); }
"for"       { PUSH_TOKEN(FOR, NULL); }
"if"        { PUSH_TOKEN(IF, NULL); }
"not"       { PUSH_TOKEN(NOT, NULL); }
"or"        { PUSH_TOKEN(OR, NULL); }
"return"    { PUSH_TOKEN(RETURN, NULL); }
"while"     { PUSH_TOKEN(WHILE, NULL); }

"True"      { PUSH_TOKEN(BOOLEAN, yytext); }
"False"     { PUSH_TOKEN(BOOLEAN, yytext); }

[a-zA-Z_][a-zA-Z0-9_]*  { PUSH_TOKEN(IDENTIFIER, yytext); }

-?[0-9]*"."[0-9]+       { PUSH_TOKEN(FLOAT, yytext); }

-?[0-9]+    { PUSH_TOKEN(INTEGER, yytext); }

"="         { PUSH_TOKEN(ASSIGN, NULL); }
"+"         { PUSH_TOKEN(PLUS, NULL); }
"-"         { PUSH_TOKEN(MINUS, NULL); }
"*"         { PUSH_TOKEN(TIMES, NULL); }
"/"         { PUSH_TOKEN(DIVIDEDBY, NULL); }

"=="        { PUSH_TOKEN(EQ, NULL); }
"!="        { PUSH_TOKEN(NEQ, NULL); }
">"         { PUSH_TOKEN(GT, NULL); }
">="        { PUSH_TOKEN(GTE, NULL); }
"<"         { PUSH_TOKEN(LT, NULL); }
"<="        { PUSH_TOKEN(LTE, NULL); }

"("         { PUSH_TOKEN(LPAREN, NULL); }
")"         { PUSH_TOKEN(RPAREN, NULL); }

","         { PUSH_TOKEN(COMMA, NULL); }
":"         { PUSH_TOKEN(COLON, NULL); }

.           {
              std::cerr << "Unrecognized token on line " << yylineno << ": "
                << yytext << std::endl;
              PUSH_TOKEN(yytext[0], NULL);
            }

%%