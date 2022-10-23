#include "ToDoBuffer.h"

// ------------ Public ------------
ToDoBuffer::~ToDoBuffer() {
    vec.clear();
    todoBuf = nullptr;
}

ToDoBuffer* ToDoBuffer::getInstance(){
    if(todoBuf == nullptr) {
        todoBuf = new ToDoBuffer();
    }
    return todoBuf;
}

void ToDoBuffer::push(StmtToDo* statement) {
    vec.push_back(statement);
}

//return number of statements in buffer
int ToDoBuffer::getSize() {
    return (int) vec.size();
}

//return statement at specified index
StmtToDo* ToDoBuffer::getStmt(int i) {
    return vec[i];
}

//remove instruction at specified index
void ToDoBuffer::remove(int i) {
    vec.erase(vec.begin() + i);
}
//------------ Private ------------

ToDoBuffer* ToDoBuffer::todoBuf = nullptr;

ToDoBuffer::ToDoBuffer(){

}
    