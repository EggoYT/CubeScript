
// Generated from C:/Users/great/source/repos/EggoYT/CubeScript/CubeScript/Generate/CSParser.g4 by ANTLR 4.13.1


    #include "../Result.h"
    #include "../Nodes/Types.h"
    #include "../Nodes/Variables.h"
    #include "../Nodes/Expressions.h"

    using namespace syntax;



#include "CSParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;

using namespace antlr4;

namespace {

struct CSParserStaticData final {
  CSParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSParserStaticData(const CSParserStaticData&) = delete;
  CSParserStaticData(CSParserStaticData&&) = delete;
  CSParserStaticData& operator=(const CSParserStaticData&) = delete;
  CSParserStaticData& operator=(CSParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CSParserStaticData *csparserParserStaticData = nullptr;

void csparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(csparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSParserStaticData>(
    std::vector<std::string>{
      "start", "scope", "expressionList", "expression", "loopExpression", 
      "condExpression", "varRefExpression", "varDeclaration", "valueList", 
      "value", "var", "literal"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", 
      "'.'", "','", "", "':'"
    },
    std::vector<std::string>{
      "", "NEXT", "NL", "WS", "MUL", "DIV", "ADD", "SUB", "LESS", "EQUAL", 
      "GREATER", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "DOT", "COMMA", 
      "ASSIGN", "SEMI", "IF", "ELSE", "FOR", "WHILE", "DO", "Declare", "Type", 
      "Int", "Float", "String", "Boolean", "VarName"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,30,244,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,5,1,36,8,1,10,1,12,1,39,9,1,1,1,1,1,1,1,1,1,1,1,3,1,46,
  	8,1,1,2,3,2,49,8,2,1,2,1,2,1,2,4,2,54,8,2,11,2,12,2,55,1,2,1,2,1,2,5,
  	2,61,8,2,10,2,12,2,64,9,2,1,2,3,2,67,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,78,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,89,8,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,103,8,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,117,8,4,1,4,1,4,3,4,121,8,4,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,132,8,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,149,8,6,1,6,1,6,1,6,1,6,1,6,5,6,
  	156,8,6,10,6,12,6,159,9,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,
  	171,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,182,8,8,10,8,12,8,185,
  	9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,194,8,9,1,9,1,9,1,9,1,9,1,9,3,9,201,
  	8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,211,8,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,3,9,223,8,9,1,9,1,9,1,9,5,9,228,8,9,10,9,12,9,231,9,
  	9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,3,11,242,8,11,1,11,0,3,
  	12,16,18,12,0,2,4,6,8,10,12,14,16,18,20,22,0,0,261,0,24,1,0,0,0,2,45,
  	1,0,0,0,4,48,1,0,0,0,6,77,1,0,0,0,8,120,1,0,0,0,10,122,1,0,0,0,12,148,
  	1,0,0,0,14,170,1,0,0,0,16,172,1,0,0,0,18,193,1,0,0,0,20,232,1,0,0,0,22,
  	241,1,0,0,0,24,25,3,4,2,0,25,26,5,0,0,1,26,27,6,0,-1,0,27,1,1,0,0,0,28,
  	29,5,13,0,0,29,30,3,4,2,0,30,31,5,14,0,0,31,32,6,1,-1,0,32,46,1,0,0,0,
  	33,37,5,13,0,0,34,36,5,1,0,0,35,34,1,0,0,0,36,39,1,0,0,0,37,35,1,0,0,
  	0,37,38,1,0,0,0,38,40,1,0,0,0,39,37,1,0,0,0,40,41,5,14,0,0,41,46,6,1,
  	-1,0,42,43,3,6,3,0,43,44,6,1,-1,0,44,46,1,0,0,0,45,28,1,0,0,0,45,33,1,
  	0,0,0,45,42,1,0,0,0,46,3,1,0,0,0,47,49,5,1,0,0,48,47,1,0,0,0,48,49,1,
  	0,0,0,49,50,1,0,0,0,50,51,3,6,3,0,51,62,6,2,-1,0,52,54,5,1,0,0,53,52,
  	1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,57,1,0,0,0,57,58,
  	3,6,3,0,58,59,6,2,-1,0,59,61,1,0,0,0,60,53,1,0,0,0,61,64,1,0,0,0,62,60,
  	1,0,0,0,62,63,1,0,0,0,63,66,1,0,0,0,64,62,1,0,0,0,65,67,5,1,0,0,66,65,
  	1,0,0,0,66,67,1,0,0,0,67,5,1,0,0,0,68,69,3,12,6,0,69,70,6,3,-1,0,70,78,
  	1,0,0,0,71,72,3,10,5,0,72,73,6,3,-1,0,73,78,1,0,0,0,74,75,3,8,4,0,75,
  	76,6,3,-1,0,76,78,1,0,0,0,77,68,1,0,0,0,77,71,1,0,0,0,77,74,1,0,0,0,78,
  	7,1,0,0,0,79,80,5,22,0,0,80,81,5,11,0,0,81,82,3,18,9,0,82,83,5,12,0,0,
  	83,88,3,2,1,0,84,85,5,20,0,0,85,86,3,2,1,0,86,87,6,4,-1,0,87,89,1,0,0,
  	0,88,84,1,0,0,0,88,89,1,0,0,0,89,90,1,0,0,0,90,91,6,4,-1,0,91,121,1,0,
  	0,0,92,93,5,23,0,0,93,94,3,2,1,0,94,95,5,22,0,0,95,96,5,11,0,0,96,97,
  	3,18,9,0,97,102,5,12,0,0,98,99,5,20,0,0,99,100,3,2,1,0,100,101,6,4,-1,
  	0,101,103,1,0,0,0,102,98,1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,
  	105,6,4,-1,0,105,121,1,0,0,0,106,107,5,21,0,0,107,108,3,18,9,0,108,109,
  	5,11,0,0,109,110,3,18,9,0,110,111,5,12,0,0,111,116,3,2,1,0,112,113,5,
  	20,0,0,113,114,3,2,1,0,114,115,6,4,-1,0,115,117,1,0,0,0,116,112,1,0,0,
  	0,116,117,1,0,0,0,117,118,1,0,0,0,118,119,6,4,-1,0,119,121,1,0,0,0,120,
  	79,1,0,0,0,120,92,1,0,0,0,120,106,1,0,0,0,121,9,1,0,0,0,122,123,5,19,
  	0,0,123,124,5,11,0,0,124,125,3,18,9,0,125,126,5,12,0,0,126,131,3,2,1,
  	0,127,128,5,20,0,0,128,129,3,2,1,0,129,130,6,5,-1,0,130,132,1,0,0,0,131,
  	127,1,0,0,0,131,132,1,0,0,0,132,133,1,0,0,0,133,134,6,5,-1,0,134,11,1,
  	0,0,0,135,136,6,6,-1,0,136,137,5,30,0,0,137,138,5,11,0,0,138,139,3,16,
  	8,0,139,140,5,12,0,0,140,141,6,6,-1,0,141,149,1,0,0,0,142,143,3,14,7,
  	0,143,144,6,6,-1,0,144,149,1,0,0,0,145,146,3,18,9,0,146,147,6,6,-1,0,
  	147,149,1,0,0,0,148,135,1,0,0,0,148,142,1,0,0,0,148,145,1,0,0,0,149,157,
  	1,0,0,0,150,151,10,4,0,0,151,152,5,17,0,0,152,153,3,12,6,4,153,154,6,
  	6,-1,0,154,156,1,0,0,0,155,150,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,
  	0,157,158,1,0,0,0,158,13,1,0,0,0,159,157,1,0,0,0,160,161,5,24,0,0,161,
  	162,3,20,10,0,162,163,5,18,0,0,163,164,5,25,0,0,164,165,6,7,-1,0,165,
  	171,1,0,0,0,166,167,5,24,0,0,167,168,3,20,10,0,168,169,6,7,-1,0,169,171,
  	1,0,0,0,170,160,1,0,0,0,170,166,1,0,0,0,171,15,1,0,0,0,172,173,6,8,-1,
  	0,173,174,3,18,9,0,174,175,6,8,-1,0,175,183,1,0,0,0,176,177,10,2,0,0,
  	177,178,5,16,0,0,178,179,3,18,9,0,179,180,6,8,-1,0,180,182,1,0,0,0,181,
  	176,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,17,1,
  	0,0,0,185,183,1,0,0,0,186,187,6,9,-1,0,187,188,3,20,10,0,188,189,6,9,
  	-1,0,189,194,1,0,0,0,190,191,3,22,11,0,191,192,6,9,-1,0,192,194,1,0,0,
  	0,193,186,1,0,0,0,193,190,1,0,0,0,194,229,1,0,0,0,195,200,10,5,0,0,196,
  	197,5,4,0,0,197,201,6,9,-1,0,198,199,5,5,0,0,199,201,6,9,-1,0,200,196,
  	1,0,0,0,200,198,1,0,0,0,201,202,1,0,0,0,202,203,3,18,9,6,203,204,6,9,
  	-1,0,204,228,1,0,0,0,205,210,10,4,0,0,206,207,5,6,0,0,207,211,6,9,-1,
  	0,208,209,5,7,0,0,209,211,6,9,-1,0,210,206,1,0,0,0,210,208,1,0,0,0,211,
  	212,1,0,0,0,212,213,3,18,9,5,213,214,6,9,-1,0,214,228,1,0,0,0,215,222,
  	10,3,0,0,216,217,5,10,0,0,217,223,6,9,-1,0,218,219,5,9,0,0,219,223,6,
  	9,-1,0,220,221,5,8,0,0,221,223,6,9,-1,0,222,216,1,0,0,0,222,218,1,0,0,
  	0,222,220,1,0,0,0,223,224,1,0,0,0,224,225,3,18,9,4,225,226,6,9,-1,0,226,
  	228,1,0,0,0,227,195,1,0,0,0,227,205,1,0,0,0,227,215,1,0,0,0,228,231,1,
  	0,0,0,229,227,1,0,0,0,229,230,1,0,0,0,230,19,1,0,0,0,231,229,1,0,0,0,
  	232,233,5,30,0,0,233,234,6,10,-1,0,234,21,1,0,0,0,235,236,5,26,0,0,236,
  	242,6,11,-1,0,237,238,5,27,0,0,238,242,6,11,-1,0,239,240,5,28,0,0,240,
  	242,6,11,-1,0,241,235,1,0,0,0,241,237,1,0,0,0,241,239,1,0,0,0,242,23,
  	1,0,0,0,23,37,45,48,55,62,66,77,88,102,116,120,131,148,157,170,183,193,
  	200,210,222,227,229,241
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csparserParserStaticData = staticData.release();
}

}

CSParser::CSParser(TokenStream *input) : CSParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSParser::CSParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csparserParserStaticData->atn, csparserParserStaticData->decisionToDFA, csparserParserStaticData->sharedContextCache, options);
}

CSParser::~CSParser() {
  delete _interpreter;
}

const atn::ATN& CSParser::getATN() const {
  return *csparserParserStaticData->atn;
}

std::string CSParser::getGrammarFileName() const {
  return "CSParser.g4";
}

const std::vector<std::string>& CSParser::getRuleNames() const {
  return csparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSParser::getVocabulary() const {
  return csparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSParser::getSerializedATN() const {
  return csparserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSParser::ExpressionListContext* CSParser::StartContext::expressionList() {
  return getRuleContext<CSParser::ExpressionListContext>(0);
}

tree::TerminalNode* CSParser::StartContext::EOF() {
  return getToken(CSParser::EOF, 0);
}


size_t CSParser::StartContext::getRuleIndex() const {
  return CSParser::RuleStart;
}


CSParser::StartContext* CSParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    antlrcpp::downCast<StartContext *>(_localctx)->expressionListContext = expressionList();
    setState(25);
    match(CSParser::EOF);
     antlrcpp::downCast<StartContext *>(_localctx)->result =  antlrcpp::downCast<StartContext *>(_localctx)->expressionListContext->result; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

CSParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::ScopeContext::LBRACK() {
  return getToken(CSParser::LBRACK, 0);
}

CSParser::ExpressionListContext* CSParser::ScopeContext::expressionList() {
  return getRuleContext<CSParser::ExpressionListContext>(0);
}

tree::TerminalNode* CSParser::ScopeContext::RBRACK() {
  return getToken(CSParser::RBRACK, 0);
}

std::vector<tree::TerminalNode *> CSParser::ScopeContext::NEXT() {
  return getTokens(CSParser::NEXT);
}

tree::TerminalNode* CSParser::ScopeContext::NEXT(size_t i) {
  return getToken(CSParser::NEXT, i);
}

CSParser::ExpressionContext* CSParser::ScopeContext::expression() {
  return getRuleContext<CSParser::ExpressionContext>(0);
}


size_t CSParser::ScopeContext::getRuleIndex() const {
  return CSParser::RuleScope;
}


CSParser::ScopeContext* CSParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 2, CSParser::RuleScope);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(28);
      match(CSParser::LBRACK);
      setState(29);
      antlrcpp::downCast<ScopeContext *>(_localctx)->expressionListContext = expressionList();
      setState(30);
      match(CSParser::RBRACK);
       antlrcpp::downCast<ScopeContext *>(_localctx)->result =  new Scope(antlrcpp::downCast<ScopeContext *>(_localctx)->expressionListContext->result); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(33);
      match(CSParser::LBRACK);
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CSParser::NEXT) {
        setState(34);
        match(CSParser::NEXT);
        setState(39);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(40);
      match(CSParser::RBRACK);
       antlrcpp::downCast<ScopeContext *>(_localctx)->result =  new Scope(nullptr); 
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(42);
      antlrcpp::downCast<ScopeContext *>(_localctx)->expressionContext = expression();
       antlrcpp::downCast<ScopeContext *>(_localctx)->result =  new Scope(antlrcpp::downCast<ScopeContext *>(_localctx)->expressionContext->result); 
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

CSParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CSParser::ExpressionContext *> CSParser::ExpressionListContext::expression() {
  return getRuleContexts<CSParser::ExpressionContext>();
}

CSParser::ExpressionContext* CSParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<CSParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CSParser::ExpressionListContext::NEXT() {
  return getTokens(CSParser::NEXT);
}

tree::TerminalNode* CSParser::ExpressionListContext::NEXT(size_t i) {
  return getToken(CSParser::NEXT, i);
}


size_t CSParser::ExpressionListContext::getRuleIndex() const {
  return CSParser::RuleExpressionList;
}


CSParser::ExpressionListContext* CSParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 4, CSParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(48);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CSParser::NEXT) {
      setState(47);
      match(CSParser::NEXT);
    }
    setState(50);
    antlrcpp::downCast<ExpressionListContext *>(_localctx)->v1 = expression();
     _localctx->result->push(antlrcpp::downCast<ExpressionListContext *>(_localctx)->v1->result); 
    setState(62);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(53); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(52);
          match(CSParser::NEXT);
          setState(55); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == CSParser::NEXT);
        setState(57);
        antlrcpp::downCast<ExpressionListContext *>(_localctx)->v = expression();
         _localctx->result->push(antlrcpp::downCast<ExpressionListContext *>(_localctx)->v->result);  
      }
      setState(64);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(66);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CSParser::NEXT) {
      setState(65);
      match(CSParser::NEXT);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CSParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSParser::VarRefExpressionContext* CSParser::ExpressionContext::varRefExpression() {
  return getRuleContext<CSParser::VarRefExpressionContext>(0);
}

CSParser::CondExpressionContext* CSParser::ExpressionContext::condExpression() {
  return getRuleContext<CSParser::CondExpressionContext>(0);
}

CSParser::LoopExpressionContext* CSParser::ExpressionContext::loopExpression() {
  return getRuleContext<CSParser::LoopExpressionContext>(0);
}


size_t CSParser::ExpressionContext::getRuleIndex() const {
  return CSParser::RuleExpression;
}


CSParser::ExpressionContext* CSParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, CSParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSParser::Declare:
      case CSParser::Int:
      case CSParser::Float:
      case CSParser::String:
      case CSParser::VarName: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        antlrcpp::downCast<ExpressionContext *>(_localctx)->varRefExpressionContext = varRefExpression(0);
         antlrcpp::downCast<ExpressionContext *>(_localctx)->result =  antlrcpp::downCast<ExpressionContext *>(_localctx)->varRefExpressionContext->result; 
        break;
      }

      case CSParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(71);
        antlrcpp::downCast<ExpressionContext *>(_localctx)->condExpressionContext = condExpression();
         antlrcpp::downCast<ExpressionContext *>(_localctx)->result =  antlrcpp::downCast<ExpressionContext *>(_localctx)->condExpressionContext->result; 
        break;
      }

      case CSParser::FOR:
      case CSParser::WHILE:
      case CSParser::DO: {
        enterOuterAlt(_localctx, 3);
        setState(74);
        antlrcpp::downCast<ExpressionContext *>(_localctx)->loopExpressionContext = loopExpression();
         antlrcpp::downCast<ExpressionContext *>(_localctx)->result =  antlrcpp::downCast<ExpressionContext *>(_localctx)->loopExpressionContext->result; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopExpressionContext ------------------------------------------------------------------

CSParser::LoopExpressionContext::LoopExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::LoopExpressionContext::WHILE() {
  return getToken(CSParser::WHILE, 0);
}

tree::TerminalNode* CSParser::LoopExpressionContext::LPAREN() {
  return getToken(CSParser::LPAREN, 0);
}

std::vector<CSParser::ValueContext *> CSParser::LoopExpressionContext::value() {
  return getRuleContexts<CSParser::ValueContext>();
}

CSParser::ValueContext* CSParser::LoopExpressionContext::value(size_t i) {
  return getRuleContext<CSParser::ValueContext>(i);
}

tree::TerminalNode* CSParser::LoopExpressionContext::RPAREN() {
  return getToken(CSParser::RPAREN, 0);
}

std::vector<CSParser::ScopeContext *> CSParser::LoopExpressionContext::scope() {
  return getRuleContexts<CSParser::ScopeContext>();
}

CSParser::ScopeContext* CSParser::LoopExpressionContext::scope(size_t i) {
  return getRuleContext<CSParser::ScopeContext>(i);
}

tree::TerminalNode* CSParser::LoopExpressionContext::ELSE() {
  return getToken(CSParser::ELSE, 0);
}

tree::TerminalNode* CSParser::LoopExpressionContext::DO() {
  return getToken(CSParser::DO, 0);
}

tree::TerminalNode* CSParser::LoopExpressionContext::FOR() {
  return getToken(CSParser::FOR, 0);
}


size_t CSParser::LoopExpressionContext::getRuleIndex() const {
  return CSParser::RuleLoopExpression;
}


CSParser::LoopExpressionContext* CSParser::loopExpression() {
  LoopExpressionContext *_localctx = _tracker.createInstance<LoopExpressionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSParser::RuleLoopExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(79);
        match(CSParser::WHILE);
        setState(80);
        match(CSParser::LPAREN);
        setState(81);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext = value(0);
        setState(82);
        match(CSParser::RPAREN);
        setState(83);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->body = scope();
        setState(88);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          setState(84);
          match(CSParser::ELSE);
          setState(85);
          antlrcpp::downCast<LoopExpressionContext *>(_localctx)->falsed = scope();
          antlrcpp::downCast<LoopExpressionContext *>(_localctx)->elseCond =  antlrcpp::downCast<LoopExpressionContext *>(_localctx)->falsed->result;
          break;
        }

        default:
          break;
        }
         antlrcpp::downCast<LoopExpressionContext *>(_localctx)->result =  new WhileLoop(antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext->result, antlrcpp::downCast<LoopExpressionContext *>(_localctx)->body->result, _localctx->elseCond); 
        break;
      }

      case CSParser::DO: {
        enterOuterAlt(_localctx, 2);
        setState(92);
        match(CSParser::DO);
        setState(93);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->body = scope();
        setState(94);
        match(CSParser::WHILE);
        setState(95);
        match(CSParser::LPAREN);
        setState(96);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext = value(0);
        setState(97);
        match(CSParser::RPAREN);
        setState(102);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          setState(98);
          match(CSParser::ELSE);
          setState(99);
          antlrcpp::downCast<LoopExpressionContext *>(_localctx)->falsed = scope();
          antlrcpp::downCast<LoopExpressionContext *>(_localctx)->elseCond =  antlrcpp::downCast<LoopExpressionContext *>(_localctx)->falsed->result;
          break;
        }

        default:
          break;
        }
         antlrcpp::downCast<LoopExpressionContext *>(_localctx)->result =  new DoWhileLoop(antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext->result, antlrcpp::downCast<LoopExpressionContext *>(_localctx)->body->result, _localctx->elseCond); 
        break;
      }

      case CSParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(106);
        match(CSParser::FOR);
        setState(107);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext = value(0);
        setState(108);
        match(CSParser::LPAREN);
        setState(109);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext = value(0);
        setState(110);
        match(CSParser::RPAREN);
        setState(111);
        antlrcpp::downCast<LoopExpressionContext *>(_localctx)->body = scope();
        setState(116);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(112);
          match(CSParser::ELSE);
          setState(113);
          antlrcpp::downCast<LoopExpressionContext *>(_localctx)->falsed = scope();
          antlrcpp::downCast<LoopExpressionContext *>(_localctx)->elseCond =  antlrcpp::downCast<LoopExpressionContext *>(_localctx)->falsed->result;
          break;
        }

        default:
          break;
        }
         antlrcpp::downCast<LoopExpressionContext *>(_localctx)->result =  new ForLoop(antlrcpp::downCast<LoopExpressionContext *>(_localctx)->valueContext->result, antlrcpp::downCast<LoopExpressionContext *>(_localctx)->body->result, _localctx->elseCond); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondExpressionContext ------------------------------------------------------------------

