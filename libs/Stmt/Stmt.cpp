#include "Stmt.h"


Stmt::Stmt() {
	opcode = 0x00000000; //purposely bad opcode for debugging purposes
	instr = "Stmt";
}

void Stmt::print() {
	std::cout << toString() << std::endl;
}