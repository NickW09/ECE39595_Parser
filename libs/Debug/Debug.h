#ifndef DEBUG_H_
#define DEBUG_H_
#include <iostream>
#include "..\InstructionBuffer\InstructionBuffer.h"
#include "..\Parser\Parser.h"
#include "..\ReadWrite\ReadWrite.h"
#include "..\Stmt\Stmt.h"
#include "..\StringBuffer\StringBuffer.h"
#include "..\ToDoBuffer\ToDoBuffer.h"
#include "..\SymbolTable\SymbolTable.h"

class Debug {

public:
	Debug(const char* input, const char* output);
	~Debug();
	void test();

private:
	static int numTests;
	static int numCorrectTests;
	void compareOutput();
};

#endif /* DEBUG_H_ */