#include "Jump.h"

Jump::Jump(std::string _lab) {
	instr = "Jump";
	opcode = 0x00000010;
	lab = _lab;
}

void Jump::action() {

}

std::string Jump::toPrint() {
	return toPrint3();
}