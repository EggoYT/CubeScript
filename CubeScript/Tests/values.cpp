#include "../Parser/CSLexer.h"
#include "../Parser/CSParser.h"

#include <string_view>

using namespace antlrcpptest;
using namespace antlr4;

namespace tests {

namespace values {

namespace {
struct Tester {
	Tester(std::string_view label, std::string_view test)
		: lexer(test)
		, lexStream(&lexer)
		, parser(&lexStream)
	{
		parser.addErrorListener(&listener);
	}

	struct ErrorListener : BaseErrorListener {
		ErrorListener(std::string_view label) : label(label) {}

		virtual void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line, size_t charPositionInLine,
			const std::string& msg, std::exception_ptr e) override {
			throw std::format("Test {} failed: {}", label, msg);
		}
		
		std::string label;
	};

	CSLexer lexer;
	CommonTokenStream lexStream;
	CSParser parser;
	ErrorListener listener;
};

void test(std::string_view label, std::string_view test) { Tester test(label, test); }

}

void recurseForTests() {
	try {
		test("Literals", R"(
			var a = 10
			a = 10.0
			a = "TEST STRING"
			a = true
			a = -10
			a = -10.0
			a = 10F
			a = 10.0F
			a = .F
			a = .0F
			a = 0.F
		)");
	}
	catch (...) {
		;
	}
}

}

}