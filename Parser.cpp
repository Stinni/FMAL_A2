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
	theListOfTerms = list<string>();
}

void Parser::parse()
{
    nextToken = lex();
	Statements();
}

Token Parser::lex()
{
    Token theNextToken = theLexer->nextToken();
    cout << "------------------------------------------------------------" << endl;
    cout << "The Token has " + theNextToken.lexeme + " as it's lexeme."  << endl;
    cout << "------------------------------------------------------------" << endl;
	switch (theNextToken.tCode)
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
        cout << "PUSH " + theNextToken.lexeme << endl;
        break;
    case ID:
        cout << "PUSH " + theNextToken.lexeme << endl;
        break;
    case PRINT:
        theListOfTerms.push_back("PRINT");
        break;
    default:
        break;
	}

	return theNextToken;
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
    cout << "Started STATEMENTS() function!" << endl; // TODO: DELETE!!!
    if (nextToken.tCode == END)
    {
        print();
        return;
    }
    else
    {
        Statement();
        if (nextToken.tCode == SEMICOL)
        {
            print();
            nextToken = lex();
            Statements();
            return;
        }
    }
    error("Syntax error!");
}

void Parser::Statement()
{
    cout << "Started STATEMENT() function!" << endl; // TODO: DELETE!!!
    if (nextToken.tCode == ID)
    {
        nextToken = lex();
        if (nextToken.tCode == ASSIGN)
        {
            nextToken = lex();
            Expr();
        }
    }
    else if (nextToken.tCode == PRINT)
    {
        nextToken = lex();
        if (nextToken.tCode == ID)
        {
            nextToken = lex();
        }
    }
}

void Parser::Expr()
{
    cout << "Started EXPR() function!" << endl; // TODO: DELETE!!!
    Term();
    if (nextToken.tCode == ADD)
    {
        nextToken = lex();
        Expr();
    }
    else if (nextToken.tCode == SUB)
    {
        nextToken = lex();
        Expr();
    }
}

void Parser::Term()
{
    cout << "Started TERM() function!" << endl; // TODO: DELETE!!!
    Factor();
    if (nextToken.tCode == MULT)
    {
        nextToken = lex();
        Term();
    }
}

void Parser::Factor()
{
    cout << "Started FACTOR() function!" << endl; // TODO: DELETE!!!
    if (nextToken.tCode == INT)
    {
        nextToken = lex();
    }
    else if (nextToken.tCode == ID)
    {
        nextToken = lex();
    }
    else if (nextToken.tCode == LPAREN)
    {
        nextToken = lex();
        Expr();
        if (nextToken.tCode == RPAREN)
        {
            print();
            nextToken = lex();
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
    cout << "Started PRINT() function!" << endl; // TODO: DELETE!!!
    if (!theListOfTerms.empty())
    {
        theListOfTerms.reverse();
        for (list<string>::iterator i = theListOfTerms.begin(); i != theListOfTerms.end(); i++)
        {
            cout << *i << endl;
        }
        theListOfTerms.clear();
    }
    cout << "Ended PRINT() function!" << endl; // TODO: DELETE!!!
}
