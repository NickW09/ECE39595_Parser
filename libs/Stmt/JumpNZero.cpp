#include "JumpNZero.h"

JumpNZero::JumpNZero(std::string _lab) {
	instr = "JumpNZero";
	opcode = 0x00000013;
	lab = _lab;
}

void JumpNZero::action() {

}

std::string JumpNZero::toPrint() {
	return toPrint2();
}