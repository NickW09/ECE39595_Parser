#include "Start.h"

Start::Start() {
	instr = "Start";
	opcode = 0x00000017;
	length = -99;
}

void Start::action() {

}

void Start::setLength(int _length) {
	length = _length;
}

std::string Start::toString() {
	return instr + " " + std::to_string(length);
}

int Start::getData() {
	return length;
}