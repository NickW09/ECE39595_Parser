#include "Debug.h"

Debug::Debug(const char* input, const char* output) {
    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    StringBuffer* strBuf = StringBuffer::getInstance();
    ToDoBuffer* toDoBuf = ToDoBuffer::getInstance();
    Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf, toDoBuf);
    parser->beginParser();

}

Debug::~Debug() {

}

void Debug::test() {

}

int Debug::numTests = 0;
int Debug::numCorrectTests = 0;

void Debug::compareOutput() {

}