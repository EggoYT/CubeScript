lexer grammar CSLexer;

NEXT : NL | ';' ;
NL: WS? '\r'? '\n' WS? ;
WS: [ \t\f]+ -> skip ;

//ARITHMETIC
MUL : NL* '*' NL*;
DIV : NL* '/' NL*;
ADD : NL* '+' NL*;
SUB : NL* '-' NL*;
LESS : NL* '<' NL*;
EQUAL : NL* '==' NL*;
GREATER : NL* '>' NL*;

//SCOPE
LPAREN : '(' ; 
RPAREN : ')' ;
LBRACK : '{' ;
RBRACK : '}' ;

//OTHER
DOT : '.' ;
COMMA : ',' ;
ASSIGN : NL* '=' NL*;
SEMI : NL* ':' NL* ;

//STATEMENTS
IF : 'if' NL* ;
ELSE : NL* 'else' NL*;
FOR : 'for' NL* ;
WHILE : 'while' NL*;
DO : 'do' NL*;

//LITERALS
Declare : ('var'|'val') NL* ;
Type : 'Int' | 'Float' | 'String' | 'Boolean' ;
Int : [0-9]+ ; 
Float : Int [fF] | Int? '.' Int [fF]? ;
String : '"' ~["]* '"' ;
Boolean : ('true')|('false') ;
VarName : [_a-zA-Z][_a-zA-Z0-9]* ;