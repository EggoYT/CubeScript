#include "Executor.h"
#include "llvm/Support/TargetSelect.h"
#include <optional>
#include <fstream>

#include "Parser/CSLexer.h"
#include "Parser/CSParser.h"

using namespace antlrcpptest;
using namespace antlr4;

inline extern void print(double v) {
    std::cout << "Called print with <" << v << ">" << std::endl;
}

int main() {
    llvm::InitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();

    Executor exec;
    syntax::GlobalScope scope;

    auto pf = exec.buildFunction("print", llvm::Type::getVoidTy, { llvm::Type::getDoubleTy });
    exec.linkFunction(print, pf);
    scope.pushFunction("print", { pf });

    syntax::declareFunction("print", { syntax::getTypeOf(syntax::ValueType::NONE), syntax::getTypeOf(syntax::ValueType::FLOAT) });


    ANTLRInputStream input(R"(
    var a = 5.0
    while (a > 0.0) {
        print(a)
        a = a - 1.0
    }
    )");
    CSLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    CSParser parser(&tokens);
    auto* tree = parser.start();

    auto node = tree->result;

    node->recurseType();
    syntax::Scopes::leaveAllScopes();
    syntax::printAST(node);

    syntax::Scopes::leaveAllScopes();
    exec.execute(node, scope);

    return 0;
}