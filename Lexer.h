//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>
#include <cstddef>
#include <list>
#include "Token.h"
using namespace std;

class Lexer
{
public:
    Lexer();
	Token nextToken();

private:
    list<Token> bufferList;
	bool checkTcode(string s);
	bool checkIfInt(string s);
	bool checkIfId(string s);
	bool checkIfHasColon(string s);
	bool checkIfOpenPar(string s);
	bool checkIfClosePar(string s);
};

#endif // LEXER_H
