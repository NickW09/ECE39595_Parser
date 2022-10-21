#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <fstream> //reading and writing function
#include "..\InstructionBuffer\InstructionBuffer.h"
#include "..\ReadWrite\ReadWrite.h"
#include "..\StringBuffer\StringBuffer.h"
#include "..\SymbolTable\SymbolTable.h"

#define INT_PARAM 1
#define VAR_PARAM 2
#define LABEL_PARAM 3
#define TO_DO 4
#define NO_PARAM 5
#define END 6

class Parser {

public:
    static Parser* getInstance(const char* inputFileName, const char* outputFileName, InstructionBuffer* instrBuf, SymbolTable* symTable, StringBuffer* strBuf); //gets single instance of parser
    void beginParser();
    //void setError();
    //bool getError();

private:
    Parser(const char* inputFileName, const char* outputFileName, InstructionBuffer* instrBuf, SymbolTable* symTable, StringBuffer* strBuf); //private parser constructor used by getInstance
    static Parser* parser;  //unique instantiation of parser
    void createStmt(char* instruction);
    int determineType(char* instr);
    void determineAction(char* instr);
    InstructionBuffer* instrBuf;
    SymbolTable* symTable;
    StringBuffer* strBuf;
    ReadWrite* readWrite;
    bool error;
};

#endif /* PARSER_H_ */

