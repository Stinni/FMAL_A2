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
	//theList = null;
}

void Parser::parse()
{
    nextToken = theLexer->nextToken();
	if (nextToken->tCode == ERROR)
	{
		error("Lexical error!");
	}

	Statements();
}

void Parser::error(string errorString)
{
    cout << errorString << endl;
    exit(1);
}

/*
 * The non-terminals are: Statements (starting symbol), Statement, Expr, Term, and Factor.
 * Terminals (tokens) are: ; end id print + - * int ( )
*/
void Parser::Statements()
{
    if (nextToken->tCode == END)
    {
        return;
    }
}

void Parser::Statement()
{

}

void Parser::Expr()
{

}

void Parser::Term()
{

}

void Parser::Factor()
{

}
