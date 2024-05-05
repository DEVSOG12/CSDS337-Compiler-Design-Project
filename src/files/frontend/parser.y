 %code requires {

#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <variant>
#include <iostream>
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

}

extern FILE *yyin;

%{
#include "parser.tab.hh"

extern int yylex(void);
void yyerror(const char *s);
void save_to_dot(FILE *);
int trav_and_write(FILE *, node *);

std::vector<std::string> varNames;
bool isPrint = false;

AST ast("TestMod");

auto main_func = ast.AddFunction("main", std::make_unique<VarTypeSimple>(VarTypeSimple::VoidType), ASTFunctionParameters());

// hard define print function
%}

%start program

%define parse.error verbose

%union {
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
}

%token NAME NEWLINE INDENT DEDENT COLON PRINT FOR ID BOOL_TYPE INT_TYPE FLOAT_TYPE STRING_TYPE VOID_TYPE SEMICOLON LPAREN RPAREN COMMA LBRACE RBRACE IF ELIF ASSIGNMENT TAB ELSE WHILE BREAK RETURN EQUALS_SIGN LOGICAL_OR LOGICAL_AND LOGICAL_NOT RELOP_GT RELOP_LT RELOP_GE RELOP_LE RELOP_EQ RELOP_NE ARITH_PLUS ARITH_MINUS ARITH_MULT ARITH_DIV ARITH_MOD VARIADIC BOOL_LITERAL INT_LITERAL FLOAT_LITERAL STRING_LITERAL EOL DEF

%type <boolval> BOOL_LITERAL
%type <strval> ID STRING_LITERAL
%type <intval> int_lit INT_LITERAL
%type <fltval> flt_lit FLOAT_LITERAL
%type <stmtBlock> maybeElse
%type <stmt> stmt exprStmt selStmt iterStmt
%type <stmtVec> stmts program
%type <exp> expr orExpr andExpr unaryRelExpr relExpr term factor primary constant
%type <rel> relop

%expect 0 // Shift/reduce conflict when resolving the if/else production; okay

%%

program: stmts {
  auto stmtBlock = std::make_unique<ASTStatementBlock>();
  for (auto s : *$1) {
    stmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));
  }

  $$ = $1;
  main_func->Define(std::move(stmtBlock));
} | dec;

dec: funDef;

funDef: DEF ID LPAREN RPAREN COLON NEWLINE INDENT expr DEDENT {
  printf("Function definition\n");
  printf("Function name: %s\n", $2);
}

stmts: stmts stmt {
  printf("Found Statement\n");
  $$ = $1;
  $$->push_back($2);
} | {
  printf("No statements\n");
  $$ = new std::vector<ASTStatement *>();
};

stmt: exprStmt { $$ = $1; }  |  selStmt {$$ = $1;} | iterStmt {$$ = $1;};

exprStmt: expr NEWLINE { $$ = $1; } | NEWLINE { $$ = new ASTStatementBlock(); };

selStmt: IF expr COLON NEWLINE INDENT stmts DEDENT maybeElse {
  printf("If statement\n");
  printf("Expression: %s\n", $2->ToString("").c_str());
  auto stmtBlock = std::make_unique<ASTStatementBlock>();
  for (auto s : *$6) {
    stmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));
  }

  $$ = new ASTStatementIf(std::unique_ptr<ASTExpression>($2), std::move(stmtBlock), std::unique_ptr<ASTStatementBlock>(nullptr));
};

maybeElse: ELSE COLON NEWLINE INDENT stmts DEDENT { 
  printf("Else statement\n");
  $$ = new ASTStatementBlock();
} | { 
  printf("No else statement\n");
  $$ = new ASTStatementBlock();
}

iterStmt: WHILE expr COLON NEWLINE INDENT stmts DEDENT {
  auto stmtBlock = std::make_unique<ASTStatementBlock>();
  for (auto s : *$6) {
    stmtBlock->statements.push_back(std::unique_ptr<ASTStatement>(s));
  }
  $$ = new ASTStatementWhile(std::unique_ptr<ASTExpression>($2), std::move(stmtBlock));
};

