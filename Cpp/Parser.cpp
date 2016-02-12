//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include "Parser.h"

Parser::Parser(Lexer *lexer)
{
	theLexer = lexer;
}

void Parser::parse()
{
	while (nextToken = theLexer->nextToken() && nextToken->tCode != END)
	{
		if (nextToken->tCode == ERROR)
		{
			cout << "Lexical error!" << endl;
		}
	}
}
