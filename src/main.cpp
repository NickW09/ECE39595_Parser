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
    Debug::test("test_inputs/6Dup", "output.txt", "test_outputs/6Dup.pout");
    Debug::test("test_inputs/7Mul", "output.txt", "test_outputs/7Mul.pout");
    Debug::test("test_inputs/8Negate", "output.txt", "test_outputs/8Negate.pout");
    Debug::test("test_inputs/9Pop", "output.txt", "test_outputs/9Pop.pout");
    Debug::test("test_inputs/10Swap", "output.txt", "test_outputs/10Swap.pout");
    Debug::test("test_inputs/11Label", "output.txt", "test_outputs/11Label.pout");
    Debug::test("test_inputs/12Jump", "output.txt", "test_outputs/12Jump.pout");
    Debug::test("test_inputs/13SimpleGoSub_GoSubLabel_Return", "output.txt", "test_outputs/13SimpleGoSub_GoSubLabel_Return.pout");
    Debug::test("test_inputs/14ScalarEasy", "output.txt", "test_outputs/14ScalarEasy.pout");
    Debug::test("test_inputs/15ScalarHard", "output.txt", "test_outputs/15ScalarHard.pout");
    Debug::test("test_inputs/16ScalarEasy", "output.txt", "test_outputs/16ScalarEasy.pout");
    Debug::test("test_inputs/17ScalarHard", "output.txt", "test_outputs/17ScalarHard.pout");
    Debug::test("test_inputs/18ScalarHardest", "output.txt", "test_outputs/18ScalarHardest.pout");
    Debug::test("test_inputs/19ArrayEasy", "output.txt", "test_outputs/19ArrayEasy.pout");
    Debug::test("test_inputs/20ArrayHard", "output.txt", "test_outputs/20ArrayHard.pout");
    Debug::test("test_inputs/21ArrayEasy", "output.txt", "test_outputs/21ArrayEasy.pout");
    Debug::test("test_inputs/22ArrayHard", "output.txt", "test_outputs/22ArrayHard.pout");
    Debug::test("test_inputs/23ArrayHardest", "output.txt", "test_outputs/23ArrayHardest.pout");
    Debug::test("test_inputs/24JumpZero", "output.txt", "test_outputs/24JumpZero.pout");
    Debug::test("test_inputs/25JumpNZero", "output.txt", "test_outputs/25JumpNZero.pout");
    Debug::test("test_inputs/26Recurse", "output.txt", "test_outputs/26Recurse.pout");
    Debug::test("test_inputs/27DotProd", "output.txt", "test_outputs/27DotProd.pout");
    Debug::test("test_inputs/99Sample", "output.txt", "test_outputs/99Sample.pout");
    Debug::test("test_inputs/Err1StmtAfterEnd", "output.txt", "test_outputs/Err1StmtAfterEnd.pout");
    Debug::test("test_inputs/Err2NoEnd", "output.txt", "test_outputs/Err2NoEnd.pout");
    Debug::test("test_inputs/Err3DoubleDefScalar", "output.txt", "test_outputs/Err3DoubleDefScalar.pout");
    Debug::test("test_inputs/Err4DoubleDefArr", "output.txt", "test_outputs/Err4DoubleDefArr.pout");
    Debug::test("test_inputs/Err5DoubleDefLabel", "output.txt", "test_outputs/Err5DoubleDefLabel.pout");


    Debug::score();
}