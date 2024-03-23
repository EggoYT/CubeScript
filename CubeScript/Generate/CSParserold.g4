parser grammar CSParser;
options { tokenVocab=CSLexer; }

@parser::preinclude {
    #include "../Result.h"
    #include "../Nodes/Types.h"
    #include "../Nodes/Variables.h"
    #include "../Nodes/Expressions.h"

    using namespace syntax;
}

@parser::members {
    OperatorType type;
}

start returns [ValueList* result]
    : expressionList EOF { $result = $expressionList.result; }
    ;

scope returns [Scope* result]
    : LBRACK expressionList RBRACK { $result = new Scope($expressionList.result); }
    | LBRACK NEXT* RBRACK { $result = new Scope(nullptr); }
    | expression { $result = new Scope($expression.result); }
    ;

expressions returns [ValueList* result = new ValueList()]
    : <assoc=left> NEXT?
        v1=expression { $result->push($v1.result); }
        (NEXT+ v=expression { $result->push($v.result); })*
        NEXT?
    ;

expression returns [NodeRef result]
    : varRefExpression { $result = $varRefExpression.result; }
    | condExpression { $result = $condExpression.result; }
    | loopExpression { $result = $loopExpression.result; }
    ;

loop returns [Loop* result] locals [Scope* elseCond = nullptr;]
    : WHILE LPAREN value RPAREN body=scope (ELSE falsed=scope {$elseCond = $falsed.result;})? { $result = new WhileLoop($value.result, $body.result, $elseCond); }
    | DO body=scope WHILE LPAREN value RPAREN (ELSE falsed=scope {$elseCond = $falsed.result;})? { $result = new DoWhileLoop($value.result, $body.result, $elseCond); }
    | FOR value LPAREN value RPAREN  body=scope (ELSE falsed=scope {$elseCond = $falsed.result;})? { $result = new ForLoop($value.result, $body.result, $elseCond); }
    ;

condition returns [Condition* result] locals [Scope* elseCond = nullptr;]
    : IF LPAREN value RPAREN trued=scope (ELSE falsed=scope {$elseCond = $falsed.result;})? { $result = new Condition($value.result, $trued.result, $elseCond); }
    ;

varRefExpression returns [NodeRef result] //it means that expression return reference to variable
    : <assoc=right> v1=varRefExpression ASSIGN v2=varRefExpression { $result = new Assignation($v1.result, $v2.result); }
    | VarName LPAREN valueList RPAREN { $result = new FunctionCall(new Function($VarName.text), $valueList.result); }
    | varDeclaration { $result = $varDeclaration.result; }
    | value { $result = $value.result; }
    ;

declaration returns [Declaration* result]
    : Declare var ':' Type { $result = new Declaration($var.result, $Declare.text, $Type.text); }
    | Declare var { $result = new Declaration($var.result, $Declare.text); }
    ;

values returns [ValueList* result]
    : v1=values ',' value { $result = $v1.result; $result->push($value.result); }
    | value { $result = new ValueList($value.result); }
    ;

value returns [NodeRef result]
    : <assoc=left>
        v1=value 
        (
            MUL {type = OperatorType::MUL;} |
            DIV {type = OperatorType::DIV;}) 
        v2=value { $result = new Operator(type, $v1.result, $v2.result); }
    | <assoc=left> 
        v1=value 
        (
            ADD {type = OperatorType::ADD;} |
            SUB {type = OperatorType::SUB;})
        v2=value { $result = new Operator(type, $v1.result, $v2.result); }
    | <assoc=left>
        v1=value
        (
            GREATER {type = OperatorType::GREATER;} |
            EQUAL {type = OperatorType::EQUAL;} |
            LESS {type = OperatorType::LESS;}
        )
        v2=value { $result = new Operator(type, $v1.result, $v2.result); }
    | var { $result = $var.result; }
    | literal { $result = $literal.result; }
    ;

var returns [Variable* result]
    : VarName { $result = new Variable($VarName.text); }
    ;

literal returns [ValueBase* result]
    : Int { $result = new syntax::Int(std::stoi($Int.text)); }
    | Float { $result = new syntax::Float(std::stod($Float.text)); }
    | String { $result = new syntax::String($String.text); }
    ;
