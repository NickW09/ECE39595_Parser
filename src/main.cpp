#include <iostream>
#include "..\libs\InstructionBuffer\InstructionBuffer.h"
#include "..\libs\Parser\Parser.h"
#include "..\libs\ReadWrite\ReadWrite.h"
#include "..\libs\Stmt\Stmt.h"
#include "..\libs\StringBuffer\StringBuffer.h"
#include "..\libs\SymbolTable\SymbolTable.h"

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

    //Virtual machine code goes here

}