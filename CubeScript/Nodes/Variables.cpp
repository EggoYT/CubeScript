#include "Variables.h"

namespace syntax {

using VarScope = std::unordered_map<std::string_view, std::pair<std::string, std::shared_ptr<TypeIndex>>>;
using Functions = std::unordered_map<std::string_view, std::vector<TypeIndex>>;

namespace {

struct Scope {
	Scope(Scope* parent, size_t index)
		: parent(parent)
		, index(std::to_string(index))
		, lookup(scopes.begin())
	{}

	VarScope values;
	std::list<Scope> scopes;
	Scope* const parent;
	std::list<Scope>::iterator lookup;
	std::string index;

	void leave() {
		for (auto& scope : scopes)
			scope.leave();
		lookup = scopes.begin();
	}

	Scope& enter() {
		assert(scopes.size() && "No scopes here!");
		if (lookup == scopes.end())
			lookup = scopes.begin();

		return *(lookup++);
	}
};

Scope global(nullptr, 0);
Scope* localScope = &global;
int scopeCount = 1;

Functions funcs;
}

TypeIndex& Variable::typeIndex() {
	if (typeIndex_)
		return *typeIndex_;

	auto scope = localScope;
	while (scope != nullptr) {
		auto iter = scope->values.find(name);
		if (iter != scope->values.end()) {
			scopeName_ = iter->second.first;
			typeIndex_ = iter->second.second.get();
			return *iter->second.second;
		}

		scope = scope->parent;
	}
	throw "Variable hadn't been declared!";
}

std::string_view Variable::scopeName() {
	if (scopeName_)
		return *scopeName_;

	auto scope = localScope;
	while (scope != nullptr) {
		auto iter = scope->values.find(name);
		if (iter != scope->values.end()) {
			scopeName_ = iter->second.first;
			typeIndex_ = iter->second.second.get();
			return iter->second.first;
		}

		scope = scope->parent;
	}
	throw "Variable hadn't been declared!";
}

TypeIndex& Function::typeIndex() {
	auto iter = funcs.find(name);
	if (iter == funcs.end())
		throw "Function hadn't been declared!";

	if (!arguments.size())
		arguments.insert(arguments.end(), iter->second.begin() + 1, iter->second.end());

	return iter->second.front();
}

std::string formatName(Scope* scope, std::string_view name) {
	return std::format("{}_{}", scope->index, name);
}

void declareVar(std::string_view name, TypeIndex type) {
	assert(!localScope->values.contains(name) && "Var has been already declared!");

	localScope->values.emplace(name, std::pair<std::string, std::shared_ptr<TypeIndex>>{ formatName(localScope, name), std::make_shared<TypeIndex>(type) });
}

void declareFunction(std::string_view name, const std::vector<TypeIndex>& func) {
	assert(!funcs.contains(name) && "Func has been already declared!");

	funcs.emplace(name, func);
}

namespace Scopes {

void enterScope() {
	localScope = &localScope->enter();
}

void leaveScope() {
	assert(localScope != &global && "Can't leave from global scope!");
	localScope = localScope->parent;
}

void createScope() {
	localScope = &localScope->scopes.emplace_back(localScope, scopeCount++);
}

void destroyScopes() {
	global.scopes.clear();
	global.values.clear();
	global.lookup = global.scopes.begin();
	localScope = &global;
	scopeCount = 1;
}

void leaveAllScopes() {
	global.leave();
	localScope = &global;
}

std::string buildName(std::string_view name) {
	auto scope = localScope;
	while (scope != nullptr) {
		auto iter = scope->values.find(name);
		if (iter != scope->values.end())
			return formatName(scope, name);

		scope = scope->parent;
	}
	throw "Variable hadn't been declared!";
}

}

}