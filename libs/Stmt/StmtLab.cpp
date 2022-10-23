#include "StmtLab.h"


StmtLab::StmtLab() {
	instr = "Lab";
}

//toStrings out instruction, may be overrided if needed
std::string StmtLab::toString() {
	return instr + " " + lab + ", (" + "#" + ")";
}

//function to be used for overriding purposes (for example see GoSubLabel)
std::string StmtLab::toString2() {
	return instr + " " + lab;
}

//function to be used for overriding purposes (for example see GoSubLabel)
std::string StmtLab::toString3() {
	return instr + ", " + "#";
}