#include "GoSub.h"

GoSub::GoSub(std::string _lab) {
	instr = "OP_GOSUB";
	opcode = 0x00000013;
	lab = _lab;
}

void GoSub::action() {

}