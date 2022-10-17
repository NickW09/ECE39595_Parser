#include "StmtNone.h"


StmtNone::StmtNone() {
	instr = "None";
}

//prints out instruction, may be overrided if needed
void StmtNone::print() {
	std::cout << instr << std::endl;
}