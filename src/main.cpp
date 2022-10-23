#include <iostream>
#include "..\libs\InstructionBuffer\InstructionBuffer.h"
#include "..\libs\Parser\Parser.h"
#include "..\libs\ReadWrite\ReadWrite.h"
#include "..\libs\Stmt\Stmt.h"
#include "..\libs\StringBuffer\StringBuffer.h"
#include "..\libs\ToDoBuffer\ToDoBuffer.h"
#include "..\libs\SymbolTable\SymbolTable.h"
#include "..\libs\Debug\Debug.h"

int main() {
    
    // --------------------------- Set-up ---------------------------

    // ------------------------- Parser Code -------------------------

    //InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    //SymbolTable* symTable = SymbolTable::getInstance();
    //StringBuffer* strBuf = StringBuffer::getInstance();
    //ToDoBuffer* toDoBuf = ToDoBuffer::getInstance();
    //Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf, toDoBuf);
    //parser->beginParser();
    
    //parse.beginParser(filename);

    // ------------------- Virtual Machine Code ----------------------

    // -------------------------- Testing ----------------------------
    Debug::test("test_inputs/0StartExit", "output.txt", "test_outputs/0StartExit.pout");
    Debug::test("test_inputs/1PushI", "output.txt", "test_outputs/1PushI.pout");
    Debug::test("test_inputs/2PrintTOS", "output.txt", "test_outputs/2PrintTOS.pout");
    Debug::test("test_inputs/3Add", "output.txt", "test_outputs/3Add.pout");
    Debug::test("test_inputs/4Prints", "output.txt", "test_outputs/4Prints.pout");
    Debug::test("test_inputs/5Div", "output.txt", "test_outputs/5Div.pout");
    Debug::score();
}