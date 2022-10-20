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
    //instrbuff must be defined
    //to do must be define
    //string table must be defined
    //symbol table must be defined
    char* instr = readWrite->readInstruction();

    while(instr != nullptr){ //checking if end of file reached
        instr = readWrite->readInstruction();
        createStmt(instr); //creates obj on instruction buff

    }
}

void Parser::createStmt(char* instr){
    //lots of cases

    if(instr == "needs int param"){
        //int _int = readWrite->getInt();
    }
    else if (instr == "needs variable param") {
        //char* var = readWrite->getVariable();
    }
    else if (instr == "needs label param") {
        //char* label = readWrite->getLabel();
    }
    else if(instr == "to do"){
        //add to the to-do list
    }
    else if(instr == "no param"){
        //
    }
    else{
        //setError to 1
        printf("Unsupported Instruction. Parser terminated.");
    }

    /*instr == needs param
        stmt_imm_param* obj;
        case 1:
            obj = 
        case 2:
            obj = 
        obj.param = num;
        inst_BUFF.Push(obj)
    elif instr == to do:
        stmt_to_do_param* obj;
        case 1:
            //  maybe necessary instead of "stmt_to_do_param* obj" is "stmt_jump* obj";
            obj =
        case 2:
            obj = 
        todobuff.push(obj)
        instrbuff.push(obj)
    elif print:
        stmt_no_param* obj;
        stringbuff.push(something)*/
}