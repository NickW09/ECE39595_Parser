#include "Parser.h"

Parser* Parser::parser = nullptr;

//TEST2

//Constructor
Parser::Parser(const char* inputFileName, const char* outputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf) {
    instrBuf = _instrBuf; //Set instructionBuffer
    symTable = _symTable; //Set symbolTable
    strBuf = _strBuf; //Set stringBuffer
    readWrite = ReadWrite::getInstance(inputFileName, outputFileName); //give ReadWriteParser the input and output files
    error = 0;
}

Parser* Parser::getInstance(const char* inputFileName, const char* outputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf){
    if(parser == nullptr) {
        parser = new Parser(inputFileName, outputFileName, _instrBuf, _symTable, _strBuf); // makes unique instantiation
    }
    return parser; // return singleton
}

void Parser::beginParser(){
    printf("Parser Running...");

    char* instr = readWrite->readInstruction(); //Grab initial instruction
    while(instr != nullptr){ //checking if end of file reached
        instr = readWrite->readInstruction();
        int type = determineType(instr);

    }
}

void Parser::createStmt(char* instr){
    //lots of cases
    //convert char* to all lower case

    
}

int Parser::determineType(char* instruction)
{
    readWrite->toLowerCase(instruction);
    std::string instr(instruction);
    int type; 

    //needs int param
    if (instr == "declarr" || instr == "pushi") {
        type = INT_PARAM;
    }
    //needs variable param
    else if (instr == "declscal" || instr == "pushscal" || instr == "pusharr" || instr == "popscal" || instr == "poparr") {
        type = VAR_PARAM;
    }
    //needs label param
    else if (instr == "label" || instr == "gosublabel" || instr == "jump" || instr == "jumpzero" || instr == "jumpnzero" || instr == "gosub") {
        type = LABEL_PARAM;
    }
    //to do
    //else if (instr == ) {
        //add to the to-do list
        // type = TO_DO;
    //}
    //no param
    else if (instr == "start" || instr == "exit" || instr == "return" || instr == "pop" || instr == "dup" || instr == "swap" 
        || instr == "add" || instr == "negate" || instr == "mul" || instr == "div" || instr == "printtos" || instr == "prints") {
        type = NO_PARAM;
    }
    //end
    else if (instr == "end") {
        type = END;
    }
    else {
        //setError to 1
        type = 0;
        printf("Unsupported Instruction. Parser terminated.");
    }

    return type;
}

void Parser::determineAction(char* instr) {

}


