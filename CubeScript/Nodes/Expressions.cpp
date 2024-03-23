#include "Expressions.h"
#include <format>

namespace syntax {
//Print part
void Declaration::print(int deep) {
	for (int i = 0; i < deep; i++)
		std::cout << "..";

	std::string_view dt;
	switch (declareType) {
	case DeclareType::VAL:
		dt = "val";
		break;
	case DeclareType::VAR:
		dt = "var";
		break;
	}

	std::cout << std::format("Expression declaration <{}>:", dt) << std::endl;
	var->print(deep + 1);
}

void Assignation::print(int deep) {
	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << "Expression assignation" << std::endl;
	var->print(deep + 1);
	value->print(deep + 1);
}

void Operator::print(int deep) {
	static std::unordered_map<OperatorType, std::string_view> enumToString{
		{OperatorType::ADD, "+"},
		{OperatorType::SUB, "-"},
		{OperatorType::MUL, "*"},
		{OperatorType::DIV, "/"},
		{OperatorType::LESS, "<"},
		{OperatorType::EQUAL, "=="},
		{OperatorType::GREATER, ">"}
	};

	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << std::format("Expression operator{} for", enumToString.at(operatorType)) << std::endl;
	left->print(deep + 1);
	right->print(deep + 1);
}

void FunctionCall::print(int deep) {
	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << std::format("Function <{}> called with args:", function->name) << std::endl;
	arguments->print(deep + 1);
}

void ValueList::print(int deep) {
	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << "List value is" << std::endl;
	for (auto& value : list)
		value->print(deep + 1);
}

void Condition::print(int deep) {
	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << "Condition with" << std::endl;
	if (cond)
		cond->print(deep + 1);
	if (body)
		body->print(deep + 1);
}

void Scope::print(int deep) {
	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << "{" << std::endl;
	Scopes::enterScope();
	if (body)
		body->print(deep + 1);
	Scopes::leaveScope();
	for (int i = 0; i < deep; i++)
		std::cout << "..";
	std::cout << "}" << std::endl;
}

//type checker part

TypeIndex extractType(NodeRef node) {
	switch (node->type()) {
	case NodeType::EXPRESSION:
		return node->getAs<ExpressionBase>().recurseType();
	case NodeType::VALUE:
		return node->getAs<ValueBase>().typeIndex;
	case NodeType::VARIABLE:
		return node->getAs<Variable>().typeIndex();
	}

	throw "Can't extract type from node!";
}

TypeIndex Declaration::recurseType() {
	declareVar(var->name, typeIndex);

	if (typeIndex)
		return typeIndex;
	else
		return var->typeIndex();
}

NodeRef Declaration::extractResult() {
	return var;
}

TypeIndex Assignation::recurseType() {
	auto typeIndexVar = extractType(var);
	auto typeIndexValue = extractType(value);

	assert(typeIndexValue && "Can't assign to unkown type");
	assert((!typeIndexVar || typeIndexVar == typeIndexValue) && "Can't assign two different types");

	if (!typeIndexVar) {
		Variable& returning = extractResult()->getAs<Variable>();

		returning.typeIndex() = typeIndexValue;
	}
	return typeIndexValue;
}

NodeRef Assignation::extractResult() {
	switch (var->type()) {
	case NodeType::EXPRESSION:
		return var->getAs<ExpressionBase>().extractResult();
	case NodeType::VARIABLE:
		return var;
	case NodeType::VALUE:
		throw "Can't assign non-variable";
	}
}

TypeIndex Operator::recurseType() {
	auto leftTypeIndex = extractType(left);
	auto rightTypeIndex = extractType(right);

	assert((!leftTypeIndex || !rightTypeIndex || leftTypeIndex == rightTypeIndex) && "Can't apply operators for two different types");

	switch (operatorType) {
	case OperatorType::ADD:
	case OperatorType::SUB:
	case OperatorType::MUL:
	case OperatorType::DIV:
		result.typeIndex = leftTypeIndex;
		break;
	case OperatorType::LESS:
	case OperatorType::EQUAL:
	case OperatorType::GREATER:
		result.typeIndex = getTypeOf(ValueType::BOOLEAN);
		break;
	}

	return result.typeIndex;
}

NodeRef Operator::extractResult() {
	return &result;
}

TypeIndex ValueList::recurseType() {
	TypeIndex type = -1;
	for (auto& value : list) {
		TypeIndex current = extractType(value);
		if (type == -1)
			type = current;
		if (type != current)
			type = 0;
	}

	return type;

	//NodeRef node = this;
	//while (node->type() == NodeType::LIST) {
	//	auto& list = node->getAs<ValueList>();
	//	if(list.left->type() == NodeType::EXPRESSION)
	//		list.left->getAs<ExpressionBase>().recurseType();
	//	node = list.right;
	//}
	//if (node && node->type() == NodeType::EXPRESSION)
	//	node->getAs<ExpressionBase>().recurseType();
}

TypeIndex FunctionCall::recurseType() {
	return function->typeIndex();
}

NodeRef FunctionCall::extractResult() {
	return function;
}

TypeIndex Condition::recurseType() {
	if (cond)
		assert(extractType(cond) == getTypeOf(ValueType::BOOLEAN) && "Can't check condition with non-boolean!");

	if (body->type() == NodeType::EXPRESSION)
		body->getAs<ExpressionBase>().recurseType();
	else if (body->type() == NodeType::LIST)
		body->getAs<ValueList>().recurseType();

	if (either)
		if (either->type() == NodeType::EXPRESSION)
			either->getAs<ExpressionBase>().recurseType();
		else if (either->type() == NodeType::LIST)
			either->getAs<ValueList>().recurseType();
	return 0;
}

NodeRef Condition::extractResult() {
	return nullptr;
}

TypeIndex Scope::recurseType() {
	Scopes::createScope();
	if (body)
		if (body->type() == NodeType::EXPRESSION)
			body->getAs<ExpressionBase>().recurseType();
		else if (body->type() == NodeType::LIST)
			body->getAs<ValueList>().recurseType();
	Scopes::leaveScope();
	return 0;
}

NodeRef Scope::extractResult() {
	return nullptr;
}

//build part

NodeRef ValueList::build(llvm::Builder& builder, GlobalScope& values) {
	for (auto& value : list) {
		if (value->type() == NodeType::EXPRESSION)
			value->getAs<ExpressionBase>().build(builder, values);
	}
	//NodeRef node = this;
	//while (node->type() == NodeType::LIST) {
	//	auto& list = node->getAs<ValueList>();
	//	if (list.left->type() == NodeType::EXPRESSION)
	//		list.left->getAs<ExpressionBase>().build(builder, values);
	//	node = list.right;
	//}
	//if (node && node->type() == NodeType::EXPRESSION)
	//	node->getAs<ExpressionBase>().build(builder, values);
	return nullptr;
}

std::pair<llvm::Value*, NodeRef> extract(llvm::Builder& builder, GlobalScope& values, NodeRef node) {
	NodeRef rnode = nullptr;
	switch (node->type()) {
	case NodeType::VALUE:
		return { node->getAs<ValueBase>().build(builder, values), node };
	case NodeType::VARIABLE:
		return { values.variable(&node->getAs<Variable>()).ref, node };
	case NodeType::EXPRESSION:
		rnode = node->getAs<ExpressionBase>().build(builder, values);
		if (!rnode)
			return { nullptr, nullptr };
		assert(rnode->type() != NodeType::EXPRESSION && "Infinity building!");
		return extract(builder, values, rnode);
	default:
		throw "I don't know what happened!";
	}
}

NodeRef Declaration::build(llvm::Builder& builder, GlobalScope& values) {
	auto& typeDescription = typesDescription[var->typeIndex()];

	assert(typeDescription.typeBuilder && "Can't declare variable with this type!");

	auto type = typeDescription.typeBuilder(builder.getContext());

	auto variable = builder.CreateAlloca(type, nullptr, std::string(var->scopeName()));
	values.pushVariable(var, VariableDescription{.type = type, .ref = variable}, true);
		
	return var;
}

NodeRef Assignation::build(llvm::Builder& builder, GlobalScope& values) {
	auto [lvalue, lnode] = extract(builder, values, var);
	auto [rvalue, rnode] = extract(builder, values, value);

	if(rnode->type() == NodeType::VARIABLE)
		rvalue = loadVariable(builder, values.variable(&rnode->getAs<Variable>()));

	assert(lvalue && rvalue && "No enough values for assignation!");
	builder.CreateStore(rvalue, lvalue);
	return lnode;
}

NodeRef Operator::build(llvm::Builder& builder, GlobalScope& values) {
	static std::unordered_map<OperatorType, std::array<std::function<llvm::Value* (llvm::Value*, llvm::Value*)>, 2>> functions {
		{ OperatorType::ADD, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateAdd(l, r); }, 
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFAdd(l, r); }
		} },
		{ OperatorType::SUB, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateSub(l, r); },
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFSub(l, r); }
		} },
		{ OperatorType::MUL, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateMul(l, r); },
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFMul(l, r); }
		} },
		{ OperatorType::DIV, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateSDiv(l, r); },
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFDiv(l, r); }
		} },
		{ OperatorType::LESS, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateICmpSLT(l, r); },
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFCmpOLT(l, r); }
		} },
		{ OperatorType::EQUAL, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateICmpEQ(l, r); },
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFCmpOEQ(l, r); }
		} },
		{ OperatorType::GREATER, {
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateICmpSGT(l, r); },
			[&builder](llvm::Value* l, llvm::Value* r) { return builder.CreateFCmpOGT(l, r); }
		} },
	};

	auto [lvalue, lnode] = extract(builder, values, left);
	auto [rvalue, rnode] = extract(builder, values, right);

	if (lnode->type() == NodeType::VARIABLE)
		lvalue = loadVariable(builder, values.variable(&lnode->getAs<Variable>()));
	if (rnode->type() == NodeType::VARIABLE)
		rvalue = loadVariable(builder, values.variable(&rnode->getAs<Variable>()));

	assert(lvalue->getType() == rvalue->getType() && "Can't add different types!");	

	TypeIndex typeIndex = lnode->type() == NodeType::VARIABLE ? lnode->getAs<Variable>().typeIndex() : lnode->getAs<ValueBase>().typeIndex;

	switch (typeIndex) {
	case getTypeOf(ValueType::INT):
		result.value = functions[operatorType][0](lvalue, rvalue);
		break;
	case getTypeOf(ValueType::FLOAT):
		result.value = functions[operatorType][1](lvalue, rvalue);
		break;
	default:
		throw "unkown type met when adding";
	}
	return &result;
}

