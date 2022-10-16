#include "ToDoBuffer.h"

// ------------ Public ------------
ToDoBuffer::~ToDoBuffer(){

}

ToDoBuffer* ToDoBuffer::getInstance(){
    if(todoBuf == nullptr) {
        todoBuf = new ToDoBuffer();
    }
    return todoBuf;
}

void ToDoBuffer::AddToBuf(Stmt* statement){
    vec.push_back(statement);
}

//------------ Private ------------

ToDoBuffer* ToDoBuffer::todoBuf = nullptr;

ToDoBuffer::ToDoBuffer(){

}
    