#include "Poparr.h"


Poparr::Poparr(std::string _var) {
	instr = "OP_POPARRAY";
	opcode = 0x00000031;
	var = _var;
}

void Poparr::action() {

}