CSParser::CondExpressionContext::CondExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::CondExpressionContext::IF() {
  return getToken(CSParser::IF, 0);
}

tree::TerminalNode* CSParser::CondExpressionContext::LPAREN() {
  return getToken(CSParser::LPAREN, 0);
}

CSParser::ValueContext* CSParser::CondExpressionContext::value() {
  return getRuleContext<CSParser::ValueContext>(0);
}

tree::TerminalNode* CSParser::CondExpressionContext::RPAREN() {
  return getToken(CSParser::RPAREN, 0);
}

std::vector<CSParser::ScopeContext *> CSParser::CondExpressionContext::scope() {
  return getRuleContexts<CSParser::ScopeContext>();
}

CSParser::ScopeContext* CSParser::CondExpressionContext::scope(size_t i) {
  return getRuleContext<CSParser::ScopeContext>(i);
}

tree::TerminalNode* CSParser::CondExpressionContext::ELSE() {
  return getToken(CSParser::ELSE, 0);
}


size_t CSParser::CondExpressionContext::getRuleIndex() const {
  return CSParser::RuleCondExpression;
}


CSParser::CondExpressionContext* CSParser::condExpression() {
  CondExpressionContext *_localctx = _tracker.createInstance<CondExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, CSParser::RuleCondExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(CSParser::IF);
    setState(123);
    match(CSParser::LPAREN);
    setState(124);
    antlrcpp::downCast<CondExpressionContext *>(_localctx)->valueContext = value(0);
    setState(125);
    match(CSParser::RPAREN);
    setState(126);
    antlrcpp::downCast<CondExpressionContext *>(_localctx)->trued = scope();
    setState(131);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(127);
      match(CSParser::ELSE);
      setState(128);
      antlrcpp::downCast<CondExpressionContext *>(_localctx)->falsed = scope();
      antlrcpp::downCast<CondExpressionContext *>(_localctx)->elseCond =  antlrcpp::downCast<CondExpressionContext *>(_localctx)->falsed->result;
      break;
    }

    default:
      break;
    }
     antlrcpp::downCast<CondExpressionContext *>(_localctx)->result =  new Condition(antlrcpp::downCast<CondExpressionContext *>(_localctx)->valueContext->result, antlrcpp::downCast<CondExpressionContext *>(_localctx)->trued->result, _localctx->elseCond); 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarRefExpressionContext ------------------------------------------------------------------

