#include "Exit.h"

Exit::Exit() {
	instr = "OP_EXIT_PROGRAM";
	opcode = 0x00000018;
}

void Exit::action() {

}