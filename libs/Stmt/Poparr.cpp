#include "Poparr.h"


Poparr::Poparr(std::string _var) {
	instr = "PopArray";
	opcode = 0x00000031;
	var = _var;
}

void Poparr::action() {

}