//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include "Lexer.h"

Token Lexer::nextToken()
{
	Token *newToken = new Token();
	cin >> newToken->lexeme;
	checkTcode(newToken);

	return *newToken;
}

void Lexer::checkTcode(Token *token)
{
	if (token->lexeme == "=")
	{
		token->tCode = ASSIGN;
	}
	else if (token->lexeme == ";")
	{
		token->tCode = SEMICOL;
	}
	else if (token->lexeme == "+")
	{
		token->tCode = ADD;
	}
	else if (token->lexeme == "-")
	{
		token->tCode = SUB;
	}
	else if (token->lexeme == "*")
	{
		token->tCode = MULT;
	}
	else if (token->lexeme == "(")
	{
		token->tCode = LPAREN;
	}
	else if (token->lexeme == ")")
	{
		token->tCode = RPAREN;
	}
	else if (token->lexeme == "print")
	{
		token->tCode = PRINT;
	}
	else if (token->lexeme == "end")
	{
		token->tCode = END;
	}
	else if (checkIfInt(token->lexeme))
	{
		token->tCode = INT;
	}
	else if (checkIfId(token->lexeme))
	{
		token->tCode = ID;
	}
}

bool Lexer::checkIfInt(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}

bool Lexer::checkIfId(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i]))
		{
			return false;
		}
	}
	return true;
}
