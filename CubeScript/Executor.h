#pragma once

#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/GlobalValue.h>

#include <iostream>
#include "Result.h"
#include "Nodes/Expressions.h"

class Executor {
public:
	Executor()
		: context()
		, builder(context)
	{
		auto Owner = std::make_unique<llvm::Module>("CubeScript", context);
		module = Owner.get();
		engine = llvm::EngineBuilder(std::move(Owner)).setEngineKind(llvm::EngineKind::JIT).create();
	}

	void linkFunction(void* func, llvm::Function* IRfunc) {
		engine->addGlobalMapping(IRfunc, func);
	}

	llvm::Function* buildFunction(std::string_view name, std::function<llvm::Type*(llvm::LLVMContext&)> returnType, std::vector<std::function<llvm::Type*(llvm::LLVMContext&)>> args) {
		std::vector<llvm::Type*> argsTypes; argsTypes.reserve(args.size());
		for (auto& arg : args) {
			argsTypes.push_back(arg(context));
		}

		return llvm::Function::Create(
			llvm::FunctionType::get(
				returnType(context),
				{ argsTypes },
				0
			),
			llvm::Function::ExternalLinkage,
			name,
			*module
		);
	}

	void execute(syntax::NodeRef nodes, syntax::GlobalScope& scope) {
		compile(nodes, scope);

		module->print(llvm::outs(), nullptr);

		std::error_code errorCode;
		llvm::raw_fd_ostream outLL("./out.ll", errorCode);
		module->print(outLL, nullptr);

		std::vector<llvm::GenericValue> Args;
		auto returned = engine->runFunction(main, Args);
		std::cout << "main returned " << returned.IntVal.getZExtValue() << std::endl;
	}

private:
	enum class ExpressionResult {
		DECLARE_VAR,
		DECLARE_VAL
	};

	void compile(syntax::NodeRef nodes, syntax::GlobalScope& scope);

	syntax::NodeRef recurseNode(syntax::NodeRef node, syntax::GlobalScope& vars);

	llvm::LLVMContext context;
	llvm::Module* module;
	llvm::Builder builder;
	llvm::ExecutionEngine* engine;

	llvm::Function* main;
};