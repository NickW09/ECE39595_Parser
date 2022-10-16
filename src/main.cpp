#include <iostream>
#include "..\libs\InstructionBuffer\InstructionBuffer.h"
#include "..\libs\Parser\Parser.h"
#include "..\libs\ReadWrite\ReadWrite.h"
#include "..\libs\Stmt\Stmt.h"
#include "..\libs\StringBuffer\StringBuffer.h"
#include "..\libs\SymbolTable\SymbolTable.h"

int main() {

    std::cout << "hi" << std::endl;

    char* input = "input.txt";
    char* output = "output.txt";

    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    StringBuffer* strBuf = StringBuffer::getInstance();
    //to do table
    //Parser parse(instrBuf, symTable, strBuf, filename);
    
    //parse.beginParser(filename);

    //Virtual machine code goes here

}