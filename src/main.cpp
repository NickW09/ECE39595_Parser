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
#include "..\libs\TableEntry\TableEntry.h" //DELETEME

int main() {
    
    // --------------------------- Set-up ---------------------------

    std::cout << "Running." << std::endl;

    const char* input = "input.txt";
    const char* output = "output.txt";

    // ------------------------- Parser Code -------------------------

    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    //StringBuffer* strBuf = StringBuffer::getInstance();
    //to do table
    //Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf);
    
    //parse.beginParser(filename);

    // ------------------- Virtual Machine Code ----------------------

    // -------------------------- Testing ----------------------------

    //TEST - abstract stmt classes//
        /*Stmt* stmt1;
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
    //ENDTEST//*/

    /*//TEST - NEEDS .txt FILES TO WORK//
    ReadWrite* readTest = ReadWrite::getInstance(input, output);
    char* word0 = readTest->readInstruction();
    delete word0;
    char* word1 = readTest->readInstruction();
    delete word1;
    char* word2 = readTest->readInstruction();
    delete word2;
    char* word3 = readTest->readInstruction();
    delete word3;
    //ENDTEST//*/

    //TEST - Table Entry / Symbol Table//
        TableEntry* te = new TableEntry(3, 5);
        std::cout << te->getLength() << std::endl;
        std::cout << te->getLocation() << std::endl;
        te->setLength(2);
        std::cout << te->getLength() << std::endl;
    
        symTable->push("myVar", *te);
        symTable->push("Z", TableEntry(8, 22));
        std::cout << symTable->getEntry("Z").getLocation() << std::endl;
        //entering into subroutine
        symTable->setSubLv(symTable->getSubLv() + 1);
        symTable->push("myVar", TableEntry(100, 101));
        symTable->push("Z", TableEntry(6, 7));
        symTable->push("Apple", TableEntry(8, 9));
        std::cout << symTable->getEntry("myVar").getLength() << std::endl;

        //exiting subrouting
        symTable->setSubLv(symTable->getSubLv() - 1);
        std::cout << symTable->getEntry("myVar").getLength() << std::endl;
    //ENDTEST//
}