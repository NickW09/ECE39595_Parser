#include "Poparr.h"


Poparr::Poparr(std::string _var, int _depth, int _loc) : StmtVar(_var, _depth, _loc) {
	instr = "PopArray";
	opcode = 0x00000031;
}

void Poparr::action() {

}