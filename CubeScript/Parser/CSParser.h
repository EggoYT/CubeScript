
// Generated from C:/Users/great/source/repos/EggoYT/CubeScript/CubeScript/Generate/CSParser.g4 by ANTLR 4.13.1

#pragma once


    #include "../Result.h"
    #include "../Nodes/Types.h"
    #include "../Nodes/Variables.h"
    #include "../Nodes/Expressions.h"

    using namespace syntax;


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  CSParser : public antlr4::Parser {
public:
  enum {
    NEXT = 1, NL = 2, WS = 3, MUL = 4, DIV = 5, ADD = 6, SUB = 7, LESS = 8, 
    EQUAL = 9, GREATER = 10, LPAREN = 11, RPAREN = 12, LBRACK = 13, RBRACK = 14, 
    DOT = 15, COMMA = 16, ASSIGN = 17, SEMI = 18, IF = 19, ELSE = 20, FOR = 21, 
    WHILE = 22, DO = 23, Declare = 24, Type = 25, Int = 26, Float = 27, 
    String = 28, Boolean = 29, VarName = 30
  };

  enum {
    RuleStart = 0, RuleScope = 1, RuleExpressionList = 2, RuleExpression = 3, 
    RuleLoopExpression = 4, RuleCondExpression = 5, RuleVarRefExpression = 6, 
    RuleVarDeclaration = 7, RuleValueList = 8, RuleValue = 9, RuleVar = 10, 
    RuleLiteral = 11
  };

  explicit CSParser(antlr4::TokenStream *input);

  CSParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CSParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


      OperatorType type;


  class StartContext;
  class ScopeContext;
  class ExpressionListContext;
  class ExpressionContext;
  class LoopExpressionContext;
  class CondExpressionContext;
  class VarRefExpressionContext;
  class VarDeclarationContext;
  class ValueListContext;
  class ValueContext;
  class VarContext;
  class LiteralContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    ValueList* result;
    CSParser::ExpressionListContext *expressionListContext = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    Scope* result;
    CSParser::ExpressionListContext *expressionListContext = nullptr;
    CSParser::ExpressionContext *expressionContext = nullptr;
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<antlr4::tree::TerminalNode *> NEXT();
    antlr4::tree::TerminalNode* NEXT(size_t i);
    ExpressionContext *expression();

   
  };

  ScopeContext* scope();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ValueList* result = new ValueList();
    CSParser::ExpressionContext *v1 = nullptr;
    CSParser::ExpressionContext *v = nullptr;
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEXT();
    antlr4::tree::TerminalNode* NEXT(size_t i);

   
  };

  ExpressionListContext* expressionList();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    NodeRef result;
    CSParser::VarRefExpressionContext *varRefExpressionContext = nullptr;
    CSParser::CondExpressionContext *condExpressionContext = nullptr;
    CSParser::LoopExpressionContext *loopExpressionContext = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarRefExpressionContext *varRefExpression();
    CondExpressionContext *condExpression();
    LoopExpressionContext *loopExpression();

   
  };

  ExpressionContext* expression();

  class  LoopExpressionContext : public antlr4::ParserRuleContext {
  public:
    Loop* result;
    Scope* elseCond = nullptr;;
    CSParser::ValueContext *valueContext = nullptr;
    CSParser::ScopeContext *body = nullptr;
    CSParser::ScopeContext *falsed = nullptr;
    LoopExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ScopeContext *> scope();
    ScopeContext* scope(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *FOR();

   
  };

  LoopExpressionContext* loopExpression();

  class  CondExpressionContext : public antlr4::ParserRuleContext {
  public:
    Condition* result;
    Scope* elseCond = nullptr;;
    CSParser::ValueContext *valueContext = nullptr;
    CSParser::ScopeContext *trued = nullptr;
    CSParser::ScopeContext *falsed = nullptr;
    CondExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ValueContext *value();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ScopeContext *> scope();
    ScopeContext* scope(size_t i);
    antlr4::tree::TerminalNode *ELSE();

   
  };

  CondExpressionContext* condExpression();

  class  VarRefExpressionContext : public antlr4::ParserRuleContext {
  public:
    NodeRef result;
    CSParser::VarRefExpressionContext *v1 = nullptr;
    antlr4::Token *varnameToken = nullptr;
    CSParser::ValueListContext *valueListContext = nullptr;
    CSParser::VarDeclarationContext *varDeclarationContext = nullptr;
    CSParser::ValueContext *valueContext = nullptr;
    CSParser::VarRefExpressionContext *v2 = nullptr;
    VarRefExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VarName();
    antlr4::tree::TerminalNode *LPAREN();
    ValueListContext *valueList();
    antlr4::tree::TerminalNode *RPAREN();
    VarDeclarationContext *varDeclaration();
    ValueContext *value();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<VarRefExpressionContext *> varRefExpression();
    VarRefExpressionContext* varRefExpression(size_t i);

   
  };

  VarRefExpressionContext* varRefExpression();
  VarRefExpressionContext* varRefExpression(int precedence);
  class  VarDeclarationContext : public antlr4::ParserRuleContext {
  public:
    Declaration* result;
    antlr4::Token *declareToken = nullptr;
    CSParser::VarContext *varContext = nullptr;
    antlr4::Token *typeToken = nullptr;
    VarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Declare();
    VarContext *var();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *Type();

   
  };

  VarDeclarationContext* varDeclaration();

  class  ValueListContext : public antlr4::ParserRuleContext {
  public:
    ValueList* result;
    CSParser::ValueListContext *v1 = nullptr;
    CSParser::ValueContext *valueContext = nullptr;
    ValueListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();
    antlr4::tree::TerminalNode *COMMA();
    ValueListContext *valueList();

   
  };

  ValueListContext* valueList();
  ValueListContext* valueList(int precedence);
  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    NodeRef result;
    CSParser::ValueContext *v1 = nullptr;
    CSParser::VarContext *varContext = nullptr;
    CSParser::LiteralContext *literalContext = nullptr;
    CSParser::ValueContext *v2 = nullptr;
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    LiteralContext *literal();
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *LESS();

   
  };

  ValueContext* value();
  ValueContext* value(int precedence);
  class  VarContext : public antlr4::ParserRuleContext {
  public:
    Variable* result;
    antlr4::Token *varnameToken = nullptr;
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VarName();

   
  };

  VarContext* var();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    ValueBase* result;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *stringToken = nullptr;
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();
    antlr4::tree::TerminalNode *String();

   
  };

  LiteralContext* literal();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool varRefExpressionSempred(VarRefExpressionContext *_localctx, size_t predicateIndex);
  bool valueListSempred(ValueListContext *_localctx, size_t predicateIndex);
  bool valueSempred(ValueContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace antlrcpptest
