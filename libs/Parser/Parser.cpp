#include "Parser.h"

Parser* Parser::parser = nullptr;

//Constructor
Parser::Parser(char* inputFileName, char* outputFileName, InstructionBuffer& _instrBuf, SymbolTable& _symTable, StringBuffer& _strBuf) {
    instrBuf = _instrBuf; //Set instructionBuffer
    symTable = _symTable; //Set symbolTable
    strBuf = _strBuf; //Set stringBuffer
    readWrite = ReadWrite::getInstance(inputFileName, outputFileName); //give ReadWriteParser the input and output files
    error = 0;
}

Parser* Parser::getInstance(char* inputFileName, char* outputFileName, InstructionBuffer& _instrBuf, SymbolTable& _symTable, StringBuffer& _strBuf){
    if(parser == nullptr) {
        parser = new Parser(inputFileName, outputFileName, _instrBuf, _symTable, _strBuf); // makes unique instantiation
    }
    return parser; // return singleton
}

void Parser::beginParser(char* txtfile){
    printf("Parser Running...");
    //instrbuff must be defined
    //to do must be define
    //string table must be defined
    //symbol table must be defined
    
    /*while(!endline){
        string = ReadWrite.readLine(){}
        createStmt(string); //creates obj on instruction buff

    }*/
}

void Parser::createStmt(char* instr){
    //lots of cases

    if(instr == "needs param"){
      
    }
    else if(instr == "to do"){

    }
    else if(instr == "no param"){

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