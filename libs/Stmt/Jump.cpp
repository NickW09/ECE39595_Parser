#include "Jump.h"

Jump::Jump(std::string _lab) {
	instr = "OP_JUMP";
	opcode = 0x00000010;
	lab = _lab;
}

void Jump::action() {

}

std::string Jump::toString() {
	return toString3();
}