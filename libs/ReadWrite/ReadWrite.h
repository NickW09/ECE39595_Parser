#ifndef READWRITE_H_
#define READWRITE_H_
#include <iostream>
#include <fstream>
#include <string>

class ReadWrite {

public:
    static ReadWrite* getInstance(const char* inputfile, const char* outputfile); //DONE
    ~ReadWrite(); //DONE
    std::string getInstruction(); //DONE
    std::string getParam1(); //DONE
    std::string getParam2(); //DONE
    bool getEOF(); //DONE
    void updateInstruction(); //DONE
    int getInt(); //DONE
    std::string getVariable(); //DONE 
    int getIntVar(std::string& var); //DONE
    std::string getLabel(); //DONE
    bool getError();
    
    void writeLine(std::string); //in-progress  

private:
    ReadWrite(const char* inputfile, const char* outputfile); //DONE
    std::string instruction;//DONE
    std::string param1; //DONE
    std::string param2; //DONE
    std::string grabLine(); //DONE
    bool endOfFile; //DONE
    bool errorFlag;
    void readLine(std::string); //DONE
    void toLowerCase(std::string&); //DONE
    int stringToInt(std::string);
    static ReadWrite* readwrite; //DONE
    std::ifstream readFile; //DONE
    std::ofstream writeFile; //DONE
};

#endif /* READWRITE_H_ */

