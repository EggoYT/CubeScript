#pragma once

#include "../Result.h"
#include "Types.h"
#include "Variables.h"
#include <optional>
#include <xhash>
#include <llvm/IR/IRBuilder.h>

namespace syntax {

enum class ExpressionType {
	DECLARE,
	ASSIGNATION,
	OPERATOR,
	FUNCTION_CALL,
	CONDITION,
	SCOPE,
	LOOP,
};

struct ExpressionBase : NodeBase {
	virtual NodeType type() override { return NodeType::EXPRESSION; }
	virtual ExpressionType expressionType() = 0;

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& values) = 0;

	virtual TypeIndex recurseType() = 0;
	virtual NodeRef extractResult() = 0;
};
template<class T> concept Expression = std::is_base_of_v<ExpressionBase, T>;

struct Declaration : ExpressionBase {
	Declaration(Variable* variable, std::string_view declareType, std::string_view type = "")
		: var(variable)
		, declareType(parseDeclareType(declareType))
		, typeIndex(parseTypeIndex(type))
	{}

	virtual ExpressionType expressionType() override { return ExpressionType::DECLARE; }

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& values) override;

	virtual void print(int deep) override;

	virtual TypeIndex recurseType() override;

	virtual NodeRef extractResult() override;
	
private:
	TypeIndex parseTypeIndex(std::string_view type) {
		if (type.empty())
			return 0;
		for (TypeIndex i = 0; i < typesDescription.size(); ++i) {
			if (type == typesDescription[i].typeName)
				return i;
		}
		return 0;
	}

	enum class DeclareType {
		VAL,
		VAR,
	};

	DeclareType parseDeclareType(std::string_view type) {
		if (type.find("var") != type.npos)
			return DeclareType::VAR;
		else
			return DeclareType::VAL;
		//return type.size() ? (type == "var" ? DeclareType::VAR : DeclareType::VAL) : DeclareType::NONE;
	}
		
	Variable* var;
	TypeIndex typeIndex;
	DeclareType declareType;
};

struct Assignation : ExpressionBase {
public:
	Assignation(NodeRef var, NodeRef value)
		: var(var)
		, value(value) 
	{}

	virtual ExpressionType expressionType() override { return ExpressionType::ASSIGNATION; }

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& values) override;

	virtual void print(int deep = 0) override;

	virtual TypeIndex recurseType() override;

	virtual NodeRef extractResult() override;
private:
	NodeRef var;
	NodeRef value;
};

enum class OperatorType {
	ADD,
	SUB,
	MUL,
	DIV,
	LESS,
	EQUAL,
	GREATER
};

struct Operator : ExpressionBase {
	Operator(OperatorType type, NodeRef left, NodeRef right)
		: operatorType(type)
		, left(left)
		, right(right)
	{}

	virtual ExpressionType expressionType() override { return ExpressionType::OPERATOR; }

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;

	virtual void print(int deep = 0) override;

	virtual TypeIndex recurseType() override;
	virtual NodeRef extractResult() override;

	const OperatorType operatorType;
	NodeRef left;
	NodeRef right;
	TemporaryValue result;
};

struct ValueList : NodeBase {
	ValueList(NodeRef value = nullptr)
	{
		if (value)
			list.push_back(value);
	}

	virtual NodeType type() override { return NodeType::LIST; }

	virtual void print(int deep = 0) override;

	NodeRef build(llvm::Builder& builder, GlobalScope& values);

	TypeIndex recurseType();

	void push(NodeRef value) { list.push_back(value); }

	std::list<NodeRef> list;
};

struct FunctionCall : ExpressionBase {
	FunctionCall(Function* function, NodeRef argList)
		: function(function)
		, arguments(argList)
	{}

	virtual ExpressionType expressionType() override { return ExpressionType::FUNCTION_CALL; }

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;

	virtual void print(int deep = 0) override;

	virtual TypeIndex recurseType() override;

	virtual NodeRef extractResult() override;

	Function* function;
	NodeRef arguments;
};

struct Scope : ExpressionBase {
	Scope(NodeRef body)
		: body(body)
	{}

	virtual ExpressionType expressionType() override { return ExpressionType::SCOPE; }

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;

	virtual void print(int deep = 0) override;

	virtual TypeIndex recurseType() override;

	virtual NodeRef extractResult() override;

	NodeRef body;
};

struct Condition : ExpressionBase {
	Condition(NodeRef cond, NodeRef body, NodeRef either = nullptr)
		: cond(cond)
		, body(body)
		, either(either)
		, index(loopIndex++)
	{}

	virtual ExpressionType expressionType() override { return ExpressionType::CONDITION; }

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;

	virtual void print(int deep = 0) override;

	virtual TypeIndex recurseType() override;

	virtual NodeRef extractResult() override;

	NodeRef cond;
	NodeRef body;
	NodeRef either;
	size_t index;
	inline static size_t loopIndex;
};

struct Loop : Condition {
	Loop(NodeRef cond, NodeRef body, NodeRef either) : Condition(cond, body, either) {}

	virtual ExpressionType expressionType() override { return ExpressionType::LOOP; }
};

struct ForLoop : Loop {
	ForLoop(NodeRef cond, NodeRef body, NodeRef either = nullptr) : Loop(cond, body, either) {}

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;
};

struct WhileLoop : Loop {
	WhileLoop(NodeRef cond, NodeRef body, NodeRef either = nullptr) : Loop(cond, body, either) {}

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;
};

struct DoWhileLoop : Loop {
	DoWhileLoop(NodeRef cond, NodeRef body, NodeRef either = nullptr) : Loop(cond, body, either) {}

	virtual NodeRef build(llvm::Builder& builder, GlobalScope& variables) override;
};

}