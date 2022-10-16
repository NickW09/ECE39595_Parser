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
    
char* ReadWrite::readLine(){
    
}
char* ReadWrite::readWord(char* curLine){
    
}
int ReadWrite::readInt(){
    
}
void ReadWrite::writeLine(){

}
void ReadWrite::setInputFile(char* txtFile){
    
}
std::ifstream ReadWrite::getInputFile(){
    
}
void ReadWrite::setOutputFile(char* txtFile){
    
}
std::ofstream ReadWrite::getOutputFile(){
    
}
void ReadWrite::setValidInputFile(){
    
}
bool ReadWrite::getValidInputFile(){
    
}

// ------------------ Private ------------------

static ReadWrite* readwrite = nullptr;

ReadWrite::ReadWrite(const char* inputfile, const char* outputfile){
    readFile.open(inputfile); //Open input file
    writeFile.open(outputfile); //Open output file
    validInputFile = true;
}



