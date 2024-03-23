#pragma once

#include "../Result.h"
#include "Scope.h"
#include <string>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <functional>

namespace syntax {

struct TypeDescription {
	std::pmr::string typeName;
	int allocaSize;
	std::function<llvm::Type*(llvm::LLVMContext&)> typeBuilder;
};

inline std::vector<TypeDescription> typesDescription {
	{"Unknown", 0},
	{"Int", sizeof(int64_t), llvm::Type::getInt64Ty},
	{"Float", sizeof(double), llvm::Type::getDoubleTy},
	{"String", sizeof(std::string), [](llvm::LLVMContext& context) { return llvm::PointerType::get(context, 0); }},
	{"Boolean", sizeof(bool), llvm::Type::getInt1Ty}
};

enum class ValueType {
	NONE,
	INT,
	FLOAT,
	STRING,
	BOOLEAN,
	TEMPORARY,
};

inline constexpr TypeIndex getTypeOf(ValueType value) {
	return static_cast<TypeIndex>(value);
}

struct ValueBase : NodeBase {
	ValueBase(TypeIndex typeIndex) : typeIndex(typeIndex) {}

	virtual NodeType type() override { return NodeType::VALUE; }
	virtual ValueType valueType() = 0;
	virtual llvm::Value* build(llvm::Builder& builder, GlobalScope& values) = 0;

	TypeDescription& typeDescription() { return typesDescription[typeIndex]; }

	TypeIndex typeIndex;
};
template<class T> concept Literall = std::is_base_of_v<ValueBase, T>;

inline TypeIndex extractTypeIndex(NodeRef node) {
	if (node->type() != NodeType::VALUE)
		return 0;

	return node->getAs<ValueBase>().typeIndex;
}


struct Int : ValueBase {
	Int(int64_t value) : ValueBase(getTypeOf(valueType())), value(value) {}

	virtual ValueType valueType() override { return ValueType::INT; }

	virtual void print(int deep = 0) override {
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << "Int value is " << value << std::endl;
	}

	virtual llvm::Value* build(llvm::Builder& builder, GlobalScope& values) override {
		auto type = typeDescription().typeBuilder(builder.getContext());
		return llvm::Constant::getIntegerValue(type, llvm::APInt(8 * sizeof(value), value, true));
	}

	int64_t value;
};

struct Float : ValueBase {
	Float(double value) : ValueBase(getTypeOf(valueType())), value(value) {}

	virtual ValueType valueType() override { return ValueType::FLOAT; }

	virtual void print(int deep = 0) override {
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << "Float value is " << value << std::endl;
	}

	virtual llvm::Value* build(llvm::Builder& builder, GlobalScope& values) override {
		auto type = typeDescription().typeBuilder(builder.getContext());
		return llvm::ConstantFP::get(type, value);
	}

	float value;
};

struct String : ValueBase {
	String(std::string value) : ValueBase(getTypeOf(valueType())), value(std::move(value)) {}

	virtual ValueType valueType() override { return ValueType::STRING; }

	virtual void print(int deep = 0) override {
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << "String value is " << value << std::endl;
	}

	virtual llvm::Value* build(llvm::Builder& builder, GlobalScope& values) override {
		llvm::Value* literal = values.stringLiteral(value);
		if (!literal) {
			literal = builder.CreateGlobalString(value);
			values.pushLiteral(value, literal);
		}
		return literal;
	}

	std::string value;
};

struct Boolean : ValueBase {
	Boolean(std::string_view value) : ValueBase(getTypeOf(valueType())), value(value == "true" ? true : false) {}

	virtual ValueType valueType() override { return ValueType::BOOLEAN; }

	virtual void print(int deep = 0) override {
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << "Boolean value is " << (value ? "true" : "false") << std::endl;
	}

	virtual llvm::Value* build(llvm::Builder& builder, GlobalScope& values) override {
		auto type = typeDescription().typeBuilder(builder.getContext());
		return llvm::Constant::getIntegerValue(type, llvm::APInt(8, value, false));
	}

	bool value;
};

struct TemporaryValue : ValueBase {
	TemporaryValue()
		: ValueBase(0)
		, value(nullptr)
	{}

	virtual ValueType valueType() override { return ValueType::TEMPORARY; }

	virtual void print(int deep = 0) override {
		for (int i = 0; i < deep; i++)
			std::cout << "..";
		std::cout << "Temporary value!" << std::endl;
	}

	virtual llvm::Value* build(llvm::Builder& builder, GlobalScope& values) override {
		return value;
	}

	llvm::Value* value;
};

struct VarTypes {
	std::unordered_map<std::string_view, TypeIndex> vars;
	std::unordered_map<std::string_view, std::vector<TypeIndex>> funcs;
};

}