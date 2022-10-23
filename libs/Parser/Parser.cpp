#include "Parser.h"

Parser* Parser::parser = nullptr; 

//Constructor
Parser::Parser(const char* inputFileName, const char* outputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf) {
    instrBuf = _instrBuf; //Set instructionBuffer
    symTable = _symTable; //Set symbolTable
    strBuf = _strBuf; //Set stringBuffer
    readWrite = ReadWrite::getInstance(inputFileName, outputFileName); //give ReadWriteParser the input and output files
    error = 0;
}

//Singelton 
Parser* Parser::getInstance(const char* inputFileName, const char* outputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf){
    if(parser == nullptr) {
        parser = new Parser(inputFileName, outputFileName, _instrBuf, _symTable, _strBuf); // makes unique instantiation
    }
    return parser; // return singleton
}

//Starts the parsing
void Parser::beginParser(){
    printf("Parser Running...");

    readWrite->updateInstruction(); //Grab initial instruction
    std::string instr = readWrite->getInstruction();

    while (!(readWrite->getEOF())) { //checking if end of file reached
        readWrite->updateInstruction();
        instr = readWrite->getInstruction();
        int type = determineType(instr);
        if (type == 0) {
            return;
        }
        createStmt(type, instr);
    }
    std::cout << "EOF Reached. Parsing Complete." << std::endl;
}

int Parser::determineType(std::string instr)
{

    int type; 

    //INT PARAM
    if (instr == "pushi") {
        type = INT_PARAM;
    }
    //VAR PARAM
    else if (instr == "declscal" || instr == "pushscal" || instr == "pusharr" || instr == "popscal" || instr == "poparr") {
        type = VAR_PARAM;
    }
    //INT AND VAR PARAM
    else if (instr == "declarr") {
        type == INT_VAR_PARAM;
    }
    //LABEL PARAM
    else if (instr == "label" || instr == "gosublabel" || instr == "jump" || instr == "jumpzero" || instr == "jumpnzero" || instr == "gosub") {
        type = LABEL_PARAM;
    }
    //NO PARAM 
    else if (instr == "start" || instr == "exit" || instr == "return" || instr == "pop" || instr == "dup" || instr == "swap" 
        || instr == "add" || instr == "negate" || instr == "mul" || instr == "div" || instr == "printtos" || instr == "prints") {
        type = NO_PARAM;
    }
    //END
    else if (instr == "end") {
        type = END;
    }
    //UNSURRORTED
    else {
        type = ERROR;
        printf("Unsupported Instruction. Parser terminated.");
    }

    return type;
}

void Parser::createStmt(int type, std::string instr) {

    int type = determineType(instr);
    Stmt* stmt = nullptr;
    int errFlag = 0;

    std::string inst(instr);

    switch (type) {

        case (INT_PARAM):
            int integer = readWrite->getInt();
            if (inst == "pushi") {
                stmt = new Pushi(integer);
            }
            break;

        case (VAR_PARAM):
            std::string var = readWrite->getVariable();
            if (inst == "declarr") {
                stmt = new Declarr(var);
            }

        case (INT_VAR_PARAM):
            std::string var;
            int integer = readWrite->getIntVar(var);
            if (inst == "declscal") {
                stmt = new Declscal();
            }
            else if (inst == "pushscal") {
                stmt = new Pushscal();
            }
            else if (inst == "pusharr") {
                stmt = new Pusharr();
            }
            else if (inst == "popscal") {
                stmt = new Popscal();
            }
            else if (inst == "poparr") {
                stmt = new Poparr();
            }

        case (LABEL_PARAM):
            std::string label = readWrite->getLabel();
            if (inst == "label") {
                stmt = new Label(label);
            }
            else if (inst == "gosublabel") {
                stmt = new GoSubLabel(label);
            }
            else if (inst == "jump") {
                stmt = new Jump(label);
            }
            else if (inst == "jumpzero") {
                stmt = new JumpZero(label);
            }
            else if (inst == "jumpnzero") {
                stmt = new JumpNZero(label);
            }
            else if (inst == "gosub") {
                stmt = new GoSub(label);
            }
            else {
                errFlag = 1;
            }
            break;


        case (NO_PARAM):
            if (inst == "start") {
                stmt = new Start();
            }
            else if (inst == "exit") {
                stmt = new Exit();
            }
            else if (inst == "return") {
                stmt = new Return();
            }
            else if (inst == "pop") {
                stmt = new Pop();
            }
            else if (inst == "dup") {
                stmt = new Dup();
            }
            else if (inst == "swap") {
                stmt = new Swap();
            }
            else if (inst == "add") {
                stmt = new Add();
            }
            else if (inst == "negate") {
                stmt = new Negate();
            }
            else if (inst == "mul") {
                stmt = new Mul();
            }
            else if (inst == "div") {
                stmt = new Div();
            }
            else if (inst == "printtos") {
                stmt = new Printtos();
            }
            else if (inst == "prints") {
                stmt = new Prints();
            }
            else {
                errFlag = 1;
            }
            break;

        case (END):
            //do something?

    }

    if (stmt != nullptr) {
        instrBuf->push(stmt);
    }
}

void Parser::determineAction(std::string instr) {

}


