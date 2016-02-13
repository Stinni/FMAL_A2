//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include "Parser.h"

Parser::Parser(Lexer* lexer)
{
	theLexer = lexer;
}

void Parser::parse()
{
    nextToken = theLexer->nextToken();
	while (nextToken->tCode != END)
	{
		if (nextToken->tCode == ERROR)
		{
			cout << "Lexical error!" << endl;
			exit(1);
		}
		cout << "Testing!" << endl;
		nextToken = theLexer->nextToken();
	}
}