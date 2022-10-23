#include "JumpZero.h"

JumpZero::JumpZero(std::string _lab) {
	instr = "OP_JUMPZERO";
	opcode = 0x00000011;
	lab = _lab;
}

void JumpZero::action() {

}

std::string JumpZero::toString() {
	return toString2();
}