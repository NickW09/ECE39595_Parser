#include "ReadWrite.h"

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

// Updates instruction and parameters in ReadWrite class both the cases and babymonoprop m boo love zoo butbuut not my very
void ReadWrite::updateInstruction() {
    std::string line = grabLine();
    if (!endOfFile) { //If not at end of file
        instruction.clear();
        param1.clear();
        param2.clear();
        readLine(line);
    }
    else {
        std::cout << "EOF detected." << std::endl;
    }
}

//Write to output file
void ReadWrite::writeLine(std::string str){
    writeFile << str;
    std::cout << str << std::endl;
}

std::string ReadWrite::getInstruction() {
    return instruction;
}

std::string ReadWrite::getParam1() {
    return param1;
}

std::string ReadWrite::getParam2() {
    return param2;
}

//Check if end of file reached
bool ReadWrite::getEOF() {
    return endOfFile;
}

//Converts string to int
int ReadWrite::stringToInt(std::string str) {
    return(std::stoi(str));
}

//Return integer parameter
int ReadWrite::getInt() {
    if (!param2.empty() || param1.empty()) {
        errorFlag = true;
        std::cout << "Invalid Instruction." << std::endl;
    }
    return(stringToInt(param1));
}

//Return variable parameter
std::string ReadWrite::getVariable() {
    if (!param2.empty() || param1.empty()) {
        errorFlag = true;
        std::cout << "Invalid Instruction." << std::endl;
    }
    return(param1);
}

//Return integer and variable parameters
int ReadWrite::getIntVar(std::string& var) {
    if (param2.empty() || param1.empty()) {
        errorFlag = true;
        std::cout << "Invalid Instruction." << std::endl;
    }
    var = param2;
    return(stringToInt(param1));
}

//Return label parameter
std::string ReadWrite::getLabel() {
    if (!param2.empty() || param1.empty()) {
        errorFlag = true;
        std::cout << "Invalid Instruction." << std::endl;
    }
    return(param1);
}


// ------------------ Private ------------------

ReadWrite* ReadWrite::readwrite = nullptr;


//Constructor
ReadWrite::ReadWrite(const char* inputfile, const char* outputfile){
    readFile.open(inputfile); //Open input file
    writeFile.open(outputfile); //Open output file
    endOfFile = false;
    errorFlag = false;
    if (!readFile) { //Check if input file opened properly
        std::cout << "Error: " << inputfile << " Does Not Exist." << std::endl;
        errorFlag = true;
    }
}


// Grabs the next line to read from readFile, and returns the line.
std::string ReadWrite::grabLine() {
    std::string line;
    if (!readFile.eof()) { //Check if end of file
        char* line_char = new char[100];
        readFile.getline(line_char, 100, '\n');
        line = line_char;
        delete[] line_char;
    }
    else {
        std::cout << "End of File (EOF)." << std::endl;
        endOfFile = true;
    }
    return line;
}

//Reads most recent line grabbed, and sets the instruction
//and parameters from the line.
void ReadWrite::readLine(std::string curLine) {
    std::cout << "Line read:" << std::endl;

    std::string::iterator ch;
    ch = curLine.begin();

    for (int i = 0; ch != curLine.end() && *ch != 32; i++) {
        instruction.append(sizeof(char), *ch);
        ch++;
    }
    
    ch = (ch == curLine.end()) ? ch + 0 : ch + 1;

    for (int i = 0; ch != curLine.end() && *ch != 32; i++) {
        param1.append(sizeof(char), *ch);
        ch++;
    }

    ch = (ch == curLine.end()) ? ch + 0 : ch + 1;

    for (int i = 0; ch != curLine.end() && *ch != 32; i++) {
        param2.append(sizeof(char), *ch);
        ch++;
    }

    toLowerCase(instruction);
}

//Converts a string to all lower case
void ReadWrite::toLowerCase(std::string& string) {

    std::string::iterator ch;

    for (ch = string.begin(); ch != string.end(); ch++) {
        if ((*ch >= 'A') && (*ch <= 'Z')) {
            *ch = (*ch) + 32;
        }
    }
}