#ifdef __cplusplus
extern "C" {
#endif
#ifndef COMPILADOR_2019_3_TOKEN_H
#define COMPILADOR_2019_3_TOKEN_H
/// TOKEN NAMES
// EOF
#define ENDOFFILE 0
// <
#define LT 1
// <=
#define LE 2
// ==
#define EQ 3
// !=
#define NE 4
// >
#define GT 5
// >=
#define GE 6
// IF
#define IF 7
// BOOL
#define BOOL 8
// ELSE
#define ELSE 9
// ID
#define ID 10
// INT
#define INT 11
// FLOAT
#define FLOAT 12
// ,
#define COMMA 13
// (
#define LPARENT 14
// )
#define RPARENT 15
// =
#define ASSIGN 16
// ;
#define SEMICOLON 17
// WHILE
#define WHILE 18
// [
#define LBRACKET 19
// ]
#define RBRACKET 20
// SWITCH
#define SWITCH 21
// BREAK
#define BREAK 22
// RETURN
#define RETURN 23
// PRINT
#define PRINT 24
// READLN
#define READLN 25
// THROW
#define THROW 26
// TRY
#define TRY 27
// CATCH
#define CATCH 28
// CASE
#define CASE 29
// LITERAL
#define LITERAL 30
// TRUE
#define TRUE 31
// FALSE
#define FALSE 32
// &
#define ADDRESS 33
// *
#define STAR 34
// .
#define DOT 35
// {
#define LBRACE 36
// }
#define RBRACE 37
// !
#define NOT 38
// CHAR
#define CHAR 39
// "
#define QUOTE 40
// '
#define SIMPLEQUOTE 41
// '\'
#define BACKSLASH 42
// :
#define COLON 43
// +
#define PLUS 44
// -
#define MINUS 45
// |
#define PIPE 46
// /
#define SLASH 47
// %
#define PERCENT 48
// &&
#define AND 49
// ||
#define OR 50
// ->
#define POINTER 51
// typedef
#define TYPEDEF 52
// struct
#define STRUCT 53
// NUMINT
#define NUMINT 54
// NUMFLOAT
#define NUMFLOAT 55
// LITERAL CHAR
#define LITERALCHAR 56

/**
 * Convert token numerical IDs to a textual represent
 * @param id Kind of token
 * @return Textual value of token
 */
char const* token_id_to_name(int id) {
    char const * tokens [] = {"ENDOFILE","LT","LE","EQ","NE","GT","GE","IF","BOOL","ELSE","ID",
                              "INT","FLOAT","COMMA","LPARENT","RPARENT","ASSIGN","SEMICOLON",
                              "WHILE","LBRACKET","RBRACKET","SWITCH","BREAK","RETURN","PRINT",
                              "READLN","THROW","TRY","CATCH","CASE","LITERAL","TRUE","FALSE",
                              "ADDRESS","STAR","DOT","LBRACE","RBRACE","NOT","CHAR","QUOTE",
                              "SIMPLEQUOTE","BACKSLASH","COLON","PLUS","MINUS","PIPE","SLASH",
                              "PERCENT","AND","OR","POINTER","TYPEDEF","STRUCT","NUMINT",
                              "NUMFLOAT","LITERALCHAR"};

    return tokens[id];
}

#endif //COMPILADOR_2019_3_TOKEN_H
#ifdef __cplusplus
}
#endif