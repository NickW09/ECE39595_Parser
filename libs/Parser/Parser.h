#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <fstream> //reading and writing function
#include "..\InstructionBuffer\InstructionBuffer.h"
#include "..\ReadWrite\ReadWrite.h"
#include "..\StringBuffer\StringBuffer.h"
#include "..\SymbolTable\SymbolTable.h"
#include "..\Stmt\Add.h"
#include "..\Stmt\Declarr.h"
#include "..\Stmt\Declscal.h"
#include "..\Stmt\Div.h"
#include "..\Stmt\Dup.h"
#include "..\Stmt\End.h"
#include "..\Stmt\Exit.h"
#include "..\Stmt\GoSub.h"
#include "..\Stmt\GoSubLabel.h"
#include "..\Stmt\Jump.h"
#include "..\Stmt\JumpNZero.h"
#include "..\Stmt\JumpZero.h"
#include "..\Stmt\Label.h"
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

