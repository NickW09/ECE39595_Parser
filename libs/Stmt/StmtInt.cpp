#include "StmtInt.h"


StmtInt::StmtInt() {
	instr = "Int";
}

//toPrints out instruction, may be overrided if needed
std::string StmtInt::toPrint() {
	return instr + "  (" + std::to_string(num) + ")";
}