CSParser::VarRefExpressionContext::VarRefExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::VarRefExpressionContext::VarName() {
  return getToken(CSParser::VarName, 0);
}

tree::TerminalNode* CSParser::VarRefExpressionContext::LPAREN() {
  return getToken(CSParser::LPAREN, 0);
}

CSParser::ValueListContext* CSParser::VarRefExpressionContext::valueList() {
  return getRuleContext<CSParser::ValueListContext>(0);
}

tree::TerminalNode* CSParser::VarRefExpressionContext::RPAREN() {
  return getToken(CSParser::RPAREN, 0);
}

CSParser::VarDeclarationContext* CSParser::VarRefExpressionContext::varDeclaration() {
  return getRuleContext<CSParser::VarDeclarationContext>(0);
}

CSParser::ValueContext* CSParser::VarRefExpressionContext::value() {
  return getRuleContext<CSParser::ValueContext>(0);
}

tree::TerminalNode* CSParser::VarRefExpressionContext::ASSIGN() {
  return getToken(CSParser::ASSIGN, 0);
}

std::vector<CSParser::VarRefExpressionContext *> CSParser::VarRefExpressionContext::varRefExpression() {
  return getRuleContexts<CSParser::VarRefExpressionContext>();
}

CSParser::VarRefExpressionContext* CSParser::VarRefExpressionContext::varRefExpression(size_t i) {
  return getRuleContext<CSParser::VarRefExpressionContext>(i);
}


