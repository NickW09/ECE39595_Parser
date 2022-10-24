#include "Popscal.h"

Popscal::Popscal(std::string _var, int _depth, int _loc) : StmtVar(_var, _depth, _loc) {
	instr = "PopScalar";
	opcode = 0x00000030;
}

void Popscal::action() {

}