NodeRef FunctionCall::build(llvm::Builder& builder, GlobalScope& values) {
	auto& [funcRef] = values.function(function->name);

	std::vector<llvm::Value*> argList;
	size_t index = 0;

	auto takeValue = [&](NodeRef listNode) {
		auto [value, node] = extract(builder, values, listNode);
		TypeIndex nodeType;
		if (node->type() == NodeType::VARIABLE) {
			auto& var = node->getAs<Variable>();
			value = loadVariable(builder, values.variable(&var));
			nodeType = var.typeIndex();
		}
		else
			nodeType = node->getAs<ValueBase>().typeIndex;

		assert(nodeType == function->arguments[index] && "Incorrect type of argument!");

		argList.push_back(value);
	};

	if(arguments->type() == NodeType::LIST)
		for (auto& arg : arguments->getAs<ValueList>().list) {
			takeValue(arg);
			index++;
		}
	else
		takeValue(arguments);

	builder.CreateCall(funcRef, argList);
	//TODO store return

	return function;
}

NodeRef Scope::build(llvm::Builder& builder, GlobalScope& values) {
	Scopes::enterScope();
	if (body)
		if (body->type() == NodeType::EXPRESSION)
			body->getAs<ExpressionBase>().build(builder, values);
		else if (body->type() == NodeType::LIST)
			body->getAs<ValueList>().build(builder, values);
	Scopes::leaveScope();

	return nullptr;
}

