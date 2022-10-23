#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

#include <iostream>
#include <fstream>
#include <vector>

class StringBuffer {

public:
    static StringBuffer* getInstance(); //DONE
    ~StringBuffer();                    //DONE
    void push(std::string str);         //DONE
    std::string get(int i);             //DONE
    void pop();                         //DONE
    void remove(int i);                 //DONE
    int getSize();                      //DONE


private:
    StringBuffer();
    static StringBuffer* strBuf; 
    std::vector<std::string> vec;
};

#endif /* STRINGBUFFER_H_ */
