#include "GoSub.h"

GoSub::GoSub(std::string _lab, int _depth) {
	instr = "GoSub";
	opcode = 0x00000013;
	lab = _lab;
	depth = _depth;
}

void GoSub::action() {

}