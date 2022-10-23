#include "Popscal.h"

Popscal::Popscal(std::string _var) {
	instr = "OP_POPSCALAR";
	opcode = 0x00000030;
	var = _var;
}

void Popscal::action() {

}