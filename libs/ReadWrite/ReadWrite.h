#ifndef READWRITE_H_
#define READWRITE_H_
#include <iostream>
#include <fstream>

class ReadWrite {

public:
    static ReadWrite* getInstance(const char* inputfile, const char* outputfile); //DONE
    ~ReadWrite(); //DONE
    char* readLine(); 
    char* readWord(char* curLine); 
    int readInt(); 
    void writeLine();
    std::ifstream getInputFile();  
    std::ofstream getOutputFile();  
    void setValidInputFile(bool _error); 
    bool getValidInputFile(); 

private:
    ReadWrite(const char* inputfile, const char* outputfile); //DONE
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
    bool validInputFile; //DONE
};

#endif /* READWRITE_H_ */

