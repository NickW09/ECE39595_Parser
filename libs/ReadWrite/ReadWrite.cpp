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
    
//MUST BE FREED
char* ReadWrite::readLine(){
    char* line = new char[30];
    readFile.getline(line, 30, '\n');
    return line;
}

char* ReadWrite::readWord(char* curLine){
    
}

int ReadWrite::readInt(){
    
}

void ReadWrite::writeLine(){

}

std::ifstream ReadWrite::getInputFile(){
    
}

std::ofstream ReadWrite::getOutputFile(){
    
}

void ReadWrite::setValidInputFile(bool _error){
    validInputFile = _error;
}

bool ReadWrite::getValidInputFile(){
    return validInputFile;
}

// ------------------ Private ------------------

static ReadWrite* readwrite = nullptr;

ReadWrite::ReadWrite(const char* inputfile, const char* outputfile){
    readFile.open(inputfile); //Open input file
    writeFile.open(outputfile); //Open output file
    validInputFile = true;
}



