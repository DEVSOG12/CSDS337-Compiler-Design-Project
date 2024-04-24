#pragma once

#include "../expression.h"
#include "../statement.h"

class ASTStatementFor : public ASTStatement
{
private:
    std::unique_ptr<ASTStatement> body;
    std::unique_ptr<ASTExpression> init;
    std::unique_ptr<ASTExpression> condition;
    std::unique_ptr<ASTExpression> increment;

public:
    ASTStatementFor(std::unique_ptr<ASTStatement> body,
                    std::unique_ptr<ASTExpression> init = nullptr,
                    std::unique_ptr<ASTExpression> condition = nullptr,
                    std::unique_ptr<ASTExpression> increment = nullptr)
        : body(std::move(body)), init(std::move(init)),
          condition(std::move(condition)), increment(std::move(increment)) {}

    static std::unique_ptr<ASTStatementFor> Create(std::unique_ptr<ASTStatement> body,
                                                   std::unique_ptr<ASTExpression> init = nullptr,
                                                   std::unique_ptr<ASTExpression> condition = nullptr,
                                                   std::unique_ptr<ASTExpression> increment = nullptr)
    {
        return std::make_unique<ASTStatementFor>(std::move(body), std::move(init), std::move(condition), std::move(increment));
    }

    // Virtual functions. See base class for details.
    virtual std::unique_ptr<VarType> StatementReturnType(ASTFunction& func) override;
    virtual void Compile(llvm::Module& mod, llvm::IRBuilder<>& builder, ASTFunction& func) override;
    virtual std::string ToString(const std::string& prefix) override;
};
