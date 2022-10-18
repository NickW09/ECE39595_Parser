#ifndef READWRITE_H_
#define READWRITE_H_
#include <iostream>
#include <fstream>

class ReadWrite {

public:
    static ReadWrite* getInstance(const char* inputfile, const char* outputfile); //DONE
    ~ReadWrite(); //DONE
    char* readInstruction(); //DONE
    int readInt(); 
    void writeLine();
    std::ifstream getInputFile();  
    std::ofstream getOutputFile();  
    void setValidInputFile(bool _error); 
    bool getValidInputFile(); 

private:
    ReadWrite(const char* inputfile, const char* outputfile); //DONE
    char* readLine(); //DONE
    char* readWord(const char* curLine); //DONE
    void wordSize(const char* str); //DONE
    int wordLen;
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
    bool validInputFile; //DONE
};

#endif /* READWRITE_H_ */

