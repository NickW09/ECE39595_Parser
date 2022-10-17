#include "StmtVarLen.h"


StmtVarLen::StmtVarLen() {
	instr = "Var";
	len = 1;
}

//prints out instruction, may be overrided if needed
void StmtVarLen::print() {
	//std::cout << instr << " " << var << ", (" << "#" << ")" << std::endl;
}