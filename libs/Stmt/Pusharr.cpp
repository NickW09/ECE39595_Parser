#include "Pusharr.h"

Pusharr::Pusharr(std::string _var, int _depth, int _loc) : StmtVar(_var, _depth, _loc) {
	instr = "PushArray";
	opcode = 0x00000021;
}

void Pusharr::action() {

}