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
    
    
    Debug::test("0StartExit", "0StartExit.pout", "test_outputs/0StartExit.pout");
    Debug::test("1PushI", "1PushI.pout", "test_outputs/1PushI.pout");
    Debug::test("2PrintTOS", "2PrintTOSt", "test_outputs/2PrintTOS.pout");
    Debug::test("3Add", "3Add.pout", "test_outputs/3Add.pout");
    Debug::test("4Prints", "4Prints.pout", "test_outputs/4Prints.pout");
    Debug::test("5Div", "5Div.pout", "test_outputs/5Div.pout");
    Debug::test("6Dup", "6Dup.pout", "test_outputs/6Dup.pout");
    Debug::test("7Mul", "7Mul.pout", "test_outputs/7Mul.pout");
    Debug::test("8Negate", "8Negate.pout", "test_outputs/8Negate.pout");
    Debug::test("9Pop", "9Pop.pout", "test_outputs/9Pop.pout");
    Debug::test("10Swap", "10Swap.pout", "test_outputs/10Swap.pout");
    Debug::test("11Label", "11Label.pout", "test_outputs/11Label.pout");
    Debug::test("12Jump", "12Jump.pout", "test_outputs/12Jump.pout");
    Debug::test("13SimpleGoSub_GoSubLabel_Return", "13SimpleGoSub_GoSubLabel_Return.pout", "test_outputs/13SimpleGoSub_GoSubLabel_Return.pout");
    Debug::test("14ScalarEasy", "14ScalarEasy.pout", "test_outputs/14ScalarEasy.pout");
    Debug::test("15ScalarHard", "15ScalarHard.pout", "test_outputs/15ScalarHard.pout");
    Debug::test("16ScalarEasy", "16ScalarEasy.pout", "test_outputs/16ScalarEasy.pout");
    Debug::test("17ScalarHard", "17ScalarHard.pout", "test_outputs/17ScalarHard.pout");
    Debug::test("18ScalarHardest", "18ScalarHardest.pout", "test_outputs/18ScalarHardest.pout");
    Debug::test("19ArrayEasy", "19ArrayEasy.pout", "test_outputs/19ArrayEasy.pout");
    Debug::test("20ArrayHard", "test_outputs/20ArrayHard.pout", "test_outputs/20ArrayHard.pout");
    Debug::test("21ArrayEasy", "21ArrayEasy.pout", "test_outputs/21ArrayEasy.pout");
    Debug::test("22ArrayHard", "22ArrayHard.pout", "test_outputs/22ArrayHard.pout");
    Debug::test("23ArrayHardest", "23ArrayHardest.pout", "test_outputs/23ArrayHardest.pout");
    Debug::test("24JumpZero", "24JumpZero.pout", "test_outputs/24JumpZero.pout");
    Debug::test("25JumpNZero", "25JumpNZero.pout", "test_outputs/25JumpNZero.pout");
    Debug::test("26Recurse", "26Recurse.pout", "test_outputs/26Recurse.pout");
    Debug::test("27DotProd", "27DotProd.pout", "test_outputs/27DotProd.pout");
    Debug::test("99Sample", "99Sample.pout", "test_outputs/99Sample.pout");
    Debug::test("Err1StmtAfterEnd", "Err1StmtAfterEnd.pout", "test_outputs/Err1StmtAfterEnd.pout");
    Debug::test("Err2NoEnd", "Err2NoEnd.pout", "test_outputs/Err2NoEnd.pout");
    Debug::test("Err3DoubleDefScalar", "Err3DoubleDefScalar.pout", "test_outputs/Err3DoubleDefScalar.pout");
    Debug::test("Err4DoubleDefArr", "Err4DoubleDefArr.pout", "test_outputs/Err4DoubleDefArr.pout");
    Debug::test("Err5DoubleDefLabel", "Err5DoubleDefLabel.pout", "test_outputs/Err5DoubleDefLabel.pout");
    

    Debug::score();
}