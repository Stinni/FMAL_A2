//Course:     T-501-FMAL - Forritunarmal
//Term:       Spring 2016
//Assignment: Skilaverkefni 2
//Author:     Kristinn Heidar Freysteinsson
//Kt.:        011081-3209
//Email:      kristinnf13@ru.is

#include "Lexer.h"
#include "Parser.h"

class Compiler
{
    Lexer* myLexer;
    Parser* myParser;

public:
    Compiler()
    {
        myLexer = new Lexer();
        myParser = new Parser(myLexer);
        myParser->parse();
    }
    ~Compiler()
    {
        delete myParser;
        delete myLexer;
    }
};

int main()
{
    Compiler* compiler = new Compiler();

    return 0;
}
