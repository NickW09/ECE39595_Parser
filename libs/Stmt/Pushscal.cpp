#include "Pushscal.h"


Pushscal::Pushscal(std::string _var, int _depth, int _loc) : StmtVar(_var, _depth, _loc) {
	instr = "PushScalar";
	opcode = 0x00000020;
}

void Pushscal::action() {

}