#include "GoSubLabel.h"

GoSubLabel::GoSubLabel(std::string _lab) {
	instr = "GoSubLabel";
	opcode = 0x00000015; //OP_ENTER_SUBROUTINE
	lab = _lab;
}

void GoSubLabel::action() {

}

std::string GoSubLabel::toString() {
	return toString2();
}