#include "Poparr.h"


Poparr::Poparr(std::string _var, int _depth) {
	instr = "PopArray";
	opcode = 0x00000031;
	var = _var;
	depth = _depth;
}

void Poparr::action() {

}