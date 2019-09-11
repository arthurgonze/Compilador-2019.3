//
// Created by souzajbr on 10/09/2019.
//

#include "ctype.h"
#include "../token.h"
#include "stdbool.h"
#include "stdio.h"

#define INITIAL_STATE 0;

int currentState = INITIAL_STATE;
char currentInput;
int currentLine = 1;

int count = 0;
//char* input = "< <= == >= > = != ! asda 10.03 10/";
char *input = "'a' | || \"cacacaraio\"/";

char getNextChar() {
    currentInput = input[count++];
}

void getNextCharAndGoTo(int state) {
    currentInput = getNextChar();
    currentState = state;
}


void goToState(int state) {
    currentState = state;
}

int foundTokenAndRestart(int token) {
    goToState(0);
    return token;
}

int foundTokenAndGetNextInput(int token) {
    getNextChar();
    return foundTokenAndRestart(token);
}

void init() {
    getNextChar();
}

bool isLetter(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void fail(char *reason) {
    //TODO jogar os erros para uma pilha
    printf("Lexicon Error: [Line %d] %s", currentLine, reason);
}

int getNextToken() {

    while (1) {

        switch (currentState) {

            case 0:
                if (currentInput == '\n')
                    currentLine++;

                if (isspace(currentInput)) {
                    getNextCharAndGoTo(0);
                } else if (isLetter(currentInput)) {
                    getNextCharAndGoTo(13);
                } else if (isDigit(currentInput))
                    getNextCharAndGoTo(19);
                else
                    switch (currentInput) {
                        case '<':
                            getNextCharAndGoTo(1);
                            break;
                        case '=':
                            getNextCharAndGoTo(4);
                            break;
                        case '>':
                            getNextCharAndGoTo(5);
                            break;
                        case '!':
                            getNextCharAndGoTo(10);
                            break;
                        case '.':
                            getNextCharAndGoTo(14);
                            break;
                        case '+':
                            getNextCharAndGoTo(27);
                            break;
                        case ')':
                            getNextCharAndGoTo(28);
                            break;
                        case '-':
                            getNextCharAndGoTo(29);
                            break;
                        case '(':
                            getNextCharAndGoTo(30);
                            break;
                        case '{':
                            getNextCharAndGoTo(31);
                            break;
                        case '}':
                            getNextCharAndGoTo(32);
                            break;
                        case '[':
                            getNextCharAndGoTo(33);
                            break;
                        case ']':
                            getNextCharAndGoTo(34);
                            break;
                        case ',':
                            getNextCharAndGoTo(35);
                            break;
                        case ';':
                            getNextCharAndGoTo(36);
                            break;
                        case '"':
                            getNextCharAndGoTo(37);
                            break;
                        case '\'':
                            getNextCharAndGoTo(38);
                            break;
                        case '|':
                            getNextCharAndGoTo(43);
                            break;
                        default:
                            return -1;
                    }
                break;
            case 1:
                switch (currentInput) {
                    case '=':
                        goToState(2);
                        break;
                    default:
                        goToState(3);
                        break;
                }
                break;
            case 2:
                return foundTokenAndGetNextInput(LE);
            case 3:
                return foundTokenAndRestart(LT);
            case 4:
                switch (currentInput) {
                    case '=':
                        getNextCharAndGoTo(6);
                        break;
                    default:
                        goToState(7);
                        break;
                }
                break;
            case 5:
                switch (currentInput) {
                    case '=':
                        getNextCharAndGoTo(8);
                        break;
                    default:
                        goToState(9);
                        break;
                }
                break;
            case 6:
                return foundTokenAndGetNextInput(EQ);
            case 7:
                return foundTokenAndRestart(ASSIGN);
            case 8:
                return foundTokenAndGetNextInput(GE);
            case 9:
                return foundTokenAndRestart(GT);
            case 10:
                switch (currentInput) {
                    case '=':
                        getNextCharAndGoTo(11);
                        break;
                    default:
                        goToState(12);
                        break;
                }
                break;
            case 11:
                return foundTokenAndGetNextInput(NE);
            case 12:
                return foundTokenAndRestart(NOT);
            case 13:
                //TODO implementar a leitura do lexema
                if (isLetter(currentInput) || isDigit(currentInput))
                    getNextCharAndGoTo(13);
                else
                    goToState(15);
                break;
            case 14:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(55);
                else
                    goToState(53);
                break;
            case 15:
                goToState(0);
                //TODO verificar para ver se é palavra reservada
                //TODO adicionar
                return ID;
            case 17:
                goToState(0);
                fail("Unexpected end of file");
                break;
            case 18:
                goToState(0);
                fail("Unexpected character");
                break;
            case 19:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(19);
                else if (currentInput == '.')
                    getNextCharAndGoTo(25);
                else if (currentInput == 'e' || currentInput == 'E')
                    getNextCharAndGoTo(20);
                else if (isLetter(currentInput))
                    getNextCharAndGoTo(18);
                else
                    goToState(24);
                break;
            case 20:
                if (isDigit(currentInput)) //TODO consertar automato nesse estado
                    getNextCharAndGoTo(22);
                else if (currentInput == '+' || currentInput == '-')
                    getNextCharAndGoTo(21);
                else
                    getNextCharAndGoTo(18);
                break;
            case 21:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(22);
                else
                    getNextCharAndGoTo(18);
                break;
            case 22:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(22);
                else {
                    goToState(23);
                }
                break;
            case 23:
                return foundTokenAndRestart(NUMFLOAT);
            case 24:
                return foundTokenAndRestart(NUMINT);
            case 25:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(26);
                else if (isLetter(currentInput))
                    getNextCharAndGoTo(18);
                else
                    goToState(23);
                break;
            case 26:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(26);
                else if (currentInput == 'E' || currentInput == 'e')
                    getNextCharAndGoTo(20);
                else if (isLetter(currentInput))
                    getNextCharAndGoTo(18);
                else
                    goToState(23);
                break;
            case 27:
                return foundTokenAndRestart(PLUS);
            case 28:
                return foundTokenAndRestart(RPARENT);
            case 29:
                return foundTokenAndRestart(MINUS);
            case 30:
                return foundTokenAndRestart(LPARENT);
            case 31:
                return foundTokenAndRestart(LBRACE);
            case 32:
                return foundTokenAndRestart(RBRACE);
            case 33:
                return foundTokenAndRestart(LBRACKET);
            case 34:
                return foundTokenAndRestart(RBRACKET);
            case 35:
                return foundTokenAndRestart(COLON);
            case 36:
                return foundTokenAndRestart(SEMICOLON);
            case 37:
                switch (currentInput) {
                    case '"':
                        getNextCharAndGoTo(40);
                        break;
                    case '\\':
                        getNextCharAndGoTo(41);
                        break;
                    case ENDOFFILE:
                        getNextCharAndGoTo(17);
                        break;
                    default:
                        getNextCharAndGoTo(37);
                        break;
                }
                break;
            case 38:
                switch (currentInput) {
                    case '\\':
                        getNextCharAndGoTo(99);
                        break;
                    default:
                        getNextCharAndGoTo(42);
                        break;
                }
                break;
            case 39:
                return foundTokenAndGetNextInput(STAR); //TODO alterar o automato para mudar o label
            case 40:
                return foundTokenAndRestart(LITERAL);
            case 41:
                getNextCharAndGoTo(37);
                break;
            case 42:
                switch (currentInput) {
                    case '\'':
                        getNextCharAndGoTo(40);
                        break;
                    case ENDOFFILE:
                        getNextCharAndGoTo(17);
                        break;
                    default:
                        getNextCharAndGoTo(18);
                        break;
                }
                break;
            case 43:
                if (currentInput == '|')
                    getNextCharAndGoTo(44);
                else
                    goToState(45);
                break;
            case 44:
                return foundTokenAndRestart(OR);
            case 45:
                return foundTokenAndRestart(PIPE);
            case 53:
                return foundTokenAndRestart(DOT);
            case 55:
                if (isDigit(currentInput))
                    getNextCharAndGoTo(55);
                else if (currentInput == 'e' ||
                         currentInput == 'E') //TODO consertar o automato para inserir esse estado
                    getNextCharAndGoTo(20);
                else if (isLetter(currentInput)) {
                    getNextCharAndGoTo(18);
                } else
                    //TODO Retornar o valor do número
                    goToState(23);
                break;
            case 99:
                getNextCharAndGoTo(38);
                break;
        }

    }
}