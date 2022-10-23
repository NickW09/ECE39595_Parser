#include "StmtInt.h"


StmtInt::StmtInt() {
	instr = "Int";
}

//toStrings out instruction, may be overrided if needed
std::string StmtInt::toString() {
	return instr + "  (" + std::to_string(num) + ")";
}