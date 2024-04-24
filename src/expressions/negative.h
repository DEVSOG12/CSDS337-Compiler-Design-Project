#pragma once

#include "../expression.h"

// An expression that adds two operands together.
class ASTExpressionNegation : public ASTExpression
{
    std::unique_ptr<ASTExpression> a1;

    VarTypeSimple* returnType = nullptr;

public:

    ASTExpressionNegation(std::unique_ptr<ASTExpression> a1) : a1(std::move(a1)) {}

    // Create a new addition expression.
    // a1: Left side expression of the addition statement.
    // a2: Right side expression of the addition statement.
    static auto Create(std::unique_ptr<ASTExpression> a1)
    {
        return std::make_unique<ASTExpressionNegation>(std::move(a1));
    }

    // Virtual functions. See base class for details.
    std::unique_ptr<VarType> ReturnType(ASTFunction& func) override;
    bool IsLValue(ASTFunction& func) override;
    llvm::Value* Compile(llvm::IRBuilder<>& builder, ASTFunction& func) override;
    std::string ToString(const std::string& prefix) override;
};