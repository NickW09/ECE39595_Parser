#ifndef DEBUG_H_
#define DEBUG_H_
#include <iostream>
#include <string>
#include <fstream>
#include "..\InstructionBuffer\InstructionBuffer.h"
#include "..\Parser\Parser.h"
#include "..\ReadWrite\ReadWrite.h"
#include "..\Stmt\Stmt.h"
#include "..\StringBuffer\StringBuffer.h"
#include "..\ToDoBuffer\ToDoBuffer.h"
#include "..\SymbolTable\SymbolTable.h"

class Debug {

public:
	static void test(const char* input, const char* output, const char* output_compare);

private:
	static int numTests;
	static int numCorrectTests;
	static void startParser(const char* input, const char* output);
	static void compareOutput(const char* output, const char* output_compare);
};

#endif /* DEBUG_H_ */