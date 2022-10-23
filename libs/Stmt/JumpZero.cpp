#include "JumpZero.h"

JumpZero::JumpZero(std::string _lab, int _depth) {
	instr = "OP_JUMPZERO";
	opcode = 0x00000011;
	lab = _lab;
	depth = _depth;
}

void JumpZero::action() {

}

std::string JumpZero::toString() {
	return toString2();
}