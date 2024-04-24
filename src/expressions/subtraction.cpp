#include "subtraction.h"

std::unique_ptr<VarType> ASTExpressionSubtraction::ReturnType(ASTFunction& func)
{
    if (!returnType) 
    {
        if (!ASTExpression::CoerceMathTypes(func, a1, a2, returnType)) 
            throw std::runtime_error("ERROR: Cannot coerce types in subtraction expression! Are they both either ints or floats?");
    }
    return std::make_unique<VarTypeSimple>(*returnType); 
}

bool ASTExpressionSubtraction::IsLValue(ASTFunction& func)
{
    return false; 
}

llvm::Value* ASTExpressionSubtraction::Compile(llvm::IRBuilder<>& builder, ASTFunction& func)
{
    auto retType = ReturnType(func);
    if (retType->Equals(&VarTypeSimple::IntType)) 
        return builder.CreateSub(a1->CompileRValue(builder, func), a2->CompileRValue(builder, func));
    else if (retType->Equals(&VarTypeSimple::FloatType)) 
        return builder.CreateFSub(a1->CompileRValue(builder, func), a2->CompileRValue(builder, func));
    else 
        throw std::runtime_error("ERROR: Cannot perform subtraction! Are both inputs either ints or floats?");
}

std::string ASTExpressionSubtraction::ToString(const std::string& prefix)
{
    std::string ret = "(-)\n";
    ret += prefix + "├──" + a1->ToString(prefix + "│  ");
    ret += prefix + "└──" + a2->ToString(prefix + "   ");
    return ret;
}
