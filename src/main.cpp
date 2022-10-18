#include <iostream>
#include "..\libs\InstructionBuffer\InstructionBuffer.h"
#include "..\libs\Parser\Parser.h"
#include "..\libs\ReadWrite\ReadWrite.h"
#include "..\libs\Stmt\Stmt.h"
#include "..\libs\StringBuffer\StringBuffer.h"
#include "..\libs\SymbolTable\SymbolTable.h"
#include "..\libs\Stmt\Pop.h" //DELETEME
#include "..\libs\Stmt\Pushscal.h" //DELETEME
#include "..\libs\Stmt\Pushi.h" //DELETEME
#include "..\libs\Stmt\GoSub.h" //DELETEME
#include "..\libs\Stmt\GoSubLabel.h" //DELETEME

int main() {

    std::cout << "hi" << std::endl;

    const char* input = "input.txt";
    const char* output = "output.txt";

    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    StringBuffer* strBuf = StringBuffer::getInstance();
    //to do table
    Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf);
    
    //parse.beginParser(filename);


    //TEST//
    Stmt* stmt1;
    Stmt* stmt2;
    Stmt* stmt3;
    Stmt* stmt4;
    Stmt* stmt5;

    stmt1 = new Pop();
    stmt2 = new Pushscal("x");
    stmt3 = new Pushi(5);
    stmt4 = new GoSub("L1");
    stmt5 = new GoSubLabel("L2");
    
    stmt1->print();
    stmt2->print();
    stmt3->print();
    stmt4->print();
    stmt5->print();
    //ENDTEST//
    
    //Virtual machine code goes here

}