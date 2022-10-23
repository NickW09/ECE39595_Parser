#include "Pushi.h"


Pushi::Pushi(int _num) {
	instr = "PushI";
	opcode = 0x00000022;
	num = _num;
}

void Pushi::action() {

}