expr: orExpr {$$ = $1;} | expr EQUALS_SIGN orExpr {
  printf("Assignment\n");
  std::string value = $3->ToString("");
  std::string varName = $1->ToString("");

  varName.erase(std::remove(varName.begin(), varName.end(), ' '), varName.end());
  value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
  varName.erase(std::remove(varName.begin(), varName.end(), '\t'), varName.end());
  value.erase(std::remove(value.begin(), value.end(), '\t'), value.end());
  varName.erase(std::remove(varName.begin(), varName.end(), '\n'), varName.end());
  value.erase(std::remove(value.begin(), value.end(), '\n'), value.end());
  varName.erase(std::remove(varName.begin(), varName.end(), '\r'), varName.end());

  printf("Value: %s\n", value.c_str());

  if (std::find(varNames.begin(), varNames.end(), varName) == varNames.end()) {
    auto r = $3->ReturnType(*main_func);
    if (r->Equals(&VarTypeSimple::IntType)) {
      main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::IntType.Copy(), varName));
    } else if (r->Equals(&VarTypeSimple::FloatType)) {
      main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::FloatType.Copy(), varName));
    } else if (r->Equals(&VarTypeSimple::StringType)) {
      main_func->AddStackVar(ASTFunction

Parameter(VarTypeSimple::StringType.Copy(), varName));
    } else if (r->Equals(&VarTypeSimple::BoolType)) {
      main_func->AddStackVar(ASTFunctionParameter(VarTypeSimple::BoolType.Copy(), varName));
    }
  }  
  varNames.push_back(varName);
  $$ = new ASTExpressionAssignment(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
}  | PRINT LPAREN expr RPAREN {
  printf("Print statement\n");
  std::string value = $3->ToString("");
  printf("Value: %s\n", value.c_str());

  if (!isPrint) {
    auto parameters = ASTFunctionParameters();
    parameters.push_back(ASTFunctionParameter(VarTypeSimple::StringType.Copy(), "str"));
    ast.AddFunction("printf", VarTypeSimple::IntType.Copy(), std::move(parameters), true);
    isPrint = true;
  }

  auto argVec = std::vector<std::unique_ptr<ASTExpression>>();
  if ($3->ReturnType(*main_func)->Equals(&VarTypeSimple::IntType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%d\n")));
  } else if ($3->ReturnType(*main_func)->Equals(&VarTypeSimple::FloatType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%f\n")));
  } else if ($3->ReturnType(*main_func)->Equals(&VarTypeSimple::StringType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%s\n")));
  } else if ($3->ReturnType(*main_func)->Equals(&VarTypeSimple::BoolType)) {
    argVec.push_back(std::unique_ptr<ASTExpression>(new ASTExpressionString("%d\n")));
  }

  argVec.push_back(std::unique_ptr<ASTExpression>($3));

  $$ = new ASTExpressionCall(ASTExpressionVariable::Create("printf"), std::move(argVec));
}

orExpr: andExpr {$$ = $1;} | orExpr LOGICAL_OR andExpr {
  $$ = new ASTExpressionOr(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
};
andExpr: unaryRelExpr {$$ = $1;} | andExpr LOGICAL_AND unaryRelExpr {
  $$ = new ASTExpressionAnd(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
};
unaryRelExpr: LOGICAL_NOT unaryRelExpr {
  $$ = $2;
} | relExpr {$$ = $1;};
relExpr: term relop term {
  $$ = new ASTExpressionComparison($2, std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
} | term {$$ = $1;};
relop: RELOP_GT {
  $$ = ASTExpressionComparisonType::GreaterThan;
} | RELOP_LT {
  $$ = ASTExpressionComparisonType::LessThan;
} | RELOP_GE {
  $$ = ASTExpressionComparisonType::GreaterThanOrEqual;
} | RELOP_LE {
  $$ = ASTExpressionComparisonType::LessThanOrEqual;
} | RELOP_EQ {
  $$ = ASTExpressionComparisonType::Equal;
} | RELOP_NE {
  $$ = ASTExpressionComparisonType::NotEqual;
};
term: factor {$$ = $1;}| term ARITH_PLUS factor {
  $$ = new ASTExpressionAddition(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
} | term ARITH_MINUS factor {
  $$ = new ASTExpressionSubtraction(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
};
factor: primary {$$ = $1;} | factor ARITH_MULT primary {
  $$ = new ASTExpressionMultiplication(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
} | factor ARITH_DIV primary {
  $$ = new ASTExpressionDivision(std::unique_ptr<ASTExpression>($1), std::unique_ptr<ASTExpression>($3));
} | factor ARITH_MOD primary {
  $$ = $1;
};
primary: ID {
  $$ = new ASTExpressionVariable($1);
} | LPAREN expr RPAREN {
  $$ = $2;
} | constant {
  $$ = $1;
};

constant: int_lit { $$ = new ASTExpressionInt($1); } | flt_lit {$$ = new ASTExpressionFloat($1);} | 
STRING_LITERAL {  $$ = new ASTExpressionString($1); } |
BOOL_LITERAL {
    printf("Bool Literal\n");
   $$ = new ASTExpressionBool($1);
   };
int_lit: INT_LITERAL | ARITH_MINUS INT_LITERAL {$$ = -1 * $2;};
flt_lit: FLOAT_LITERAL | ARITH_MINUS FLOAT_LITERAL {$$ = -1 * $2;};

%%

int main(int argc, char **argv) {
  // Arg flags:
  bool showHelp = false; // Show the help and exit.
  std::string openFile = ""; // File to open. Nothing for standard in.
  std::string outFile = ""; // File to write to. Nothing for standard out.
  int outputFormat = 3; // 0 - LLVM Assembly. 1 - LLVM Bitcode. 2 - Object (TODO). 3 - AST tree.
  bool printAST = true; // If to print the AST to console.

  // Read the arguments. Don't count the first which is the executable name.
  for (int i = 1; i < argc; i++) {
    bool hasNextArg = i + 1 < argc;
    std::string arg(argv[i]);
    if (arg == "-i" && hasNextArg) {
      i++;
      openFile = argv[i];
    } else if (arg == "-o" && hasNextArg) {
      i++;
      outFile = argv[i];
    } else if (arg == "-nPrint") {
      printAST = false;
    } else if (arg == "-fAsm") {
      outputFormat = 0;
    } else if (arg == "-fBc") {
      outputFormat = 1;
    } else if (arg == "-fObj") {
      outputFormat = 2;
    } else if (arg == "-fAst") {
      outputFormat = 3;
    } else {
      showHelp = true;
    }
  }
  printAST &= outputFormat != 3 && outFile != ""; // Always print AST by default in addition to whatever is being output.

  // Show help if needed.
  if (showHelp) {
    printf("Usage: LLVM-Lab [options]\n");
    printf("\nOptions:\n\n");
    printf("-h              Show this help screen.\n");
    printf("-i [input]      Read from an input file (reads from console by default).\n");
    printf("-o [output]     Write to an output file (writes to console by default).\n");
    printf("-nPrint         If to not print the AST to the console.\n");
    printf("-fAsm           Output format is in LLVM assembly.\n");
    printf("-fAst           Output

 format is an abstract syntax tree.\n");
    printf("-fBc            Output format is in LLVM bitcode.\n");
    printf("-fObj           Output format is an object file.\n");
    return 1;
  }

  // Fetch input.
  if (openFile != "") {
    yyin = fopen(openFile.c_str(), "r");
  }

  if (yyparse() == 1) {
    printf("Irrecoverable error state, aborting\n");
    return 1;
  }

  // Close input if needed.
  if (openFile != "") {
    fclose(yyin);
  }

  // Do the compilation.
  ast.Compile();

  // Print AST if needed.
  if (printAST) std::cout << ast.ToString() << std::endl;

  // Export data.
  if (outputFormat == 0) {
    ast.WriteLLVMAssemblyToFile(outFile);
  } else if (outputFormat == 1) {
    ast.WriteLLVMBitcodeToFile(outFile);
  } else if (outputFormat == 2) {
    std::cout << "OBJ exporting not supported yet." << std::endl;
  } else {
    std::cout << ast.ToString() << std::endl;
  }
  return 0;
}

void yyerror(const char *s) {
  fprintf(stderr, "error: %s\n", s);
}
