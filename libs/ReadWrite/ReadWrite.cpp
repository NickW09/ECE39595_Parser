#include "ReadWrite.h"
#include <fstream>
#include <iostream>

// ------------------ Public ------------------

ReadWrite* ReadWrite::getInstance(const char* inputfile, const char* outputfile){
    if(readwrite == nullptr){
        readwrite = new ReadWrite(inputfile, outputfile);
    }
    return readwrite;
}

ReadWrite::~ReadWrite(){
    readFile.close();
    writeFile.close();
}
    
//Returns nullptr when nothing left to read
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
    lineLen = 0; //Initializing word length
}

//MUST BE FREED
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
    std::cout << "Line read: ";

    lineSize(curLine); //Finds word size
    char* line = new char[lineLen + 1];
    for (int i = 0; i < lineLen /*and curLine[i] != space or newline*/; i++) {
        //std::cout << i << std::endl;
        line[i] = curLine[i];
    }
    //for (int i = /*past i*/; i < lineLen; i++) {
        //store new thing
    //}
    line[lineLen] = '\0';
    std::cout << line << std::endl;

    return line; 
}

void ReadWrite::lineSize(const char* str) {
    char ch = str[0];
    int size = 0;
    for (size = 0; (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 32; size++) { //this checks for a valid character input
        ch = str[size];
    }
    std::cout << size << std::endl;
    lineLen = size == 0 ? 0 : (size - 1); //temp
}



