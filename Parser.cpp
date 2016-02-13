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
    lex();
	Statements();
}

void Parser::lex()
{
    nextToken = theLexer->nextToken();
	switch (nextToken->tCode)
	{
    case ERROR:
        error("Lexical error!");
    case ASSIGN:
        theListOfTerms.push_back("ASSIGN");
        break;
    case ADD:
        theListOfTerms.push_back("ADD");
        break;
    case SUB:
        theListOfTerms.push_back("SUB");
        break;
    case MULT:
        theListOfTerms.push_back("MULT");
        break;
    case INT:
        cout << "PUSH " + nextToken->lexeme << endl;
        break;
    case ID:
        cout << "PUSH " + nextToken->lexeme << endl;
        break;
    case PRINT:
        theListOfTerms.push_back("PRINT");
        break;
    default:
        break;
	}
}

void Parser::error(string errorString)
{
    cout << errorString << endl;
    exit(1);
}

/*
 * The non-terminals are: Statements (starting symbol), Statement, Expr, Term, and Factor.
 * Terminals (tokens) are: ; end id print + - * int ( )
 *
 * Implemented: NT's -
 * Implemented: Tokens - ; end id print + - * int ( )
*/
void Parser::Statements()
{
    if (nextToken->tCode == END)
    {
        print();
        return;
    }
    else
    {
        Statement();
        if (nextToken->tCode == SEMICOL)
        {
            print();
            lex();
            Statements();
        }
    }
    error("Syntax error!");
}

void Parser::Statement()
{
    if (nextToken->tCode == ID)
    {
        lex();
        if (nextToken->tCode == ASSIGN)
        {
            lex();
            Expr();
        }
    }
    else if (nextToken->tCode == PRINT)
    {
        lex();
        if (nextToken->tCode == ID)
        {
            lex();
        }
    }
}

void Parser::Expr()
{
    Term();
    if (nextToken->tCode == ADD)
    {
        lex();
        Expr();
    }
    else if (nextToken->tCode == SUB)
    {
        lex();
        Expr();
    }
}

void Parser::Term()
{
    Factor();
    if (nextToken->tCode == MULT)
    {
        lex();
        Term();
    }
}

void Parser::Factor()
{
    if (nextToken->tCode == INT)
    {
        lex();
    }
    else if (nextToken->tCode == ID)
    {
        lex();
    }
    else if (nextToken->tCode == LPAREN)
    {
        lex();
        Expr();
        if (nextToken->tCode == RPAREN)
        {
            lex();
        }
        else
        {
            error("Syntax error!");
        }
    }
    else
    {
        error("Syntax error!");
    }
}

void Parser::print()
{
    if (!theListOfTerms.empty())
    {
        for (list<string>::iterator i = theListOfTerms.end(); i != theListOfTerms.begin(); --i)
        {
            cout << *i << endl;
        }
        theListOfTerms.clear();
    }
}
