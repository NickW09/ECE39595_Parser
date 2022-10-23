#include "StmtNone.h"


StmtNone::StmtNone() {
	instr = "None";
}

//toStrings out instruction, may be overrided if needed
std::string StmtNone::toString() {
	return instr;
}