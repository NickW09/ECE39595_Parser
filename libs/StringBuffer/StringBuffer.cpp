#include "StringBuffer.h"

StringBuffer* StringBuffer::strBuf = nullptr;

//Constructor
StringBuffer::StringBuffer(){
    vec = std::vector<std::string>();
}

//possibly creates then returns singleton
StringBuffer* StringBuffer::getInstance(){
    if(strBuf == nullptr) {
        strBuf = new StringBuffer();
    }
    return strBuf;
}


//pushes string onto string buffer
void StringBuffer::push(std::string str) {
    vec.push_back(str);
}

//returns string when given an index into strBuf
std::string StringBuffer::get(int i) {
    // std::vector<std::string>::iterator p;
    // p = (*vec).begin();
    // return *p;
    return vec[i];
}

//pops string off of string buffer
void StringBuffer::pop() {
    vec.pop_back();
}

//removes string at index i
void StringBuffer::remove(int i) {
    vec.erase(vec.begin() + i);
}


//return size of string buffer
int StringBuffer::getSize() {
    return vec.size();
}
