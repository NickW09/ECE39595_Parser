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
    void toLowerCase(char* string);

private:
    ReadWrite(const char* inputfile, const char* outputfile); //DONE
    char* grabLine(); //DONE
    char* readLine(const char* curLine); 
    void lineSize(const char* str); //DONE
    int instrLen;
    int paramLen;
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
    bool validInputFile; //DONE
};

#endif /* READWRITE_H_ */

