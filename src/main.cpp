#include <iostream>
#include "..\libs\InstructionBuffer\InstructionBuffer.h"
#include "..\libs\Parser\Parser.h"
#include "..\libs\ReadWrite\ReadWrite.h"
#include "..\libs\Stmt\Stmt.h"
#include "..\libs\StringBuffer\StringBuffer.h"
#include "..\libs\ToDoBuffer\ToDoBuffer.h"
#include "..\libs\SymbolTable\SymbolTable.h"

int main() {
    
    // --------------------------- Set-up ---------------------------

    std::cout << "Running." << std::endl;

    const char* input = "test_inputs/input.txt";
    const char* output = "output.txt";

    // ------------------------- Parser Code -------------------------

    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    StringBuffer* strBuf = StringBuffer::getInstance();
    ToDoBuffer* toDoBuf = ToDoBuffer::getInstance();
    Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf, toDoBuf);
    parser->beginParser();
    
    //parse.beginParser(filename);

    // ------------------- Virtual Machine Code ----------------------

    // -------------------------- Testing ----------------------------

}