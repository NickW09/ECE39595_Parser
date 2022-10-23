#include "Pusharr.h"

Pusharr::Pusharr(std::string _var) {
	instr = "OP_PUSHARR";
	opcode = 0x00000021;
	var = _var;
}

void Pusharr::action() {

}