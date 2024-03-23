#include "Executor.h"

syntax::NodeRef Executor::recurseNode(syntax::NodeRef node, syntax::GlobalScope& scope) {
	if (!node)
		return nullptr;

	switch (node->type()) {
	case syntax::NodeType::EXPRESSION:
		return static_cast<syntax::ExpressionBase*>(node)->build(builder, scope);
	case syntax::NodeType::LIST:
		return node->getAs<syntax::ValueList>().build(builder, scope);
	case syntax::NodeType::VALUE:
	case syntax::NodeType::VARIABLE:
		return nullptr;
	}
}

using namespace llvm;

void Executor::compile(syntax::NodeRef nodes, syntax::GlobalScope& scope) {
	auto returnType = FunctionType::get(builder.getInt32Ty(), false);

	main = Function::Create(returnType, Function::ExternalLinkage, "main", module);
	verifyFunction(*main);

	auto entry = BasicBlock::Create(context, "entry", main);
	builder.SetInsertPoint(entry);

	scope.setCurrentFunction(main);

	recurseNode(nodes, scope);

	//auto loaded = builder.CreateLoad(Type::getInt8Ty(context), vars.variable("0_a").ref);
	//builder.CreateCall(print, { loaded });

	//auto floatVar = builder.CreateAlloca(Type::getDoubleTy(context), nullptr, "lolkekcheburek");

	auto result = builder.CreateRet(builder.getInt32(0));
}