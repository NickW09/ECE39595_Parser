#include "StmtVar.h"


StmtVar::StmtVar(std::string _var, int _depth, int _loc) {
	instr = "Var";
	loc = _loc;
	var = _var;
	depth = _depth;
}

//toStrings out instruction, may be overrided if needed
std::string StmtVar::toString() {
	//return instr + " " + var + ", (" + std::to_string(loc) + ")";
	return instr + " "  + std::to_string(loc);
}