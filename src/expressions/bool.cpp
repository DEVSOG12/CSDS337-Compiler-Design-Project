#include "bool.h"

std::unique_ptr<VarType> ASTExpressionBool::ReturnType(ASTFunction& func)
{
    // Return type is boolean.
    return VarTypeSimple::BoolType.Copy();
}

bool ASTExpressionBool::IsLValue(ASTFunction& func)
{
    return false; // Constant boolean expression is not an l-value.
}

llvm::Value* ASTExpressionBool::Compile(llvm::IRBuilder<>& builder, ASTFunction& func)
{
    return llvm::ConstantInt::get(llvm::Type::getInt1Ty(builder.getContext()), value);
}

std::string ASTExpressionBool::ToString(const std::string& prefix)
{
    return value ? "true" : "false";
}

bool ASTExpressionBool::GetValue()
{
    return value;
}