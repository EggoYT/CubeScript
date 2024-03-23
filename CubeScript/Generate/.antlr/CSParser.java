// Generated from c://Users//great//source//repos//EggoYT//CubeScript//CubeScript//Generate//CSParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class CSParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NEXT=1, NL=2, WS=3, MUL=4, DIV=5, ADD=6, SUB=7, LESS=8, EQUAL=9, GREATER=10, 
		LPAREN=11, RPAREN=12, LBRACK=13, RBRACK=14, DOT=15, COMMA=16, ASSIGN=17, 
		SEMI=18, IF=19, ELSE=20, FOR=21, WHILE=22, DO=23, Declare=24, Type=25, 
		Int=26, Float=27, String=28, Boolean=29, VarName=30;
	public static final int
		RULE_start = 0, RULE_scope = 1, RULE_expressionList = 2, RULE_expression = 3, 
		RULE_loopExpression = 4, RULE_condExpression = 5, RULE_varRefExpression = 6, 
		RULE_varDeclaration = 7, RULE_valueList = 8, RULE_value = 9, RULE_var = 10, 
		RULE_literal = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "scope", "expressionList", "expression", "loopExpression", "condExpression", 
			"varRefExpression", "varDeclaration", "valueList", "value", "var", "literal"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, "'('", 
			"')'", "'{'", "'}'", "'.'", "','", null, "':'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NEXT", "NL", "WS", "MUL", "DIV", "ADD", "SUB", "LESS", "EQUAL", 
			"GREATER", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "DOT", "COMMA", "ASSIGN", 
			"SEMI", "IF", "ELSE", "FOR", "WHILE", "DO", "Declare", "Type", "Int", 
			"Float", "String", "Boolean", "VarName"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "CSParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


	    OperatorType type;

	public CSParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ValueList* result;
		public ExpressionListContext expressionList;
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public TerminalNode EOF() { return getToken(CSParser.EOF, 0); }
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			((StartContext)_localctx).expressionList = expressionList();
			setState(25);
			match(EOF);
			 ((StartContext)_localctx).result =  ((StartContext)_localctx).expressionList.result; 
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScopeContext extends ParserRuleContext {
		public Scope* result;
		public ExpressionListContext expressionList;
		public ExpressionContext expression;
		public TerminalNode LBRACK() { return getToken(CSParser.LBRACK, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public TerminalNode RBRACK() { return getToken(CSParser.RBRACK, 0); }
		public List<TerminalNode> NEXT() { return getTokens(CSParser.NEXT); }
		public TerminalNode NEXT(int i) {
			return getToken(CSParser.NEXT, i);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ScopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scope; }
	}

	public final ScopeContext scope() throws RecognitionException {
		ScopeContext _localctx = new ScopeContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_scope);
		int _la;
		try {
			setState(45);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(28);
				match(LBRACK);
				setState(29);
				((ScopeContext)_localctx).expressionList = expressionList();
				setState(30);
				match(RBRACK);
				 ((ScopeContext)_localctx).result =  new Scope(((ScopeContext)_localctx).expressionList.result); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(33);
				match(LBRACK);
				setState(37);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==NEXT) {
					{
					{
					setState(34);
					match(NEXT);
					}
					}
					setState(39);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(40);
				match(RBRACK);
				 ((ScopeContext)_localctx).result =  new Scope(nullptr); 
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(42);
				((ScopeContext)_localctx).expression = expression();
				 ((ScopeContext)_localctx).result =  new Scope(((ScopeContext)_localctx).expression.result); 
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionListContext extends ParserRuleContext {
		public ValueList* result = new ValueList();
		public ExpressionContext v1;
		public ExpressionContext v;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> NEXT() { return getTokens(CSParser.NEXT); }
		public TerminalNode NEXT(int i) {
			return getToken(CSParser.NEXT, i);
		}
		public ExpressionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionList; }
	}

	public final ExpressionListContext expressionList() throws RecognitionException {
		ExpressionListContext _localctx = new ExpressionListContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_expressionList);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NEXT) {
				{
				setState(47);
				match(NEXT);
				}
			}

			setState(50);
			((ExpressionListContext)_localctx).v1 = expression();
			 _localctx.result->push(((ExpressionListContext)_localctx).v1.result); 
			setState(62);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(53); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(52);
						match(NEXT);
						}
						}
						setState(55); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==NEXT );
					setState(57);
					((ExpressionListContext)_localctx).v = expression();
					 _localctx.result->push(((ExpressionListContext)_localctx).v.result); 
					}
					} 
				}
				setState(64);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			setState(66);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NEXT) {
				{
				setState(65);
				match(NEXT);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public NodeRef result;
		public VarRefExpressionContext varRefExpression;
		public CondExpressionContext condExpression;
		public LoopExpressionContext loopExpression;
		public VarRefExpressionContext varRefExpression() {
			return getRuleContext(VarRefExpressionContext.class,0);
		}
		public CondExpressionContext condExpression() {
			return getRuleContext(CondExpressionContext.class,0);
		}
		public LoopExpressionContext loopExpression() {
			return getRuleContext(LoopExpressionContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_expression);
		try {
			setState(77);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Declare:
			case Int:
			case Float:
			case String:
			case VarName:
				enterOuterAlt(_localctx, 1);
				{
				setState(68);
				((ExpressionContext)_localctx).varRefExpression = varRefExpression(0);
				 ((ExpressionContext)_localctx).result =  ((ExpressionContext)_localctx).varRefExpression.result; 
				}
				break;
			case IF:
				enterOuterAlt(_localctx, 2);
				{
				setState(71);
				((ExpressionContext)_localctx).condExpression = condExpression();
				 ((ExpressionContext)_localctx).result =  ((ExpressionContext)_localctx).condExpression.result; 
				}
				break;
			case FOR:
			case WHILE:
			case DO:
				enterOuterAlt(_localctx, 3);
				{
				setState(74);
				((ExpressionContext)_localctx).loopExpression = loopExpression();
				 ((ExpressionContext)_localctx).result =  ((ExpressionContext)_localctx).loopExpression.result; 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LoopExpressionContext extends ParserRuleContext {
		public Loop* result;
		public Scope* elseCond = nullptr;;
		public ValueContext value;
		public ScopeContext body;
		public ScopeContext falsed;
		public TerminalNode WHILE() { return getToken(CSParser.WHILE, 0); }
		public TerminalNode LPAREN() { return getToken(CSParser.LPAREN, 0); }
		public List<ValueContext> value() {
			return getRuleContexts(ValueContext.class);
		}
		public ValueContext value(int i) {
			return getRuleContext(ValueContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(CSParser.RPAREN, 0); }
		public List<ScopeContext> scope() {
			return getRuleContexts(ScopeContext.class);
		}
		public ScopeContext scope(int i) {
			return getRuleContext(ScopeContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(CSParser.ELSE, 0); }
		public TerminalNode DO() { return getToken(CSParser.DO, 0); }
		public TerminalNode FOR() { return getToken(CSParser.FOR, 0); }
		public LoopExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loopExpression; }
	}

	public final LoopExpressionContext loopExpression() throws RecognitionException {
		LoopExpressionContext _localctx = new LoopExpressionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_loopExpression);
		try {
			setState(120);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case WHILE:
				enterOuterAlt(_localctx, 1);
				{
				setState(79);
				match(WHILE);
				setState(80);
				match(LPAREN);
				setState(81);
				((LoopExpressionContext)_localctx).value = value(0);
				setState(82);
				match(RPAREN);
				setState(83);
				((LoopExpressionContext)_localctx).body = scope();
				setState(88);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
				case 1:
					{
					setState(84);
					match(ELSE);
					setState(85);
					((LoopExpressionContext)_localctx).falsed = scope();
					((LoopExpressionContext)_localctx).elseCond =  ((LoopExpressionContext)_localctx).falsed.result;
					}
					break;
				}
				 ((LoopExpressionContext)_localctx).result =  new WhileLoop(((LoopExpressionContext)_localctx).value.result, ((LoopExpressionContext)_localctx).body.result, _localctx.elseCond); 
				}
				break;
			case DO:
				enterOuterAlt(_localctx, 2);
				{
				setState(92);
				match(DO);
				setState(93);
				((LoopExpressionContext)_localctx).body = scope();
				setState(94);
				match(WHILE);
				setState(95);
				match(LPAREN);
				setState(96);
				((LoopExpressionContext)_localctx).value = value(0);
				setState(97);
				match(RPAREN);
				setState(102);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
				case 1:
					{
					setState(98);
					match(ELSE);
					setState(99);
					((LoopExpressionContext)_localctx).falsed = scope();
					((LoopExpressionContext)_localctx).elseCond =  ((LoopExpressionContext)_localctx).falsed.result;
					}
					break;
				}
				 ((LoopExpressionContext)_localctx).result =  new DoWhileLoop(((LoopExpressionContext)_localctx).value.result, ((LoopExpressionContext)_localctx).body.result, _localctx.elseCond); 
				}
				break;
			case FOR:
				enterOuterAlt(_localctx, 3);
				{
				setState(106);
				match(FOR);
				setState(107);
				((LoopExpressionContext)_localctx).value = value(0);
				setState(108);
				match(LPAREN);
				setState(109);
				((LoopExpressionContext)_localctx).value = value(0);
				setState(110);
				match(RPAREN);
				setState(111);
				((LoopExpressionContext)_localctx).body = scope();
				setState(116);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
				case 1:
					{
					setState(112);
					match(ELSE);
					setState(113);
					((LoopExpressionContext)_localctx).falsed = scope();
					((LoopExpressionContext)_localctx).elseCond =  ((LoopExpressionContext)_localctx).falsed.result;
					}
					break;
				}
				 ((LoopExpressionContext)_localctx).result =  new ForLoop(((LoopExpressionContext)_localctx).value.result, ((LoopExpressionContext)_localctx).body.result, _localctx.elseCond); 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CondExpressionContext extends ParserRuleContext {
		public Condition* result;
		public Scope* elseCond = nullptr;;
		public ValueContext value;
		public ScopeContext trued;
		public ScopeContext falsed;
		public TerminalNode IF() { return getToken(CSParser.IF, 0); }
		public TerminalNode LPAREN() { return getToken(CSParser.LPAREN, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(CSParser.RPAREN, 0); }
		public List<ScopeContext> scope() {
			return getRuleContexts(ScopeContext.class);
		}
		public ScopeContext scope(int i) {
			return getRuleContext(ScopeContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(CSParser.ELSE, 0); }
		public CondExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_condExpression; }
	}

	public final CondExpressionContext condExpression() throws RecognitionException {
		CondExpressionContext _localctx = new CondExpressionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_condExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(122);
			match(IF);
			setState(123);
			match(LPAREN);
			setState(124);
			((CondExpressionContext)_localctx).value = value(0);
			setState(125);
			match(RPAREN);
			setState(126);
			((CondExpressionContext)_localctx).trued = scope();
			setState(131);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(127);
				match(ELSE);
				setState(128);
				((CondExpressionContext)_localctx).falsed = scope();
				((CondExpressionContext)_localctx).elseCond =  ((CondExpressionContext)_localctx).falsed.result;
				}
				break;
			}
			 ((CondExpressionContext)_localctx).result =  new Condition(((CondExpressionContext)_localctx).value.result, ((CondExpressionContext)_localctx).trued.result, _localctx.elseCond); 
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarRefExpressionContext extends ParserRuleContext {
		public NodeRef result;
		public VarRefExpressionContext v1;
		public Token VarName;
		public ValueListContext valueList;
		public VarDeclarationContext varDeclaration;
		public ValueContext value;
		public VarRefExpressionContext v2;
		public TerminalNode VarName() { return getToken(CSParser.VarName, 0); }
		public TerminalNode LPAREN() { return getToken(CSParser.LPAREN, 0); }
		public ValueListContext valueList() {
			return getRuleContext(ValueListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(CSParser.RPAREN, 0); }
		public VarDeclarationContext varDeclaration() {
			return getRuleContext(VarDeclarationContext.class,0);
		}
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(CSParser.ASSIGN, 0); }
		public List<VarRefExpressionContext> varRefExpression() {
			return getRuleContexts(VarRefExpressionContext.class);
		}
		public VarRefExpressionContext varRefExpression(int i) {
			return getRuleContext(VarRefExpressionContext.class,i);
		}
		public VarRefExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varRefExpression; }
	}

	public final VarRefExpressionContext varRefExpression() throws RecognitionException {
		return varRefExpression(0);
	}

	private VarRefExpressionContext varRefExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		VarRefExpressionContext _localctx = new VarRefExpressionContext(_ctx, _parentState);
		VarRefExpressionContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_varRefExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(148);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				{
				setState(136);
				((VarRefExpressionContext)_localctx).VarName = match(VarName);
				setState(137);
				match(LPAREN);
				setState(138);
				((VarRefExpressionContext)_localctx).valueList = valueList(0);
				setState(139);
				match(RPAREN);
				 ((VarRefExpressionContext)_localctx).result =  new FunctionCall(new Function((((VarRefExpressionContext)_localctx).VarName!=null?((VarRefExpressionContext)_localctx).VarName.getText():null)), ((VarRefExpressionContext)_localctx).valueList.result); 
				}
				break;
			case 2:
				{
				setState(142);
				((VarRefExpressionContext)_localctx).varDeclaration = varDeclaration();
				 ((VarRefExpressionContext)_localctx).result =  ((VarRefExpressionContext)_localctx).varDeclaration.result; 
				}
				break;
			case 3:
				{
				setState(145);
				((VarRefExpressionContext)_localctx).value = value(0);
				 ((VarRefExpressionContext)_localctx).result =  ((VarRefExpressionContext)_localctx).value.result; 
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(157);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new VarRefExpressionContext(_parentctx, _parentState);
					_localctx.v1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_varRefExpression);
					setState(150);
					if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
					setState(151);
					match(ASSIGN);
					setState(152);
					((VarRefExpressionContext)_localctx).v2 = varRefExpression(4);
					 ((VarRefExpressionContext)_localctx).result =  new Assignation(((VarRefExpressionContext)_localctx).v1.result, ((VarRefExpressionContext)_localctx).v2.result); 
					}
					} 
				}
				setState(159);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarDeclarationContext extends ParserRuleContext {
		public Declaration* result;
		public Token Declare;
		public VarContext var;
		public Token Type;
		public TerminalNode Declare() { return getToken(CSParser.Declare, 0); }
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(CSParser.SEMI, 0); }
		public TerminalNode Type() { return getToken(CSParser.Type, 0); }
		public VarDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDeclaration; }
	}

	public final VarDeclarationContext varDeclaration() throws RecognitionException {
		VarDeclarationContext _localctx = new VarDeclarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_varDeclaration);
		try {
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(160);
				((VarDeclarationContext)_localctx).Declare = match(Declare);
				setState(161);
				((VarDeclarationContext)_localctx).var = var();
				setState(162);
				match(SEMI);
				setState(163);
				((VarDeclarationContext)_localctx).Type = match(Type);
				 ((VarDeclarationContext)_localctx).result =  new Declaration(((VarDeclarationContext)_localctx).var.result, (((VarDeclarationContext)_localctx).Declare!=null?((VarDeclarationContext)_localctx).Declare.getText():null), (((VarDeclarationContext)_localctx).Type!=null?((VarDeclarationContext)_localctx).Type.getText():null)); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(166);
				((VarDeclarationContext)_localctx).Declare = match(Declare);
				setState(167);
				((VarDeclarationContext)_localctx).var = var();
				 ((VarDeclarationContext)_localctx).result =  new Declaration(((VarDeclarationContext)_localctx).var.result, (((VarDeclarationContext)_localctx).Declare!=null?((VarDeclarationContext)_localctx).Declare.getText():null)); 
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ValueListContext extends ParserRuleContext {
		public ValueList* result;
		public ValueListContext v1;
		public ValueContext value;
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(CSParser.COMMA, 0); }
		public ValueListContext valueList() {
			return getRuleContext(ValueListContext.class,0);
		}
		public ValueListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_valueList; }
	}

	public final ValueListContext valueList() throws RecognitionException {
		return valueList(0);
	}

	private ValueListContext valueList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ValueListContext _localctx = new ValueListContext(_ctx, _parentState);
		ValueListContext _prevctx = _localctx;
		int _startState = 16;
		enterRecursionRule(_localctx, 16, RULE_valueList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(173);
			((ValueListContext)_localctx).value = value(0);
			 ((ValueListContext)_localctx).result =  new ValueList(((ValueListContext)_localctx).value.result); 
			}
			_ctx.stop = _input.LT(-1);
			setState(183);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ValueListContext(_parentctx, _parentState);
					_localctx.v1 = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_valueList);
					setState(176);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(177);
					match(COMMA);
					setState(178);
					((ValueListContext)_localctx).value = value(0);
					 ((ValueListContext)_localctx).result =  ((ValueListContext)_localctx).v1.result; _localctx.result->push(((ValueListContext)_localctx).value.result); 
					}
					} 
				}
				setState(185);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ValueContext extends ParserRuleContext {
		public NodeRef result;
		public ValueContext v1;
		public VarContext var;
		public LiteralContext literal;
		public ValueContext v2;
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public List<ValueContext> value() {
			return getRuleContexts(ValueContext.class);
		}
		public ValueContext value(int i) {
			return getRuleContext(ValueContext.class,i);
		}
		public TerminalNode MUL() { return getToken(CSParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(CSParser.DIV, 0); }
		public TerminalNode ADD() { return getToken(CSParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(CSParser.SUB, 0); }
		public TerminalNode GREATER() { return getToken(CSParser.GREATER, 0); }
		public TerminalNode EQUAL() { return getToken(CSParser.EQUAL, 0); }
		public TerminalNode LESS() { return getToken(CSParser.LESS, 0); }
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
	}

	public final ValueContext value() throws RecognitionException {
		return value(0);
	}

	private ValueContext value(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ValueContext _localctx = new ValueContext(_ctx, _parentState);
		ValueContext _prevctx = _localctx;
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_value, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(193);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VarName:
				{
				setState(187);
				((ValueContext)_localctx).var = var();
				 ((ValueContext)_localctx).result =  ((ValueContext)_localctx).var.result; 
				}
				break;
			case Int:
			case Float:
			case String:
				{
				setState(190);
				((ValueContext)_localctx).literal = literal();
				 ((ValueContext)_localctx).result =  ((ValueContext)_localctx).literal.result; 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(229);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(227);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						_localctx = new ValueContext(_parentctx, _parentState);
						_localctx.v1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_value);
						setState(195);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(200);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case MUL:
							{
							setState(196);
							match(MUL);
							type = OperatorType::MUL;
							}
							break;
						case DIV:
							{
							setState(198);
							match(DIV);
							type = OperatorType::DIV;
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						setState(202);
						((ValueContext)_localctx).v2 = value(6);
						 ((ValueContext)_localctx).result =  new Operator(type, ((ValueContext)_localctx).v1.result, ((ValueContext)_localctx).v2.result); 
						}
						break;
					case 2:
						{
						_localctx = new ValueContext(_parentctx, _parentState);
						_localctx.v1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_value);
						setState(205);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(210);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case ADD:
							{
							setState(206);
							match(ADD);
							type = OperatorType::ADD;
							}
							break;
						case SUB:
							{
							setState(208);
							match(SUB);
							type = OperatorType::SUB;
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						setState(212);
						((ValueContext)_localctx).v2 = value(5);
						 ((ValueContext)_localctx).result =  new Operator(type, ((ValueContext)_localctx).v1.result, ((ValueContext)_localctx).v2.result); 
						}
						break;
					case 3:
						{
						_localctx = new ValueContext(_parentctx, _parentState);
						_localctx.v1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_value);
						setState(215);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(222);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case GREATER:
							{
							setState(216);
							match(GREATER);
							type = OperatorType::GREATER;
							}
							break;
						case EQUAL:
							{
							setState(218);
							match(EQUAL);
							type = OperatorType::EQUAL;
							}
							break;
						case LESS:
							{
							setState(220);
							match(LESS);
							type = OperatorType::LESS;
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						setState(224);
						((ValueContext)_localctx).v2 = value(4);
						 ((ValueContext)_localctx).result =  new Operator(type, ((ValueContext)_localctx).v1.result, ((ValueContext)_localctx).v2.result); 
						}
						break;
					}
					} 
				}
				setState(231);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarContext extends ParserRuleContext {
		public Variable* result;
		public Token VarName;
		public TerminalNode VarName() { return getToken(CSParser.VarName, 0); }
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_var);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(232);
			((VarContext)_localctx).VarName = match(VarName);
			 ((VarContext)_localctx).result =  new Variable((((VarContext)_localctx).VarName!=null?((VarContext)_localctx).VarName.getText():null)); 
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LiteralContext extends ParserRuleContext {
		public ValueBase* result;
		public Token Int;
		public Token Float;
		public Token String;
		public TerminalNode Int() { return getToken(CSParser.Int, 0); }
		public TerminalNode Float() { return getToken(CSParser.Float, 0); }
		public TerminalNode String() { return getToken(CSParser.String, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_literal);
		try {
			setState(241);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Int:
				enterOuterAlt(_localctx, 1);
				{
				setState(235);
				((LiteralContext)_localctx).Int = match(Int);
				 ((LiteralContext)_localctx).result =  new syntax::Int(std::stoi((((LiteralContext)_localctx).Int!=null?((LiteralContext)_localctx).Int.getText():null))); 
				}
				break;
			case Float:
				enterOuterAlt(_localctx, 2);
				{
				setState(237);
				((LiteralContext)_localctx).Float = match(Float);
				 ((LiteralContext)_localctx).result =  new syntax::Float(std::stod((((LiteralContext)_localctx).Float!=null?((LiteralContext)_localctx).Float.getText():null))); 
				}
				break;
			case String:
				enterOuterAlt(_localctx, 3);
				{
				setState(239);
				((LiteralContext)_localctx).String = match(String);
				 ((LiteralContext)_localctx).result =  new syntax::String((((LiteralContext)_localctx).String!=null?((LiteralContext)_localctx).String.getText():null)); 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return varRefExpression_sempred((VarRefExpressionContext)_localctx, predIndex);
		case 8:
			return valueList_sempred((ValueListContext)_localctx, predIndex);
		case 9:
			return value_sempred((ValueContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean varRefExpression_sempred(VarRefExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 4);
		}
		return true;
	}
	private boolean valueList_sempred(ValueListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean value_sempred(ValueContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u001e\u00f4\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001"+
		"$\b\u0001\n\u0001\f\u0001\'\t\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u0001.\b\u0001\u0001\u0002\u0003\u0002"+
		"1\b\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0004\u00026\b\u0002\u000b"+
		"\u0002\f\u00027\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002=\b\u0002"+
		"\n\u0002\f\u0002@\t\u0002\u0001\u0002\u0003\u0002C\b\u0002\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0003\u0003N\b\u0003\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0003\u0004Y\b\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004g\b\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004"+
		"u\b\u0004\u0001\u0004\u0001\u0004\u0003\u0004y\b\u0004\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0003\u0005\u0084\b\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0003\u0006\u0095\b\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0005\u0006\u009c\b\u0006\n\u0006\f\u0006\u009f\t\u0006"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u00ab\b\u0007"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0005\b\u00b6\b\b\n\b\f\b\u00b9\t\b\u0001\t\u0001\t\u0001\t\u0001\t"+
		"\u0001\t\u0001\t\u0001\t\u0003\t\u00c2\b\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0003\t\u00c9\b\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0003\t\u00d3\b\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u00df\b\t\u0001\t\u0001"+
		"\t\u0001\t\u0005\t\u00e4\b\t\n\t\f\t\u00e7\t\t\u0001\n\u0001\n\u0001\n"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000b\u00f2\b\u000b\u0001\u000b\u0000\u0003\f\u0010\u0012\f\u0000"+
		"\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0000\u0000\u0105"+
		"\u0000\u0018\u0001\u0000\u0000\u0000\u0002-\u0001\u0000\u0000\u0000\u0004"+
		"0\u0001\u0000\u0000\u0000\u0006M\u0001\u0000\u0000\u0000\bx\u0001\u0000"+
		"\u0000\u0000\nz\u0001\u0000\u0000\u0000\f\u0094\u0001\u0000\u0000\u0000"+
		"\u000e\u00aa\u0001\u0000\u0000\u0000\u0010\u00ac\u0001\u0000\u0000\u0000"+
		"\u0012\u00c1\u0001\u0000\u0000\u0000\u0014\u00e8\u0001\u0000\u0000\u0000"+
		"\u0016\u00f1\u0001\u0000\u0000\u0000\u0018\u0019\u0003\u0004\u0002\u0000"+
		"\u0019\u001a\u0005\u0000\u0000\u0001\u001a\u001b\u0006\u0000\uffff\uffff"+
		"\u0000\u001b\u0001\u0001\u0000\u0000\u0000\u001c\u001d\u0005\r\u0000\u0000"+
		"\u001d\u001e\u0003\u0004\u0002\u0000\u001e\u001f\u0005\u000e\u0000\u0000"+
		"\u001f \u0006\u0001\uffff\uffff\u0000 .\u0001\u0000\u0000\u0000!%\u0005"+
		"\r\u0000\u0000\"$\u0005\u0001\u0000\u0000#\"\u0001\u0000\u0000\u0000$"+
		"\'\u0001\u0000\u0000\u0000%#\u0001\u0000\u0000\u0000%&\u0001\u0000\u0000"+
		"\u0000&(\u0001\u0000\u0000\u0000\'%\u0001\u0000\u0000\u0000()\u0005\u000e"+
		"\u0000\u0000).\u0006\u0001\uffff\uffff\u0000*+\u0003\u0006\u0003\u0000"+
		"+,\u0006\u0001\uffff\uffff\u0000,.\u0001\u0000\u0000\u0000-\u001c\u0001"+
		"\u0000\u0000\u0000-!\u0001\u0000\u0000\u0000-*\u0001\u0000\u0000\u0000"+
		".\u0003\u0001\u0000\u0000\u0000/1\u0005\u0001\u0000\u00000/\u0001\u0000"+
		"\u0000\u000001\u0001\u0000\u0000\u000012\u0001\u0000\u0000\u000023\u0003"+
		"\u0006\u0003\u00003>\u0006\u0002\uffff\uffff\u000046\u0005\u0001\u0000"+
		"\u000054\u0001\u0000\u0000\u000067\u0001\u0000\u0000\u000075\u0001\u0000"+
		"\u0000\u000078\u0001\u0000\u0000\u000089\u0001\u0000\u0000\u00009:\u0003"+
		"\u0006\u0003\u0000:;\u0006\u0002\uffff\uffff\u0000;=\u0001\u0000\u0000"+
		"\u0000<5\u0001\u0000\u0000\u0000=@\u0001\u0000\u0000\u0000><\u0001\u0000"+
		"\u0000\u0000>?\u0001\u0000\u0000\u0000?B\u0001\u0000\u0000\u0000@>\u0001"+
		"\u0000\u0000\u0000AC\u0005\u0001\u0000\u0000BA\u0001\u0000\u0000\u0000"+
		"BC\u0001\u0000\u0000\u0000C\u0005\u0001\u0000\u0000\u0000DE\u0003\f\u0006"+
		"\u0000EF\u0006\u0003\uffff\uffff\u0000FN\u0001\u0000\u0000\u0000GH\u0003"+
		"\n\u0005\u0000HI\u0006\u0003\uffff\uffff\u0000IN\u0001\u0000\u0000\u0000"+
		"JK\u0003\b\u0004\u0000KL\u0006\u0003\uffff\uffff\u0000LN\u0001\u0000\u0000"+
		"\u0000MD\u0001\u0000\u0000\u0000MG\u0001\u0000\u0000\u0000MJ\u0001\u0000"+
		"\u0000\u0000N\u0007\u0001\u0000\u0000\u0000OP\u0005\u0016\u0000\u0000"+
		"PQ\u0005\u000b\u0000\u0000QR\u0003\u0012\t\u0000RS\u0005\f\u0000\u0000"+
		"SX\u0003\u0002\u0001\u0000TU\u0005\u0014\u0000\u0000UV\u0003\u0002\u0001"+
		"\u0000VW\u0006\u0004\uffff\uffff\u0000WY\u0001\u0000\u0000\u0000XT\u0001"+
		"\u0000\u0000\u0000XY\u0001\u0000\u0000\u0000YZ\u0001\u0000\u0000\u0000"+
		"Z[\u0006\u0004\uffff\uffff\u0000[y\u0001\u0000\u0000\u0000\\]\u0005\u0017"+
		"\u0000\u0000]^\u0003\u0002\u0001\u0000^_\u0005\u0016\u0000\u0000_`\u0005"+
		"\u000b\u0000\u0000`a\u0003\u0012\t\u0000af\u0005\f\u0000\u0000bc\u0005"+
		"\u0014\u0000\u0000cd\u0003\u0002\u0001\u0000de\u0006\u0004\uffff\uffff"+
		"\u0000eg\u0001\u0000\u0000\u0000fb\u0001\u0000\u0000\u0000fg\u0001\u0000"+
		"\u0000\u0000gh\u0001\u0000\u0000\u0000hi\u0006\u0004\uffff\uffff\u0000"+
		"iy\u0001\u0000\u0000\u0000jk\u0005\u0015\u0000\u0000kl\u0003\u0012\t\u0000"+
		"lm\u0005\u000b\u0000\u0000mn\u0003\u0012\t\u0000no\u0005\f\u0000\u0000"+
		"ot\u0003\u0002\u0001\u0000pq\u0005\u0014\u0000\u0000qr\u0003\u0002\u0001"+
		"\u0000rs\u0006\u0004\uffff\uffff\u0000su\u0001\u0000\u0000\u0000tp\u0001"+
		"\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000uv\u0001\u0000\u0000\u0000"+
		"vw\u0006\u0004\uffff\uffff\u0000wy\u0001\u0000\u0000\u0000xO\u0001\u0000"+
		"\u0000\u0000x\\\u0001\u0000\u0000\u0000xj\u0001\u0000\u0000\u0000y\t\u0001"+
		"\u0000\u0000\u0000z{\u0005\u0013\u0000\u0000{|\u0005\u000b\u0000\u0000"+
		"|}\u0003\u0012\t\u0000}~\u0005\f\u0000\u0000~\u0083\u0003\u0002\u0001"+
		"\u0000\u007f\u0080\u0005\u0014\u0000\u0000\u0080\u0081\u0003\u0002\u0001"+
		"\u0000\u0081\u0082\u0006\u0005\uffff\uffff\u0000\u0082\u0084\u0001\u0000"+
		"\u0000\u0000\u0083\u007f\u0001\u0000\u0000\u0000\u0083\u0084\u0001\u0000"+
		"\u0000\u0000\u0084\u0085\u0001\u0000\u0000\u0000\u0085\u0086\u0006\u0005"+
		"\uffff\uffff\u0000\u0086\u000b\u0001\u0000\u0000\u0000\u0087\u0088\u0006"+
		"\u0006\uffff\uffff\u0000\u0088\u0089\u0005\u001e\u0000\u0000\u0089\u008a"+
		"\u0005\u000b\u0000\u0000\u008a\u008b\u0003\u0010\b\u0000\u008b\u008c\u0005"+
		"\f\u0000\u0000\u008c\u008d\u0006\u0006\uffff\uffff\u0000\u008d\u0095\u0001"+
		"\u0000\u0000\u0000\u008e\u008f\u0003\u000e\u0007\u0000\u008f\u0090\u0006"+
		"\u0006\uffff\uffff\u0000\u0090\u0095\u0001\u0000\u0000\u0000\u0091\u0092"+
		"\u0003\u0012\t\u0000\u0092\u0093\u0006\u0006\uffff\uffff\u0000\u0093\u0095"+
		"\u0001\u0000\u0000\u0000\u0094\u0087\u0001\u0000\u0000\u0000\u0094\u008e"+
		"\u0001\u0000\u0000\u0000\u0094\u0091\u0001\u0000\u0000\u0000\u0095\u009d"+
		"\u0001\u0000\u0000\u0000\u0096\u0097\n\u0004\u0000\u0000\u0097\u0098\u0005"+
		"\u0011\u0000\u0000\u0098\u0099\u0003\f\u0006\u0004\u0099\u009a\u0006\u0006"+
		"\uffff\uffff\u0000\u009a\u009c\u0001\u0000\u0000\u0000\u009b\u0096\u0001"+
		"\u0000\u0000\u0000\u009c\u009f\u0001\u0000\u0000\u0000\u009d\u009b\u0001"+
		"\u0000\u0000\u0000\u009d\u009e\u0001\u0000\u0000\u0000\u009e\r\u0001\u0000"+
		"\u0000\u0000\u009f\u009d\u0001\u0000\u0000\u0000\u00a0\u00a1\u0005\u0018"+
		"\u0000\u0000\u00a1\u00a2\u0003\u0014\n\u0000\u00a2\u00a3\u0005\u0012\u0000"+
		"\u0000\u00a3\u00a4\u0005\u0019\u0000\u0000\u00a4\u00a5\u0006\u0007\uffff"+
		"\uffff\u0000\u00a5\u00ab\u0001\u0000\u0000\u0000\u00a6\u00a7\u0005\u0018"+
		"\u0000\u0000\u00a7\u00a8\u0003\u0014\n\u0000\u00a8\u00a9\u0006\u0007\uffff"+
		"\uffff\u0000\u00a9\u00ab\u0001\u0000\u0000\u0000\u00aa\u00a0\u0001\u0000"+
		"\u0000\u0000\u00aa\u00a6\u0001\u0000\u0000\u0000\u00ab\u000f\u0001\u0000"+
		"\u0000\u0000\u00ac\u00ad\u0006\b\uffff\uffff\u0000\u00ad\u00ae\u0003\u0012"+
		"\t\u0000\u00ae\u00af\u0006\b\uffff\uffff\u0000\u00af\u00b7\u0001\u0000"+
		"\u0000\u0000\u00b0\u00b1\n\u0002\u0000\u0000\u00b1\u00b2\u0005\u0010\u0000"+
		"\u0000\u00b2\u00b3\u0003\u0012\t\u0000\u00b3\u00b4\u0006\b\uffff\uffff"+
		"\u0000\u00b4\u00b6\u0001\u0000\u0000\u0000\u00b5\u00b0\u0001\u0000\u0000"+
		"\u0000\u00b6\u00b9\u0001\u0000\u0000\u0000\u00b7\u00b5\u0001\u0000\u0000"+
		"\u0000\u00b7\u00b8\u0001\u0000\u0000\u0000\u00b8\u0011\u0001\u0000\u0000"+
		"\u0000\u00b9\u00b7\u0001\u0000\u0000\u0000\u00ba\u00bb\u0006\t\uffff\uffff"+
		"\u0000\u00bb\u00bc\u0003\u0014\n\u0000\u00bc\u00bd\u0006\t\uffff\uffff"+
		"\u0000\u00bd\u00c2\u0001\u0000\u0000\u0000\u00be\u00bf\u0003\u0016\u000b"+
		"\u0000\u00bf\u00c0\u0006\t\uffff\uffff\u0000\u00c0\u00c2\u0001\u0000\u0000"+
		"\u0000\u00c1\u00ba\u0001\u0000\u0000\u0000\u00c1\u00be\u0001\u0000\u0000"+
		"\u0000\u00c2\u00e5\u0001\u0000\u0000\u0000\u00c3\u00c8\n\u0005\u0000\u0000"+
		"\u00c4\u00c5\u0005\u0004\u0000\u0000\u00c5\u00c9\u0006\t\uffff\uffff\u0000"+
		"\u00c6\u00c7\u0005\u0005\u0000\u0000\u00c7\u00c9\u0006\t\uffff\uffff\u0000"+
		"\u00c8\u00c4\u0001\u0000\u0000\u0000\u00c8\u00c6\u0001\u0000\u0000\u0000"+
		"\u00c9\u00ca\u0001\u0000\u0000\u0000\u00ca\u00cb\u0003\u0012\t\u0006\u00cb"+
		"\u00cc\u0006\t\uffff\uffff\u0000\u00cc\u00e4\u0001\u0000\u0000\u0000\u00cd"+
		"\u00d2\n\u0004\u0000\u0000\u00ce\u00cf\u0005\u0006\u0000\u0000\u00cf\u00d3"+
		"\u0006\t\uffff\uffff\u0000\u00d0\u00d1\u0005\u0007\u0000\u0000\u00d1\u00d3"+
		"\u0006\t\uffff\uffff\u0000\u00d2\u00ce\u0001\u0000\u0000\u0000\u00d2\u00d0"+
		"\u0001\u0000\u0000\u0000\u00d3\u00d4\u0001\u0000\u0000\u0000\u00d4\u00d5"+
		"\u0003\u0012\t\u0005\u00d5\u00d6\u0006\t\uffff\uffff\u0000\u00d6\u00e4"+
		"\u0001\u0000\u0000\u0000\u00d7\u00de\n\u0003\u0000\u0000\u00d8\u00d9\u0005"+
		"\n\u0000\u0000\u00d9\u00df\u0006\t\uffff\uffff\u0000\u00da\u00db\u0005"+
		"\t\u0000\u0000\u00db\u00df\u0006\t\uffff\uffff\u0000\u00dc\u00dd\u0005"+
		"\b\u0000\u0000\u00dd\u00df\u0006\t\uffff\uffff\u0000\u00de\u00d8\u0001"+
		"\u0000\u0000\u0000\u00de\u00da\u0001\u0000\u0000\u0000\u00de\u00dc\u0001"+
		"\u0000\u0000\u0000\u00df\u00e0\u0001\u0000\u0000\u0000\u00e0\u00e1\u0003"+
		"\u0012\t\u0004\u00e1\u00e2\u0006\t\uffff\uffff\u0000\u00e2\u00e4\u0001"+
		"\u0000\u0000\u0000\u00e3\u00c3\u0001\u0000\u0000\u0000\u00e3\u00cd\u0001"+
		"\u0000\u0000\u0000\u00e3\u00d7\u0001\u0000\u0000\u0000\u00e4\u00e7\u0001"+
		"\u0000\u0000\u0000\u00e5\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e6\u0001"+
		"\u0000\u0000\u0000\u00e6\u0013\u0001\u0000\u0000\u0000\u00e7\u00e5\u0001"+
		"\u0000\u0000\u0000\u00e8\u00e9\u0005\u001e\u0000\u0000\u00e9\u00ea\u0006"+
		"\n\uffff\uffff\u0000\u00ea\u0015\u0001\u0000\u0000\u0000\u00eb\u00ec\u0005"+
		"\u001a\u0000\u0000\u00ec\u00f2\u0006\u000b\uffff\uffff\u0000\u00ed\u00ee"+
		"\u0005\u001b\u0000\u0000\u00ee\u00f2\u0006\u000b\uffff\uffff\u0000\u00ef"+
		"\u00f0\u0005\u001c\u0000\u0000\u00f0\u00f2\u0006\u000b\uffff\uffff\u0000"+
		"\u00f1\u00eb\u0001\u0000\u0000\u0000\u00f1\u00ed\u0001\u0000\u0000\u0000"+
		"\u00f1\u00ef\u0001\u0000\u0000\u0000\u00f2\u0017\u0001\u0000\u0000\u0000"+
		"\u0017%-07>BMXftx\u0083\u0094\u009d\u00aa\u00b7\u00c1\u00c8\u00d2\u00de"+
		"\u00e3\u00e5\u00f1";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}