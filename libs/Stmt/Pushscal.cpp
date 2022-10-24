#include "Pushscal.h"


Pushscal::Pushscal(std::string _var, int _depth) {
	instr = "PushScalar";
	opcode = 0x00000020;
	var = _var;
	depth = _depth;
}

void Pushscal::action() {

}