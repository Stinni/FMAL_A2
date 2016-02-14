//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <list>
#include "Lexer.h"
#include "Token.h"
using namespace std;

class Parser
{
public:
	Parser(Lexer* lexer);
	void parse();

private:
	Lexer* theLexer;
	Token nextToken;
	list<string> theListOfTerms;
	Token lex();
	void error(string errorString);
	void Statements();
	void Statement();
	void Expr();
    void Term();
    void Factor();
    void print();
};

#endif // PARSER_H