size_t CSParser::VarRefExpressionContext::getRuleIndex() const {
  return CSParser::RuleVarRefExpression;
}



CSParser::VarRefExpressionContext* CSParser::varRefExpression() {
   return varRefExpression(0);
}

CSParser::VarRefExpressionContext* CSParser::varRefExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSParser::VarRefExpressionContext *_localctx = _tracker.createInstance<VarRefExpressionContext>(_ctx, parentState);
  CSParser::VarRefExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, CSParser::RuleVarRefExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(136);
      antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->varnameToken = match(CSParser::VarName);
      setState(137);
      match(CSParser::LPAREN);
      setState(138);
      antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->valueListContext = valueList(0);
      setState(139);
      match(CSParser::RPAREN);
       antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->result =  new FunctionCall(new Function((antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->varnameToken != nullptr ? antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->varnameToken->getText() : "")), antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->valueListContext->result); 
      break;
    }

    case 2: {
      setState(142);
      antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->varDeclarationContext = varDeclaration();
       antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->result =  antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->varDeclarationContext->result; 
      break;
    }

    case 3: {
      setState(145);
      antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->valueContext = value(0);
       antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->result =  antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->valueContext->result; 
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(157);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VarRefExpressionContext>(parentContext, parentState);
        _localctx->v1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleVarRefExpression);
        setState(150);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(151);
        match(CSParser::ASSIGN);
        setState(152);
        antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->v2 = varRefExpression(4);
         antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->result =  new Assignation(antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->v1->result, antlrcpp::downCast<VarRefExpressionContext *>(_localctx)->v2->result);  
      }
      setState(159);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

CSParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::VarDeclarationContext::Declare() {
  return getToken(CSParser::Declare, 0);
}

CSParser::VarContext* CSParser::VarDeclarationContext::var() {
  return getRuleContext<CSParser::VarContext>(0);
}

tree::TerminalNode* CSParser::VarDeclarationContext::SEMI() {
  return getToken(CSParser::SEMI, 0);
}

tree::TerminalNode* CSParser::VarDeclarationContext::Type() {
  return getToken(CSParser::Type, 0);
}


size_t CSParser::VarDeclarationContext::getRuleIndex() const {
  return CSParser::RuleVarDeclaration;
}


CSParser::VarDeclarationContext* CSParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSParser::RuleVarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      antlrcpp::downCast<VarDeclarationContext *>(_localctx)->declareToken = match(CSParser::Declare);
      setState(161);
      antlrcpp::downCast<VarDeclarationContext *>(_localctx)->varContext = var();
      setState(162);
      match(CSParser::SEMI);
      setState(163);
      antlrcpp::downCast<VarDeclarationContext *>(_localctx)->typeToken = match(CSParser::Type);
       antlrcpp::downCast<VarDeclarationContext *>(_localctx)->result =  new Declaration(antlrcpp::downCast<VarDeclarationContext *>(_localctx)->varContext->result, (antlrcpp::downCast<VarDeclarationContext *>(_localctx)->declareToken != nullptr ? antlrcpp::downCast<VarDeclarationContext *>(_localctx)->declareToken->getText() : ""), (antlrcpp::downCast<VarDeclarationContext *>(_localctx)->typeToken != nullptr ? antlrcpp::downCast<VarDeclarationContext *>(_localctx)->typeToken->getText() : "")); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(166);
      antlrcpp::downCast<VarDeclarationContext *>(_localctx)->declareToken = match(CSParser::Declare);
      setState(167);
      antlrcpp::downCast<VarDeclarationContext *>(_localctx)->varContext = var();
       antlrcpp::downCast<VarDeclarationContext *>(_localctx)->result =  new Declaration(antlrcpp::downCast<VarDeclarationContext *>(_localctx)->varContext->result, (antlrcpp::downCast<VarDeclarationContext *>(_localctx)->declareToken != nullptr ? antlrcpp::downCast<VarDeclarationContext *>(_localctx)->declareToken->getText() : "")); 
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueListContext ------------------------------------------------------------------

