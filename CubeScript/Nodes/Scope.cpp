#include "Scope.h"
#include "Variables.h"
#include <ranges>

namespace syntax {

VariableDescription& GlobalScope::variable(Variable* var) {
	auto iter = variables.find(var->scopeName());
	if (iter == variables.end())
		throw "Can't find variable";
	return iter->second;
}

void GlobalScope::pushVariable(Variable* var, const VariableDescription& description, bool declaring) {
	if (declaring) {
		assert(variables.find(var->scopeName()) == variables.end() && "Variable had been already declared");

		variables.emplace(var->scopeName(), description);
	}
	else {
		auto iter = variables.find(var->scopeName());
		assert(iter != variables.end() && "Variable didn't have been already declared");

		iter->second = description;
	}
}

llvm::Value* GlobalScope::stringLiteral(std::string_view name) {
	auto iter = stringLiterals.find(name);

	if (iter == stringLiterals.end())
		return nullptr;
	return iter->second;
}

FunctionDescription& GlobalScope::function(std::string_view name) {
	auto iter = functions.find({ name.begin(), name.end() });

	assert(iter != functions.end() && "Can't find function");
	return iter->second;
}

void GlobalScope::pushFunction(std::string_view name, const FunctionDescription& description) {
	auto iter = functions.find(name);

	assert(iter == functions.end() && "Function had been already declared");
	functions.emplace(name, description);
}

}