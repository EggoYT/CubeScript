#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <variant>
#include <unordered_map>
#include <format>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/NoFolder.h>

namespace llvm {
	using Builder = IRBuilder<llvm::NoFolder>;
}

namespace syntax {

enum class NodeType {
	EXPRESSION,
	VALUE,
	VARIABLE,
	LIST,
};

struct NodeBase;
template<class T> concept Node = std::is_base_of_v<NodeBase, T>;

class GlobalScope;

struct NodeBase {
	NodeBase() {}

	template<Node N> N& getAs() { return static_cast<N&>(*this); }

	virtual NodeType type() = 0;
	virtual void print(int deep = 0) = 0;

protected:
};

using NodeRef = NodeBase*;
using TypeIndex = uint16_t;

struct VariableDescription {
	llvm::Type* type;
	llvm::Value* ref;
};

inline void printAST(NodeRef nodes) {
	std::cout << "AST /////////" << std::endl;
	nodes->print(0);
	std::cout << "/////////////" << std::endl;
}

};