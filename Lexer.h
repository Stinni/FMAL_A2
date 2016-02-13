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
    ~Lexer();
	Token* nextToken();

private:
    Token* theToken;
    list<string> buffer;
	void checkTcode(Token *token);
	bool checkIfInt(string s);
	bool checkIfId(string s);
};

#endif // LEXER_H
