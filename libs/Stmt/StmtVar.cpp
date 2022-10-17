#include "StmtVar.h"


StmtVar::StmtVar() {
	instr = "Var";
}

//prints out instruction, may be overrided if needed
void StmtVar::print() {
	std::cout << instr << " " << var << ", (" << "#" << ")" << std::endl;
}