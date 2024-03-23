#pragma once

#include "../Result.h"
#include <unordered_map>
#include <string_view>
#include <llvm/IR/Type.h>

namespace syntax {

struct FunctionDescription {
	llvm::Function* ref;
};

struct ScopeValues {
	std::unordered_map<std::string_view, VariableDescription> variables;
};

struct Variable;

class GlobalScope : ScopeValues {
public:
	GlobalScope() {}

	VariableDescription& variable(Variable* var);

	void pushVariable(Variable* var, const VariableDescription& description, bool declaring = false);

	llvm::Value* stringLiteral(std::string_view name);

	void pushLiteral(std::string_view name, llvm::Value* literal) {
		assert(stringLiterals.find(name) == stringLiterals.end() && "Literal already declared!");

		stringLiterals.emplace(name, literal);
	}

	FunctionDescription& function(std::string_view name);

	void pushFunction(std::string_view name, const FunctionDescription& description);

	void setCurrentFunction(llvm::Function* func) {
		current = func;
	}

	llvm::Function* currentFunction() {
		return current;
	}
private:
	std::unordered_map<std::string_view, llvm::Value*> stringLiterals;
	std::unordered_map<std::string_view, FunctionDescription> functions;
	llvm::Function* current = nullptr;
};

}