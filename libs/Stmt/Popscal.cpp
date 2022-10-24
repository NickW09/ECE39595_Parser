#include "Popscal.h"

Popscal::Popscal(std::string _var, int _depth) {
	instr = "PopScalar";
	opcode = 0x00000030;
	var = _var;
	depth = _depth;
}

void Popscal::action() {

}