CSParser::ValueListContext::ValueListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSParser::ValueContext* CSParser::ValueListContext::value() {
  return getRuleContext<CSParser::ValueContext>(0);
}

tree::TerminalNode* CSParser::ValueListContext::COMMA() {
  return getToken(CSParser::COMMA, 0);
}

CSParser::ValueListContext* CSParser::ValueListContext::valueList() {
  return getRuleContext<CSParser::ValueListContext>(0);
}


size_t CSParser::ValueListContext::getRuleIndex() const {
  return CSParser::RuleValueList;
}



CSParser::ValueListContext* CSParser::valueList() {
   return valueList(0);
}

CSParser::ValueListContext* CSParser::valueList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSParser::ValueListContext *_localctx = _tracker.createInstance<ValueListContext>(_ctx, parentState);
  CSParser::ValueListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, CSParser::RuleValueList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(173);
    antlrcpp::downCast<ValueListContext *>(_localctx)->valueContext = value(0);
     antlrcpp::downCast<ValueListContext *>(_localctx)->result =  new ValueList(antlrcpp::downCast<ValueListContext *>(_localctx)->valueContext->result); 
    _ctx->stop = _input->LT(-1);
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ValueListContext>(parentContext, parentState);
        _localctx->v1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleValueList);
        setState(176);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(177);
        match(CSParser::COMMA);
        setState(178);
        antlrcpp::downCast<ValueListContext *>(_localctx)->valueContext = value(0);
         antlrcpp::downCast<ValueListContext *>(_localctx)->result =  antlrcpp::downCast<ValueListContext *>(_localctx)->v1->result; _localctx->result->push(antlrcpp::downCast<ValueListContext *>(_localctx)->valueContext->result);  
      }
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

CSParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSParser::VarContext* CSParser::ValueContext::var() {
  return getRuleContext<CSParser::VarContext>(0);
}

CSParser::LiteralContext* CSParser::ValueContext::literal() {
  return getRuleContext<CSParser::LiteralContext>(0);
}

std::vector<CSParser::ValueContext *> CSParser::ValueContext::value() {
  return getRuleContexts<CSParser::ValueContext>();
}

CSParser::ValueContext* CSParser::ValueContext::value(size_t i) {
  return getRuleContext<CSParser::ValueContext>(i);
}

tree::TerminalNode* CSParser::ValueContext::MUL() {
  return getToken(CSParser::MUL, 0);
}

tree::TerminalNode* CSParser::ValueContext::DIV() {
  return getToken(CSParser::DIV, 0);
}

tree::TerminalNode* CSParser::ValueContext::ADD() {
  return getToken(CSParser::ADD, 0);
}

tree::TerminalNode* CSParser::ValueContext::SUB() {
  return getToken(CSParser::SUB, 0);
}

tree::TerminalNode* CSParser::ValueContext::GREATER() {
  return getToken(CSParser::GREATER, 0);
}

tree::TerminalNode* CSParser::ValueContext::EQUAL() {
  return getToken(CSParser::EQUAL, 0);
}

tree::TerminalNode* CSParser::ValueContext::LESS() {
  return getToken(CSParser::LESS, 0);
}


size_t CSParser::ValueContext::getRuleIndex() const {
  return CSParser::RuleValue;
}



CSParser::ValueContext* CSParser::value() {
   return value(0);
}

