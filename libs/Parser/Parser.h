#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <fstream> //reading and writing function
#include "..\InstructionBuffer\InstructionBuffer.h"
#include "..\ReadWrite\ReadWrite.h"
#include "..\StringBuffer\StringBuffer.h"
#include "..\SymbolTable\SymbolTable.h"

class Parser {

public:
    static Parser* getInstance(char* inputFileName, char* outputFileName, InstructionBuffer& instrBuf, SymbolTable& symTable, StringBuffer& strBuf); //gets single instance of parser
    void beginParser(char* txtfile);
    void setError();
    bool getError();

private:
    Parser(char* inputFileName, char* outputFileName, InstructionBuffer& instrBuf, SymbolTable& symTable, StringBuffer& strBuf); //private parser constructor used by getInstance
    static Parser* parser;  //unique instantiation of parser
    void createStmt(char* instruction);
    InstructionBuffer instrBuf;
    SymbolTable symTable;
    StringBuffer strBuf;
    ReadWrite* readWrite;
    bool error;
};

#endif /* PARSER_H_ */

