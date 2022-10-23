#include "Pushscal.h"


Pushscal::Pushscal(std::string _var) {
	instr = "OP_PUSHSCALAR";
	opcode = 0x00000020;
	var = _var;
}

void Pushscal::action() {

}