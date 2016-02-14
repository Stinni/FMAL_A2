//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include "Lexer.h"

Lexer::Lexer()
{
    bufferList = list<Token>();
}

Token Lexer::nextToken()
{
    if (!bufferList.empty())
    {
        Token tokenFromList = bufferList.front();
        bufferList.pop_front();
        return tokenFromList;
    }
    string input;
    cin >> input;
    if(!checkTcode(input))
    {
        Token errorToken = Token();
        return errorToken;
    }
    cout << "Before copying the front Token from the bufferList." << endl;
    Token tmp = bufferList.front();
    cout << "After coyping and before popping the front Token from the bufferList." << endl;
    bufferList.pop_front();
    cout << "After popping the front Token from the bufferList" << endl;
    return tmp;
}

bool Lexer::checkTcode(string s)
{
    Token newToken = Token();
    newToken.lexeme = s;
    if (s.empty() || s == "")
    {
        return false;
    }
    else if (s.length() == 1)
    {
        if (s == "=")
        {
            newToken.tCode = ASSIGN;
        }
        else if (s == "+")
        {
            newToken.tCode = ADD;
        }
        else if (s == "-")
        {
            newToken.tCode = SUB;
        }
        else if (s == "*")
        {
            newToken.tCode = MULT;
        }
        else if (s == "(")
        {
            newToken.tCode = LPAREN;
        }
        else if (s == ")")
        {
            newToken.tCode = RPAREN;
        }
        else if (s == ";")
        {
            newToken.tCode = SEMICOL;
        }
        else if (checkIfInt(s))
        {
            newToken.tCode = INT;
        }
        else if (checkIfId(s))
        {
            newToken.tCode = ID;
        }
        else
        {
            return false;
        }

        bufferList.push_back(newToken);
        return true;
    }
	else if (s == "print")
	{
		newToken.tCode = PRINT;
        bufferList.push_back(newToken);
        return true;
	}
	else if (s == "end")
	{
		newToken.tCode = END;
        bufferList.push_back(newToken);
        return true;
	}
	else if (checkIfInt(s))
	{
		newToken.tCode = INT;
        bufferList.push_back(newToken);
        return true;
	}
	else if (checkIfId(s))
	{
		newToken.tCode = ID;
        bufferList.push_back(newToken);
        return true;
	}
	else if (checkIfHasColon(s))
    {
        string buf = s.substr(0, buf.length()-1);
        if(!checkTcode(buf) || !checkTcode(";"))
        {
            return false;
        }
        return true;
    }
	else if (checkIfOpenPar(s))
    {
        string buf = s.substr(1, s.length());
        if(!checkTcode("(") || !checkTcode(buf))
        {
            return false;
        }
        return true;
    }
    else if (checkIfClosePar(s))
    {
        string buf = s.substr(0, s.length()-1);
        if(!checkTcode(buf) || !checkTcode(")"))
        {
            return false;
        }
        return true;
    }

    return false;
}

bool Lexer::checkIfInt(string s)
{
    for (string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (!isdigit(*i))
        {
            return false;
        }
    }
    return true;
}

bool Lexer::checkIfId(string s)
{
    for (string::iterator i = s.begin(); i != s.end(); i++)
    {
        if (!isalpha(*i))
        {
            return false;
        }
    }
    return true;
}

bool Lexer::checkIfHasColon(string s)
{
    if (!s.empty())
    {
        string tmp = s.substr(s.length()-1, s.length());
        return tmp == ";";
    }
    return false;
}

bool Lexer::checkIfOpenPar(string s)
{
    if (!s.empty() && s.length() > 2)
    {
        string tmp = s.substr(0, 1);
        return tmp == "(";
    }
    return false;
}

bool Lexer::checkIfClosePar(string s)
{
    if (!s.empty() && s.length() > 1)
    {
        string tmp = s.substr(s.length()-1, s.length());
        return tmp == ")";
    }
    return false;
}
