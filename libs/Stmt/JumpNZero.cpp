#include "JumpNZero.h"

JumpNZero::JumpNZero(std::string _lab) {
	instr = "JumpNZero";
	opcode = 0x00000012;
	lab = _lab;
}

void JumpNZero::action() {

}

std::string JumpNZero::toString() {
	return toString2();
}