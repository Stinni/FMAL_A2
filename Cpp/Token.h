//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include <string>
using namespace std;

enum TokenCode { ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR };

class Token {
public:
	Token()
	{
		lexeme = "";
		tCode = ERROR;
	}
    string lexeme;
	int tCode;
};
