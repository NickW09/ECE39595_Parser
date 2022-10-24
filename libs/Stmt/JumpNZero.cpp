#include "JumpNZero.h"

JumpNZero::JumpNZero(std::string _lab, int _depth) {
	instr = "JumpNZero";
	opcode = 0x00000012;
	lab = _lab;
	depth = _depth;
}

void JumpNZero::action() {

}

std::string JumpNZero::toString() {
	return toString2();
}