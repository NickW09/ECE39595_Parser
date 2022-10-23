#include "Popscal.h"

Popscal::Popscal(std::string _var) {
	instr = "PopScalar";
	opcode = 0x00000030;
	var = _var;
}

void Popscal::action() {

}