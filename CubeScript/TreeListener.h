#pragma once

#include "Result.h"
#include "Nodes/Expressions.h"
#include "Nodes/Variables.h"

class ASTListener : tree::ParseTreeListener {
public:
    ASTListener() {}

    virtual void visitTerminal(tree::TerminalNode* node) {
        for (int i = 0; i < depth; i++)
            std::cout << "..";
        std::cout << "Value " << node->getText() << std::endl;
    }

    virtual void visitErrorNode(tree::ErrorNode* node) {

    }

    virtual void enterEveryRule(ParserRuleContext* ctx) {
        for (int i = 0; i < depth; i++)
            std::cout << "..";
        std::cout << "Expression " << (ctx->children.size() == 3 ? ctx->children[1] : ctx->children[0])->getText() << std::endl;
        depth++;
    }

    virtual void exitEveryRule(ParserRuleContext* ctx) {
        depth--;
        for (int i = 0; i < depth; i++)
            std::cout << "..";
        std::cout << "End expression" << std::endl;
    }
private:
    int depth = 0;
};