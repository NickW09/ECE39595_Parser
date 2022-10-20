#ifndef READWRITE_H_
#define READWRITE_H_
#include <iostream>
#include <fstream>

class ReadWrite {

public:
    static ReadWrite* getInstance(const char* inputfile, const char* outputfile); //DONE
    ~ReadWrite(); //DONE
    char* readInstruction(); 
    int charToInt(); 
    void writeLine();  
    void setValidInputFile(bool _error); 
    bool getValidInputFile(); 
    int getInt();
    char* getVariable();
    char* getLabel();

private:
    ReadWrite(const char* inputfile, const char* outputfile); //DONE
    char* grabLine(); //DONE
    char* readLine(const char* curLine); //DONE
    void lineSize(const char* str); //DONE
    int lineLen;
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
    bool validInputFile; //DONE
};

#endif /* READWRITE_H_ */

