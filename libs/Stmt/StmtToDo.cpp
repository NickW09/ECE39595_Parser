#include "StmtToDo.h"

StmtToDo::StmtToDo() {
	instr = "ToDo";
	loc = -99;
}

//sets the location at which the label is in the symbol table
void StmtToDo::setLoc(int _loc) {
	loc = _loc;
}

std::string StmtToDo::getVar() {
	return var;
}
