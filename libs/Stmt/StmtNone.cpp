#include "StmtNone.h"


StmtNone::StmtNone() {
	instr = "None";
}

//toPrints out instruction, may be overrided if needed
std::string StmtNone::toPrint() {
	return instr;
}