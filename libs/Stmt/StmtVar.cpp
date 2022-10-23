#include "StmtVar.h"


StmtVar::StmtVar() {
	instr = "Var";
}

//toStrings out instruction, may be overrided if needed
std::string StmtVar::toString() {
	return instr + " " + var + ", (" + std::to_string(loc) + ")";
}