#include "Pusharr.h"

Pusharr::Pusharr(std::string _var, int _depth) {
	instr = "PushArray";
	opcode = 0x00000021;
	var = _var;
	depth = _depth;
}

void Pusharr::action() {

}