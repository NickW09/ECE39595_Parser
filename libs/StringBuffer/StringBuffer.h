#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

#include <iostream>
#include <fstream>
#include <vector>

class StringBuffer {

public:
    static StringBuffer* getInstance(); //DONE
    void push(std::string str); //DONE maybe
    std::string get(int i); //DONE maybe


private:
    StringBuffer();
    static StringBuffer* strBuf; 
    std::vector<std::string> vec;
};

#endif /* STRINGBUFFER_H_ */
