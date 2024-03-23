
// Generated from C:/Users/great/source/repos/EggoYT/CubeScript/CubeScript/Generate/CSLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  CSLexer : public antlr4::Lexer {
public:
  enum {
    NEXT = 1, NL = 2, WS = 3, MUL = 4, DIV = 5, ADD = 6, SUB = 7, LESS = 8, 
    EQUAL = 9, GREATER = 10, LPAREN = 11, RPAREN = 12, LBRACK = 13, RBRACK = 14, 
    DOT = 15, COMMA = 16, ASSIGN = 17, SEMI = 18, IF = 19, ELSE = 20, FOR = 21, 
    WHILE = 22, DO = 23, Declare = 24, Type = 25, Int = 26, Float = 27, 
    String = 28, Boolean = 29, VarName = 30
  };

  explicit CSLexer(antlr4::CharStream *input);

  ~CSLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace antlrcpptest
