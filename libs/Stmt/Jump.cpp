#include "Jump.h"

Jump::Jump(std::string _lab, int _depth) {
	instr = "Jump";
	opcode = 0x00000010;
	lab = _lab;
	depth = _depth;
}

void Jump::action() {

}

std::string Jump::toString() {
	return toString3();
}