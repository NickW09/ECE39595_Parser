#include "StmtVar.h"


StmtVar::StmtVar() {
	instr = "Var";
}

//toPrints out instruction, may be overrided if needed
std::string StmtVar::toPrint() {
	return instr + " " + var + ", (" + "#" + ")";
}