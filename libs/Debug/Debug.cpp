#include "Debug.h"

int Debug::numTests = 0;
int Debug::numCorrectTests = 0;

//Input: Input file to parse |
void Debug::test(const char* input, const char* output, const char* output_compare) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Test #" << numTests << std::endl;
    numTests++;
    startParser(input, output);
    compareOutput(output, output_compare);
    std::cout << "----------------------------------------" << std::endl;
}

void Debug::startParser(const char* input, const char* output) {
    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    StringBuffer* strBuf = StringBuffer::getInstance();
    ToDoBuffer* toDoBuf = ToDoBuffer::getInstance();
    Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf, toDoBuf);
    int error = parser->beginParser(); 
    parser->~Parser();
    instrBuf->~InstructionBuffer();
    symTable->~SymbolTable();
    strBuf->~StringBuffer();
    toDoBuf->~ToDoBuffer();
    
}

void Debug::compareOutput(const char* output, const char* output_compare) {
    std::ifstream actual;
    std::ifstream ideal;
    actual.open(output);
    ideal.open(output_compare);
    int line_count = 0;
    int error = 0;

    if (!actual) {
        std::cout << "Unable to open: " << output << std::endl;
        actual.close();
        ideal.close();
    }
    if (!ideal) {
        std::cout << "Unable to open: " << output_compare << std::endl;
        actual.close();
        ideal.close();
    }

    while (!ideal.eof()) {
        if (actual.eof()) {
            //std::cout << "Failure at line: " << line_count << std::endl;
            actual.close();
            ideal.close();
            return;
        }
        else {
            char* _line_actual = new char[100];
            char* _line_ideal = new char[100];
            actual.getline(_line_actual, 100, '\n');
            ideal.getline(_line_ideal, 100, '\n');
            std::string line_actual = deleteSpaces(_line_actual);
            std::string line_ideal = deleteSpaces(_line_ideal);
            if (!(line_actual == line_ideal)) {
                std::cout << "Failure at line: " << line_count << std::endl;
                std::cout << "Correct: " << _line_ideal << " | " << "Actual: " << _line_actual << std::endl;
                std::cout << "-" << std::endl;
                error = 1;
            }
            delete[] _line_actual;
            delete[] _line_ideal;
        }
        line_count++;
    }
    actual.close();
    ideal.close();
    numCorrectTests = (error == 0) ? numCorrectTests + 1 : numCorrectTests + 0;
}

std::string Debug::deleteSpaces(char* _str) {

    std::string str = _str;

    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    return str;

}

void Debug::score() {
    std::cout << "SCORE: " << numCorrectTests << "/" << numTests << std::endl;
}