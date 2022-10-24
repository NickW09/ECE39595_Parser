#include "GoSubLabel.h"

GoSubLabel::GoSubLabel(std::string _lab) {
	instr = "GoSubLabel";
	opcode = 0x00000015; //OP_ENTER_SUBROUTINE
	lab = _lab;
	len = -99; //uses len, not loc
}

void GoSubLabel::action() {

}

std::string GoSubLabel::toString() {
	loc = len;
	return toString2();
}

void GoSubLabel::setLength(int _len) {
	len = _len;
}