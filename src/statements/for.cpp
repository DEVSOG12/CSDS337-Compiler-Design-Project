#include "for.h"

#include "../function.h"


std::unique_ptr<VarType> ASTStatementFor::StatementReturnType(ASTFunction& func)
{
    // The return type of a for loop statement is not defined in this example.
    return nullptr;
}

void ASTStatementFor::Compile(llvm::Module& mod, llvm::IRBuilder<>& builder, ASTFunction& func)
{
    // Create basic blocks for the for loop.
    auto* funcVal = (llvm::Function*)func.GetVariableValue(func.name);
    // auto forLoop = llvm::BasicBlock::Create(builder.getContext(), "forLoop", funcVal);
    auto forInit = llvm::BasicBlock::Create(builder.getContext(), "forInit", funcVal);
    auto forCond = llvm::BasicBlock::Create(builder.getContext(), "forCond", funcVal);
    auto forBody = llvm::BasicBlock::Create(builder.getContext(), "forBody", funcVal);
    auto forEnd = llvm::BasicBlock::Create(builder.getContext(), "forEnd", funcVal);


    // Compile the initialization expression and jump to the condition block.
    builder.CreateBr(forInit);
    builder.SetInsertPoint(forInit);
    if (init)
        init->Compile(mod, builder, func);
    builder.CreateBr(forCond);

    // Compile the condition expression and jump to the body block.
    builder.SetInsertPoint(forCond);
    auto conditionVal = condition->CompileRValue(builder, func);
    builder.CreateCondBr(conditionVal, forBody, forEnd);

    // Compile the body statement and jump back to the condition block.
    builder.SetInsertPoint(forBody);
    if (!body) {
        builder.CreateBr(forEnd);
    }
    body->Compile(mod, builder, func);
    increment->Compile(mod, builder, func);
    builder.CreateBr(forCond);
    

    // Set insert point to the end block.
    builder.SetInsertPoint(forEnd);
}

std::string ASTStatementFor::ToString(const std::string& prefix)
{
    std::string output = "for\n";
    if (init)
        output += prefix + "├──" + init->ToString(prefix + "│  ");
    else
        output += prefix + "├──(no init)\n";
    if (condition)
        output += prefix + "├──" + condition->ToString(prefix + "│  ");
    else
        output += prefix + "├──(no condition)\n";
    output += prefix + "└──" + body->ToString(prefix + "   ");
    return output;
}
