#include "InstructionBuffer.h"

// ------------ Public ------------
InstructionBuffer::~InstructionBuffer(){
    vec.clear();
    instrBuf = nullptr;
}

InstructionBuffer* InstructionBuffer::getInstance(){
    if(instrBuf == nullptr) {
        instrBuf = new InstructionBuffer();
    }
    return instrBuf;
}

void InstructionBuffer::push(Stmt* statement){
    vec.push_back(statement);
}

//return number of statements in buffer
int InstructionBuffer::getSize() {
    return (int) vec.size();
}

//return statement at specified index
Stmt* InstructionBuffer::getStmt(int i) {
    return vec[i];
}

//remove instruction at specified index
void InstructionBuffer::remove(int i) {
    vec.erase(vec.begin() + i);
}

//------------ Private ------------

InstructionBuffer* InstructionBuffer::instrBuf = nullptr;

InstructionBuffer::InstructionBuffer(){

}
    