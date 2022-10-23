#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <fstream> //reading and writing function
#include "..\InstructionBuffer\InstructionBuffer.h"
#include "..\ReadWrite\ReadWrite.h"
#include "..\StringBuffer\StringBuffer.h"
#include "..\SymbolTable\SymbolTable.h"
#include "..\ToDoBuffer\ToDoBuffer.h"
#include "..\Stmt\Add.h"
#include "..\Stmt\Div.h"
#include "..\Stmt\Dup.h"
#include "..\Stmt\Exit.h"
#include "..\Stmt\GoSub.h"
#include "..\Stmt\GoSubLabel.h"
#include "..\Stmt\Jump.h"
#include "..\Stmt\JumpNZero.h"
#include "..\Stmt\JumpZero.h"
#include "..\Stmt\Mul.h"
#include "..\Stmt\Negate.h"
#include "..\Stmt\Pop.h"
#include "..\Stmt\Poparr.h"
#include "..\Stmt\Popscal.h"
#include "..\Stmt\Prints.h"
#include "..\Stmt\Printtos.h"
#include "..\Stmt\Pusharr.h"
#include "..\Stmt\Pushi.h"
#include "..\Stmt\Pushscal.h"
#include "..\Stmt\Return.h"
#include "..\Stmt\Start.h"
#include "..\Stmt\Stmt.h"
#include "..\Stmt\Swap.h"

#define ERROR 0
#define INT_PARAM 1
#define VAR_PARAM 2
#define INT_VAR_PARAM 3
#define LABEL_PARAM 4
#define TO_DO 5
#define NO_PARAM 6
#define END 7

class Parser {

public:
    static Parser* getInstance(const char* inputFileName, const char* outputFileName, InstructionBuffer* instrBuf, SymbolTable* symTable, StringBuffer* strBuf, ToDoBuffer* todoBuf); //gets single instance of parser
    int beginParser();
    ~Parser();
    //void setError();
    //bool getError();

private:
    Parser(const char* inputFileName, const char* outputFileName, InstructionBuffer* instrBuf, SymbolTable* symTable, StringBuffer* strBuf, ToDoBuffer* todoBuf); //private parser constructor used by getInstance
    static Parser* parser;  //unique instantiation of parser
    void createStmt(int type, std::string str);
    int determineType(std::string str);
    void determineAction(std::string str);
    void printStringBuf();
    void printInstrBuf();
    void printSymTable();
    InstructionBuffer* instrBuf;
    SymbolTable* symTable;
    StringBuffer* strBuf;
    ToDoBuffer* toDoBuf;
    ReadWrite* readWrite;
    bool error;
    Start* start;
    GoSubLabel* gosublabel;
};

#endif /* PARSER_H_ */