NodeRef Condition::build(llvm::Builder& builder, GlobalScope& values) {
	auto [value, node] = extract(builder, values, cond);

	if(node->type() == NodeType::VARIABLE)
		value = loadVariable(builder, values.variable(&node->getAs<Variable>()));

	auto good = llvm::BasicBlock::Create(builder.getContext(), std::format("true{}", index), values.currentFunction());
	auto bad = llvm::BasicBlock::Create(builder.getContext(), std::format("false{}", index), values.currentFunction());
	auto after = llvm::BasicBlock::Create(builder.getContext(), std::format("after{}", index), values.currentFunction());
	builder.CreateCondBr(value, good, bad);

	builder.SetInsertPoint(good);
	extract(builder, values, body);
	builder.CreateBr(after);

	builder.SetInsertPoint(bad);
	if (either) {
		extract(builder, values, either);
	}
	builder.CreateBr(after);

	builder.SetInsertPoint(after);
	return nullptr;
}

NodeRef ForLoop::build(llvm::Builder& builder, GlobalScope& values) { return nullptr; }

NodeRef DoWhileLoop::build(llvm::Builder& builder, GlobalScope& values) {
	auto good = llvm::BasicBlock::Create(builder.getContext(), std::format("repeat{}", index), values.currentFunction());
	auto repeat = llvm::BasicBlock::Create(builder.getContext(), std::format("true{}", index), values.currentFunction());
	auto after = llvm::BasicBlock::Create(builder.getContext(), std::format("after{}", index), values.currentFunction());

	builder.CreateBr(good);
	builder.SetInsertPoint(repeat);

	auto [value, node] = extract(builder, values, cond);

	if (node->type() == NodeType::VARIABLE)
		value = loadVariable(builder, values.variable(&node->getAs<Variable>()));

	builder.CreateCondBr(value, good, after);

	builder.SetInsertPoint(good);
	extract(builder, values, body);
	builder.CreateBr(repeat);

	builder.SetInsertPoint(after);
	return nullptr;
}

NodeRef WhileLoop::build(llvm::Builder& builder, GlobalScope& values) {
	auto repeat = llvm::BasicBlock::Create(builder.getContext(), std::format("repeat{}", index), values.currentFunction());
	auto good = llvm::BasicBlock::Create(builder.getContext(), std::format("true{}", index), values.currentFunction());
	auto after = llvm::BasicBlock::Create(builder.getContext(), std::format("after{}", index), values.currentFunction());

	builder.CreateBr(repeat);
	builder.SetInsertPoint(repeat);

	auto [value, node] = extract(builder, values, cond);

	if (node->type() == NodeType::VARIABLE)
		value = loadVariable(builder, values.variable(&node->getAs<Variable>()));

	builder.CreateCondBr(value, good, after);

	builder.SetInsertPoint(good);
	extract(builder, values, body);
	builder.CreateBr(repeat);

	builder.SetInsertPoint(after);
	return nullptr;
}

}