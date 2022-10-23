#include <iostream>
#include "..\libs\InstructionBuffer\InstructionBuffer.h"
#include "..\libs\Parser\Parser.h"
#include "..\libs\ReadWrite\ReadWrite.h"
#include "..\libs\Stmt\Stmt.h"
#include "..\libs\StringBuffer\StringBuffer.h"
#include "..\libs\ToDoBuffer\ToDoBuffer.h"
#include "..\libs\SymbolTable\SymbolTable.h"
#include "..\libs\Stmt\Pop.h" //DELETEME
#include "..\libs\Stmt\Pushscal.h" //DELETEME
#include "..\libs\Stmt\Pushi.h" //DELETEME
#include "..\libs\Stmt\GoSub.h" //DELETEME
#include "..\libs\Stmt\GoSubLabel.h" //DELETEME
#include "..\libs\TableEntry\TableEntry.h" //DELETEME

int main() {
    
    // --------------------------- Set-up ---------------------------

    std::cout << "Running." << std::endl;

    const char* input = "input.txt";
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