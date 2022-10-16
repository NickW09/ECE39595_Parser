#ifndef READWRITE_H_
#define READWRITE_H_
#include <iostream>
#include <fstream>

class ReadWrite {

public:
    static ReadWrite* getInstance(char* inputfile, char* outputfile); //DONE
    ~ReadWrite(); //DONE
    char* readLine(); 
    char* readWord(char* curLine); 
    int readInt(); 
    void writeLine();
    void setInputFile(char* txtFile); 
    std::ifstream getInputFile(); 
    void setOutputFile(char* txtFile); 
    std::ofstream getOutputFile();  
    void setValidInputFile(); 
    bool getValidInputFile(); 

private:
    ReadWrite(char* inputfile, char* outputfile); //DONE
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
    bool validInputFile; //DONE
};

#endif /* READWRITE_H_ */

