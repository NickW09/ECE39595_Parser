#include "StmtLab.h"


StmtLab::StmtLab() {
	instr = "Lab";
	loc = -99;
	isStmtLab = true;
}

//sets the location at which the label is in the symbol table
void StmtLab::setLoc(int _loc) {
	loc = _loc;
}

//sets the depth in subroutines the statement is in
void StmtLab::setDepth(int _depth) {
	depth = _depth;
}

//gets the depth in subroutines the statement is in
int StmtLab::getDepth() {
	return depth;
}

std::string StmtLab::getLabel() {
	return lab;
}

std::string StmtLab::getVar() {
	return getLabel();
}

//toStrings out instruction, may be overrided if needed
std::string StmtLab::toString() {
	return instr + " " + std::to_string(loc);
}

//function to be used for overriding purposes (for example see GoSubLabel)
std::string StmtLab::toString2() {
	return instr + " " + std::to_string(loc);
}

//function to be used for overriding purposes (for example see GoSubLabel)
std::string StmtLab::toString3() {
	return instr + " " + std::to_string(loc);
}