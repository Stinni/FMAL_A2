//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include <string>
#include <iostream>
#include "Token.h"
using namespace std;

class Lexer
{
public:
	Token nextToken();

private:
	void checkTcode(Token *token);
	bool checkIfInt(string s);
	bool checkIfId(string s);
};
