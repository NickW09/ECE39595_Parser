#include "StringBuffer.h"

StringBuffer* StringBuffer::strBuf = nullptr;

//Constructor
StringBuffer::StringBuffer(){
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

