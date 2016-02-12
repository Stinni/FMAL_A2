//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include "Lexer.h"
#include "Parser.h"

int main()
{
    Lexer *myLexer = new Lexer();
    Parser *myParser = new Parser(myLexer);
    myParser->parse();

    return 0;
}
