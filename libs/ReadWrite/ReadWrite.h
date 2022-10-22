#ifndef READWRITE_H_
#define READWRITE_H_
#include <iostream>
#include <fstream>

class ReadWrite {

public:
    static ReadWrite* getInstance(const char* inputfile, const char* outputfile); //DONE
    ~ReadWrite(); //DONE
    std::string getInstruction();
    std::string getParam1();
    std::string getParam2();
    void updateInstruction(); 
    void writeLine(std::string str);
    //int charToInt(); 
    //void writeLine();  
    //int getInt();
    //std::string getVariable();
    //char* getLabel();

private:
    ReadWrite(const char* inputfile, const char* outputfile); //DONE
    std::string instruction;
    std::string param1;
    std::string param2;
    std::string grabLine(); //DONE
    void readLine(std::string curLine);
    void toLowerCase(std::string& str);
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
};

#endif /* READWRITE_H_ */

