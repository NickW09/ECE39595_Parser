#include "Stmt.h"


Stmt::Stmt() {
	opcode = 0x00000000; //purposely bad opcode for debugging purposes
	instr = "Stmt";
}

void Stmt::print() {
	std::cout << toString() << std::endl;
}

uint32_t Stmt::getOp() {
	return opcode;
}

int Stmt::getData() {
	return 0;
}