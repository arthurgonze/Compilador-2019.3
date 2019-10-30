#ifndef COMPILADOR_2019_3_PARSER_H
#define COMPILADOR_2019_3_PARSER_H

#include <cstdio>
#include "../token.h"
#include "../lexical/analyzer.h"
#include "AST.h"

class Parser
{
    int tok;
    inline int Advance() { return tok = lexical_analyzer_next_token(); }
    void Eat(int t);
    void EatOrSkip(int expected, int *syncSet);
    void Sync (int * syncSet);

    static int programFollowSet[];
    ProgramNode *Program(FunctionListNode *functionList, TypeDeclNode *typeList, VarDeclNode *varList);

    static int programAUXFollowSet[];
    ASTNode *ProgramAUX(TypeNode *type, PointerNode *pointer, TokenNode *id, VarDeclNode *varList);

    static int programListFollowSet[];
    ProgramNode *ProgramList(FunctionListNode *functions, TypeDeclNode *typelist, VarDeclNode *varlist);

    VarStmtNode* VarStmt(VarDeclNode *varList);
    VarStmtNode* VarStmtAux(TokenNode *id, VarDeclNode *varList);

    static int typeDeclFollowSet[];
    TypeDeclNode *TypeDecl(TypeDeclNode *typeListNode);

    static int varDeclFollowSet[];
    VarDeclNode *VarDecl();

    static int idListFollowSet[];
    IdListNode *IdList();
    static int idListAUXFollowSet[];
    IdListNode *IdListAUX();

    static int pointerFollowSet[];
    PointerNode *Pointer();

    static int arrayFollowSet[];
    ArrayNode *Array();

    static int formalListFollowSet[];
    FormalListNode* FormalList();

    static int formalRestFollowSet[];
    FormalListNode* FormalRest();

    static int typeFollowSet[];
    TypeNode *Type();
    TypeNode* TypeAux();

    static int stmtListFollowSet[];
    StmtListNode *StmtList();

    static int stmtListAUXFollowSet[];
    StmtListNode *StmtListAUX();

    static int stmtFollowSet[];
    StmtNode *Stmt();

    static int stmtAUXFollowSet[];
    StmtNode *StmtAUX();

    StmtNode* ElseStmt();

    static int caseBlockFollowSet[];
    CaseBlockNode *CaseBlock();

    static int caseBlockAUXFollowSet[];
    CaseBlockNode *CaseBlockAUX(TokenNode *num);

    static int exprListFollowSet[];
    ExpListNode *ExprList();

    static int exprListTailFollowSet[];
    ExpListNode *ExprListTail();

    static int exprListTailAUXFollowSet[];
    ExpListNode *ExprListTailAUX();

    static int exprAssignFollowSet[];
    ExpNode *ExprAssign();

    static int exprAssignAUXFollowSet[];
    ExpNode *ExprAssignAUX(ExpNode *expr);

    static int exprOrFollowSet[];
    ExpNode *ExprOr();

    static int exprOrAUXFollowSet[];
    ExpNode *ExprOrAUX(ExpNode *expr);

    static int exprAndFollowSet[];
    ExpNode *ExprAnd();

    static int exprAndAUXFollowSet[];
    ExpNode *ExprAndAUX(ExpNode *expr);

    static int exprEqualityFollowSet[];
    ExpNode *ExprEquality();

    static int exprEqualityAUXFollowSet[];
    ExpNode *ExprEqualityAUX(ExpNode *expr);

    static int exprRelationalFollowSet[];
    ExpNode *ExprRelational();

    static int exprRelationalAUXFollowSet[];
    ExpNode *ExprRelationalAUX(ExpNode *expr);

    static int exprAdditiveFollowSet[];
    ExpNode *ExprAdditive();

    static int exprAdditiveAUXFollowSet[];
    ExpNode *ExprAdditiveAUX(ExpNode *expr);

    static int exprMultiplicativeFollowSet[];
    ExpNode *ExprMultiplicative();

    static int exprMultiplicativeAUXFollowSet[];
    ExpNode *ExprMultiplicativeAUX(ExpNode *expr);

    static int exprUnaryFollowSet[];
    ExpNode *ExprUnary();

    static int primaryFollowSet[];
    ExpNode *Primary();

    static int postFixExprAUXFollowSet[];
    ExpNode *PostFixExprAUX(ExpNode *ex);/// +/- PrimaryAux

    static int postFixExprFollowSet[];
    ExpNode *PostFixExpr(TokenNode *id); // +/- PrimaryFAT
public:
    ProgramNode *StartParser();
};

#endif //COMPILADOR_2019_3_PARSER_H