CSParser::ValueContext* CSParser::value(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSParser::ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, parentState);
  CSParser::ValueContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSParser::RuleValue, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSParser::VarName: {
        setState(187);
        antlrcpp::downCast<ValueContext *>(_localctx)->varContext = var();
         antlrcpp::downCast<ValueContext *>(_localctx)->result =  antlrcpp::downCast<ValueContext *>(_localctx)->varContext->result; 
        break;
      }

      case CSParser::Int:
      case CSParser::Float:
      case CSParser::String: {
        setState(190);
        antlrcpp::downCast<ValueContext *>(_localctx)->literalContext = literal();
         antlrcpp::downCast<ValueContext *>(_localctx)->result =  antlrcpp::downCast<ValueContext *>(_localctx)->literalContext->result; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(227);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ValueContext>(parentContext, parentState);
          _localctx->v1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleValue);
          setState(195);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(200);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case CSParser::MUL: {
              setState(196);
              match(CSParser::MUL);
              type = OperatorType::MUL;
              break;
            }

            case CSParser::DIV: {
              setState(198);
              match(CSParser::DIV);
              type = OperatorType::DIV;
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(202);
          antlrcpp::downCast<ValueContext *>(_localctx)->v2 = value(6);
           antlrcpp::downCast<ValueContext *>(_localctx)->result =  new Operator(type, antlrcpp::downCast<ValueContext *>(_localctx)->v1->result, antlrcpp::downCast<ValueContext *>(_localctx)->v2->result); 
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ValueContext>(parentContext, parentState);
          _localctx->v1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleValue);
          setState(205);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(210);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case CSParser::ADD: {
              setState(206);
              match(CSParser::ADD);
              type = OperatorType::ADD;
              break;
            }

            case CSParser::SUB: {
              setState(208);
              match(CSParser::SUB);
              type = OperatorType::SUB;
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(212);
          antlrcpp::downCast<ValueContext *>(_localctx)->v2 = value(5);
           antlrcpp::downCast<ValueContext *>(_localctx)->result =  new Operator(type, antlrcpp::downCast<ValueContext *>(_localctx)->v1->result, antlrcpp::downCast<ValueContext *>(_localctx)->v2->result); 
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ValueContext>(parentContext, parentState);
          _localctx->v1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleValue);
          setState(215);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(222);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case CSParser::GREATER: {
              setState(216);
              match(CSParser::GREATER);
              type = OperatorType::GREATER;
              break;
            }

            case CSParser::EQUAL: {
              setState(218);
              match(CSParser::EQUAL);
              type = OperatorType::EQUAL;
              break;
            }

            case CSParser::LESS: {
              setState(220);
              match(CSParser::LESS);
              type = OperatorType::LESS;
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(224);
          antlrcpp::downCast<ValueContext *>(_localctx)->v2 = value(4);
           antlrcpp::downCast<ValueContext *>(_localctx)->result =  new Operator(type, antlrcpp::downCast<ValueContext *>(_localctx)->v1->result, antlrcpp::downCast<ValueContext *>(_localctx)->v2->result); 
          break;
        }

        default:
          break;
        } 
      }
      setState(231);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

CSParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::VarContext::VarName() {
  return getToken(CSParser::VarName, 0);
}


size_t CSParser::VarContext::getRuleIndex() const {
  return CSParser::RuleVar;
}


CSParser::VarContext* CSParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 20, CSParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    antlrcpp::downCast<VarContext *>(_localctx)->varnameToken = match(CSParser::VarName);
     antlrcpp::downCast<VarContext *>(_localctx)->result =  new Variable((antlrcpp::downCast<VarContext *>(_localctx)->varnameToken != nullptr ? antlrcpp::downCast<VarContext *>(_localctx)->varnameToken->getText() : "")); 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

CSParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSParser::LiteralContext::Int() {
  return getToken(CSParser::Int, 0);
}

tree::TerminalNode* CSParser::LiteralContext::Float() {
  return getToken(CSParser::Float, 0);
}

tree::TerminalNode* CSParser::LiteralContext::String() {
  return getToken(CSParser::String, 0);
}


size_t CSParser::LiteralContext::getRuleIndex() const {
  return CSParser::RuleLiteral;
}


CSParser::LiteralContext* CSParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 22, CSParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSParser::Int: {
        enterOuterAlt(_localctx, 1);
        setState(235);
        antlrcpp::downCast<LiteralContext *>(_localctx)->intToken = match(CSParser::Int);
         antlrcpp::downCast<LiteralContext *>(_localctx)->result =  new syntax::Int(std::stoi((antlrcpp::downCast<LiteralContext *>(_localctx)->intToken != nullptr ? antlrcpp::downCast<LiteralContext *>(_localctx)->intToken->getText() : ""))); 
        break;
      }

      case CSParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(237);
        antlrcpp::downCast<LiteralContext *>(_localctx)->floatToken = match(CSParser::Float);
         antlrcpp::downCast<LiteralContext *>(_localctx)->result =  new syntax::Float(std::stod((antlrcpp::downCast<LiteralContext *>(_localctx)->floatToken != nullptr ? antlrcpp::downCast<LiteralContext *>(_localctx)->floatToken->getText() : ""))); 
        break;
      }

      case CSParser::String: {
        enterOuterAlt(_localctx, 3);
        setState(239);
        antlrcpp::downCast<LiteralContext *>(_localctx)->stringToken = match(CSParser::String);
         antlrcpp::downCast<LiteralContext *>(_localctx)->result =  new syntax::String((antlrcpp::downCast<LiteralContext *>(_localctx)->stringToken != nullptr ? antlrcpp::downCast<LiteralContext *>(_localctx)->stringToken->getText() : "")); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CSParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return varRefExpressionSempred(antlrcpp::downCast<VarRefExpressionContext *>(context), predicateIndex);
    case 8: return valueListSempred(antlrcpp::downCast<ValueListContext *>(context), predicateIndex);
    case 9: return valueSempred(antlrcpp::downCast<ValueContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSParser::varRefExpressionSempred(VarRefExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool CSParser::valueListSempred(ValueListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSParser::valueSempred(ValueContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void CSParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csparserParserInitialize();
#else
  ::antlr4::internal::call_once(csparserParserOnceFlag, csparserParserInitialize);
#endif
}
