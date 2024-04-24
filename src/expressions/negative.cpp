#include "negative.h"

std::unique_ptr<VarType> ASTExpressionNegation::ReturnType(ASTFunction& func)
{
    // Logic to determine return type based on operand.
    return a1->ReturnType(func);
}

bool ASTExpressionNegation::IsLValue(ASTFunction& func)
{
    return false; // Negative result is not an l-value.
}

llvm::Value* ASTExpressionNegation::Compile(llvm::IRBuilder<>& builder, ASTFunction& func)
{
    // Compile the operand and negate its value.
    llvm::Value* operandValue = a1->CompileRValue(builder, func);
    return builder.CreateNeg(operandValue);
}

std::string ASTExpressionNegation::ToString(const std::string& prefix)
{
    // Convert the expression to a string representation.
    return "(-)\n" + prefix + "└──" + a1->ToString(prefix + "   ");
}