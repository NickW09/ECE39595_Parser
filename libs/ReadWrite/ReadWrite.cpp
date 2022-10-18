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
    
char* ReadWrite::readInstruction() {
    char* line = readLine();
    char* instr = readWord(line);
    delete line;
    return instr;
}

int ReadWrite::readInt(){
    return 0; //temp
}

void ReadWrite::writeLine(){

}

std::ifstream ReadWrite::getInputFile(){
    std::ifstream stream; //temp
    return stream;  //temp
}

std::ofstream ReadWrite::getOutputFile(){
    std::ofstream stream; //temp
    return stream;  //temp
}

void ReadWrite::setValidInputFile(bool _error){
    validInputFile = _error;
}

bool ReadWrite::getValidInputFile(){
    return validInputFile;
}

// ------------------ Private ------------------

ReadWrite* ReadWrite::readwrite = nullptr;

ReadWrite::ReadWrite(const char* inputfile, const char* outputfile){
    readFile.open(inputfile); //Open input file
    writeFile.open(outputfile); //Open output file
    validInputFile = true;
    wordLen = 0;
}

//MUST BE FREED
char* ReadWrite::readLine() {
    char* line = new char[100];
    readFile.getline(line, 100, '\n');
    return line;
}

//MUST BE FREED
char* ReadWrite::readWord(const char* curLine) {
    std::cout << "Word search." << std::endl;

    wordSize(curLine); //Finds word size
    char* word = new char[wordLen + 1];
    for (int i = 0; i < wordLen; i++) {
        std::cout << i << std::endl;
        word[i] = curLine[i];
    }
    word[wordLen] = '\0';

    return word; //temp
}

void ReadWrite::wordSize(const char* str) {
    std::cout << "Word size = ";
    char ch = str[0];
    int size = 0;
    for (size = 0; ch != 32; size++) {
        ch = str[size];
    }

    wordLen = size - 1; //temp
    std::cout << wordLen << std::endl;
}



