#include "ReadWrite.h"
#include <fstream>
#include <iostream>

//TEST HI DAVID
//Test again

// ------------------ Public ------------------

// Checks if ReadWrite object has been defined or not, if not, it
// gets defined.
ReadWrite* ReadWrite::getInstance(const char* inputfile, const char* outputfile){
    if(readwrite == nullptr){
        readwrite = new ReadWrite(inputfile, outputfile);
    }
    return readwrite;
}

// Deconstructor
ReadWrite::~ReadWrite(){
    readFile.close();
    writeFile.close();
}

    
// Returns the next instruction read from readWrite.
// Returns nullptr when end of file is reached.
char* ReadWrite::readInstruction() {
    char* line = grabLine();
    char* instr = nullptr;
    if (line != nullptr) { //If not at end of file
        instr = readLine(line);
        delete line;
    }
    return instr;
}


int ReadWrite::charToInt(){
    return 0; //temp
}


void ReadWrite::writeLine(){

}


void ReadWrite::setValidInputFile(bool _error){
    validInputFile = _error;
}


bool ReadWrite::getValidInputFile(){
    return validInputFile;
}

// ------------------ Private ------------------

ReadWrite* ReadWrite::readwrite = nullptr;


//Constructor
ReadWrite::ReadWrite(const char* inputfile, const char* outputfile){
    readFile.open(inputfile); //Open input file
    writeFile.open(outputfile); //Open output file
    if (!readFile) { //Check if input file opened properly
        std::cout << "Error: " << inputfile << " Does Not Exist." << std::endl;
        validInputFile = false;
    }
    else {
        validInputFile = true;
    }
    instrLen = 0; //Initializing instr length
    paramLen = 0; //Initializing param length
}


// Grabs the next line to read from readFile, and returns the line.
// The returned char* must be freed after use.
char* ReadWrite::grabLine() {
    char* line = nullptr;
    if (!readFile.eof()) { //Check if end of file
        line = new char[100];
        readFile.getline(line, 100, '\n');
    }
    else {
        std::cout << "End of File (EOF)." << std::endl;
    }
    return line;
}

//MUST BE FREED
char* ReadWrite::readLine(const char* curLine) {
    std::cout << "Line read:" << std::endl;

    lineSize(curLine); //Finds word size
    char* instr = new char[instrLen + 1];
    char* param;

    int count = 0;
    for (count; (count < instrLen); count++) { //Storing instruction
        instr[count] = curLine[count];
    }
    count++;

    instr[instrLen] = '\0';
    std::cout << "instr: " << instr << std::endl;

    if (paramLen > 0) { //Check if param is available
        param = new char[paramLen + 1];
        for (count; count <= (instrLen + paramLen); count++) { //Storing param
            param[count - instrLen - 1] = curLine[count];
        }
        param[paramLen] = '\0';
        std::cout << "param: " << param << std::endl;
    }

    //set param as int, variable, label

    return instr;
}

void ReadWrite::lineSize(const char* str) {
    char ch = str[0];
    int count = 0;

    for (count; (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'); count++) { //this checks for a valid character input
        ch = str[count];
    }
    count--;
    instrLen = count;

    if (str[count] == 32 /*space*/) {
        count++;
        ch = str[count];
        for (count; (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'); count++) {
            ch = str[count];
        }
    }
   
    paramLen = count - instrLen - 2;

    //std::cout << "instrLen: " << instrLen << std::endl;
    //std::cout << "paramLen: " << paramLen << std::endl;
}



