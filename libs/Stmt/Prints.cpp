#include "Prints.h"

Prints::Prints(int i) {
	instr = "OP_PRINTS";
	opcode = 0x00000060;
	num = i;
}

void Prints::action() {

}