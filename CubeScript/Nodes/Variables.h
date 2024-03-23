#pragma once

#include "../Result.h"
#include "Scope.h"
#include "Types.h"
#include <unordered_set>
#include <optional>
#include <ranges>

namespace syntax {

struct Variable : NodeBase {
	Variable(std::string_view name)
		: name(name)
		, scopeName_(std::nullopt)
		, typeIndex_(nullptr)
	{}

	virtual bool function() { return false; }
	virtual NodeType type() { return NodeType::VARIABLE; }
	virtual TypeIndex& typeIndex();
	std::string_view scopeName();

	virtual void print(int deep = 0) override {
		assert(typeIndex() && "Type doesn't set");
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << std::format("Variable {} have type {}", name, std::string_view(typesDescription.at(typeIndex()).typeName)) << std::endl;
	}

	std::string name;
private:
	std::optional<std::string> scopeName_;
	TypeIndex* typeIndex_;
};

struct Function : Variable {
	Function(std::string_view name)
		: Variable(std::string(name))
	{}

	virtual bool function() { return true; }
	virtual TypeIndex& typeIndex() override;
	virtual void print(int deep = 0) override {
		assert(typeIndex() && "Type doesn't set");
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << std::format("Function {} have type {} and args: ", name, std::string_view(typesDescription.at(typeIndex()).typeName));
		for (auto& arg : arguments)
			std::cout << typesDescription.at(arg).typeName;
		std::cout << std::endl;
	}

	std::vector<TypeIndex> arguments;
};

void declareVar(std::string_view name, TypeIndex type);
void declareFunction(std::string_view name, const std::vector<TypeIndex>& type);

namespace Scopes {

void enterScope();
void leaveScope();
void createScope();
void destroyScopes();
void leaveAllScopes();
std::string buildName(std::string_view name);

}

inline llvm::Value* loadVariable(llvm::Builder& builder, VariableDescription& var) {
	return builder.CreateLoad(var.type, var.ref);
}

}