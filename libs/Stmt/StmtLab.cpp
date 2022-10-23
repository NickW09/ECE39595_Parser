#include "StmtLab.h"


StmtLab::StmtLab() {
	instr = "Lab";
}

//toPrints out instruction, may be overrided if needed
std::string StmtLab::toPrint() {
	return instr + " " + lab + ", (" + "#" + ")";
}

//function to be used for overriding purposes (for example see GoSubLabel)
std::string StmtLab::toPrint2() {
	return instr + " " + lab;
}

//function to be used for overriding purposes (for example see GoSubLabel)
std::string StmtLab::toPrint3() {
	return instr + ", " + "#";
}