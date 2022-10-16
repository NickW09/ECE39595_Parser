#include "InstructionBuffer.h"

// ------------ Public ------------
//InstructionBuffer::~InstructionBuffer(){

//}

InstructionBuffer* InstructionBuffer::getInstance(){
    if(instrBuf == nullptr) {
        instrBuf = new InstructionBuffer();
    }
    return instrBuf;
}

void InstructionBuffer::AddToBuf(Stmt* statement){
    vec.push_back(statement);
}

//------------ Private ------------

InstructionBuffer* InstructionBuffer::instrBuf = nullptr;

InstructionBuffer::InstructionBuffer(){

}
    