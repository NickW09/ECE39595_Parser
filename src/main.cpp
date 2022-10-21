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
    StringBuffer* strBuf = StringBuffer::getInstance();
    //to do table
    //Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf);
    
    //parse.beginParser(filename);

    // ------------------- Virtual Machine Code ----------------------

    // -------------------------- Testing ----------------------------

    /*//TEST - abstract stmt classes//
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

    /*//TEST - Table Entry / Symbol Table//
        TableEntry* te = new TableEntry(3, 5);
        std::cout << te->getLength() << std::endl;
        std::cout << te->getLocation() << std::endl;
        te->setLength(2);
        std::cout << te->getLength() << std::endl;
    
        symTable->push("myVar", *te);
        symTable->push("Z", TableEntry(8, 22));
        std::cout << symTable->getEntry("Z").getLocation() << std::endl;
        std::cout << "Size bf subroutine: " << symTable->getNumEntries() << std::endl;
        //entering into subroutine
        symTable->setSubLv(symTable->getSubLv() + 1);
        symTable->push("myVar", TableEntry(100, 101));
        symTable->push("Z", TableEntry(6, 7));
        symTable->push("Apple", TableEntry(20, 21));
        std::cout << symTable->getEntry("myVar").getLength() << std::endl;
        std::cout << "Size at end of subroutine: " << symTable->getNumEntries() << std::endl;
        //exiting subrouting
        std::cout << symTable->getSubLength() << std::endl;
        symTable->exitSubroutine();
        std::cout << symTable->getEntry("myVar").getLength() << std::endl;
        std::cout << "Size at after subroutine: " << symTable->getNumEntries() << std::endl;
    *///ENDTEST//

    /*//TEST - String Buffer//
        strBuf->push("Hello");
        strBuf->push(" World");
        std::cout << "Size: " << strBuf->getSize() << " String: " << strBuf->get(0) << strBuf->get(1) << std::endl;
        strBuf->push(" World1");
        strBuf->push(" World2");
        strBuf->push(" World3");
        std::cout << "Size: " << strBuf->getSize() << " String: " << strBuf->get(0) << strBuf->get(1) << std::endl;
        strBuf->remove(1);
        std::cout << "Size: " << strBuf->getSize() << " String: " << strBuf->get(0) << strBuf->get(1) << std::endl;
        strBuf->pop();
        std::cout << "Size: " << strBuf->getSize() << " String: " << strBuf->get(0) << strBuf->get(1) << std::endl;
    *///ENDTEST//

    /*//TEST - Instruction Buffer//
    instrBuf->push(new Pushscal("x"));
    instrBuf->push(new Pop());
    instrBuf->push(new Pushi(5));
    for (int i = 0; i < instrBuf->getBufSize(); i++) {
        std::cout << instrBuf->getStmt(i)->toPrint() << std::endl;
    }
    instrBuf->remove(1);
    std::cout << std::endl;
    for (int i = 0; i < instrBuf->getBufSize(); i++) {
        std::cout << instrBuf->getStmt(i)->toPrint() << std::endl;
    }
    *///ENDTEST

}