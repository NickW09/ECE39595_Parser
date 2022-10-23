#include "Debug.h"

int Debug::numTests = 0;
int Debug::numCorrectTests = 0;

//Input: Input file to parse |
void Debug::test(const char* input, const char* output, const char* output_compare) {
    numTests++;
    InstructionBuffer* instrBuf = InstructionBuffer::getInstance();
    SymbolTable* symTable = SymbolTable::getInstance();
    StringBuffer* strBuf = StringBuffer::getInstance();
    ToDoBuffer* toDoBuf = ToDoBuffer::getInstance();
    Parser* parser = Parser::getInstance(input, output, instrBuf, symTable, strBuf, toDoBuf);
    parser->beginParser();
    compareOutput(output, output_compare);
}

void Debug::compareOutput(const char* output, const char* output_compare) {
    std::ifstream actual;
    std::ifstream ideal;
    actual.open(output);
    ideal.open(output_compare);
    int line_count = 0;

    while (!ideal.eof()) {
        if (actual.eof()) {
            std::cout << "Failure at line: " << line_count << std::endl;
            actual.close();
            ideal.close();
            return;
        }
        else {
            char* _line_actual = new char[100];
            char* _line_ideal = new char[100];
            actual.getline(_line_actual, 100, '\n');
            ideal.getline(_line_ideal, 100, '\n');
            std::string line_actual = _line_actual;
            std::string line_ideal = _line_ideal;
            delete[] _line_actual;
            delete[] _line_ideal;
            if (!(line_actual == line_ideal)) {
                std::cout << "Failure at line: " << line_count << std::endl;
                std::cout << "Correct: " << line_ideal << " | " << "Actual: " << line_actual << std::endl;
            }
        }
    }
    actual.close();
    ideal.close();
    numCorrectTests++;
}