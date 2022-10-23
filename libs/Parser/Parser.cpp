#include "Parser.h"

Parser* Parser::parser = nullptr; 

//Constructor
Parser::Parser(const char* inputFileName, const char* outputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf, ToDoBuffer* _todoBuf) {
    instrBuf = _instrBuf; //Set instructionBuffer
    symTable = _symTable; //Set symbolTable
    strBuf = _strBuf; //Set stringBuffer
    toDoBuf = _todoBuf;
    readWrite = ReadWrite::getInstance(inputFileName, outputFileName); //give ReadWriteParser the input and output files
    start = nullptr;
    error = 0;
}

Parser::~Parser() {
    readWrite->~ReadWrite();
    parser = nullptr;
}

//Singelton 
Parser* Parser::getInstance(const char* inputFileName, const char* outputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf, ToDoBuffer* _todoBuf){
    if(parser == nullptr) {
        parser = new Parser(inputFileName, outputFileName, _instrBuf, _symTable, _strBuf, _todoBuf); // makes unique instantiation
    }
    return parser; // return singleton
}

//Starts the parsing
int Parser::beginParser(){
    std::cout << "Parser Running..." << std::endl;

    //readWrite->updateInstruction(); //Grab initial instruction
    std::string instr;// = readWrite->getInstruction();
    bool end = false;
    while (!(readWrite->getEOF() || readWrite->getError())) { //checking if end of file reached
        readWrite->updateInstruction();
        instr = readWrite->getInstruction();
        if (!instr.empty()) {
            if (end) {
                return 1;
            }
            int type = determineType(instr);
            if (type == ERROR) {
                return 1;
            }
            createStmt(type, instr);
            end = type == END;
        }
    }

    std::cout << "EOF Reached. Parsing Complete." << std::endl;
    
    std::cout << std::endl;
    printInstrBuf();
    std::cout << std::endl;
    printSymTable();

    return 0;
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
        type = INT_VAR_PARAM;
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

    Stmt* stmt = nullptr;
    int errFlag = 0;
    
    std::string inst(instr);

    int integer;
    std::string var;
    std::string label;
    //TableEntry te;

    switch (type) {

        case (INT_PARAM):
            integer = readWrite->getInt();
            if (inst == "pushi") {              
                stmt = new Pushi(integer);
            }
            break;
        case (INT_VAR_PARAM):
            integer = readWrite->getIntVar(var);
            if (inst == "declarr") {            
                //is this instr buffer loc instead?
                symTable->push(var, TableEntry(symTable->getCurrLoc(), integer));
            }
            break;
        case (VAR_PARAM):
            var = readWrite->getVariable();
            if (inst == "declscal") {           
                //is this instr buffer loc instead?
                symTable->push(var, TableEntry(symTable->getCurrLoc(), 1));
            }
            else if (inst == "pushscal") {      
                stmt = new Pushscal(var);
            }
            else if (inst == "pusharr") {       
                stmt = new Pusharr(var);
            }
            else if (inst == "popscal") {       
                stmt = new Popscal(var);
            }
            else if (inst == "poparr") {       
                stmt = new Poparr(var);
            }
            else if (inst == "prints") {      
                strBuf->push(var);
                //technically int param
                stmt = new Prints(strBuf->getSize());
            }
            break;
        case (LABEL_PARAM):
            label = readWrite->getLabel();
            if (inst == "label") {            
                symTable->push(label, TableEntry(symTable->getCurrLoc(), instrBuf->getSize() + 1));
            }
            else if (inst == "gosublabel") {  
                symTable->push(label, TableEntry(symTable->getCurrLoc(), instrBuf->getSize() + 1));
                stmt = new GoSubLabel(label);
                symTable->enterSubroutine();
            }
            else if (inst == "jump") {        
                //make searches only able to see in subroutine
                StmtLab* stmtLab = new Jump(label, symTable->getSubLv());
                stmt = stmtLab;
                toDoBuf->push(stmtLab);
            }
            else if (inst == "jumpzero") {    
                StmtLab* stmtLab = new JumpZero(label, symTable->getSubLv());
                stmt = stmtLab;
                toDoBuf->push(stmtLab);
            }
            else if (inst == "jumpnzero") {   
                StmtLab* stmtLab = new JumpNZero(label, symTable->getSubLv());
                stmt = stmtLab;
                toDoBuf->push(stmtLab);
            }
            else if (inst == "gosub") {     
                StmtLab* stmtLab = new GoSub(label, symTable->getSubLv());
                stmt = stmtLab;
                toDoBuf->push(stmtLab);
            }
            else {
                errFlag = 1;
            }
            break;


        case (NO_PARAM):
            if (inst == "start") { 
                start = new Start();
                stmt = start;
            }
            else if (inst == "exit") {      
                stmt = new Exit();
            }
            else if (inst == "return") {    //FILLS IN INFO
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
            else {
                errFlag = 1;
            }
            break;

        case (END):         //FILLS IN INFO
            start->setLength(symTable->getTotalLength());
            /*for (int i = 0; i < toDoBuf->getSize(); i++) {
                //toDoBuf->getStmt().set
            }*/

            break;
    }

    if (stmt != nullptr) {
        instrBuf->push(stmt);
    }
}

void Parser::determineAction(std::string instr) {

}

void Parser::printInstrBuf() {
    for (int i = 0; i < instrBuf->getSize(); i++) {
        readWrite->writeLine(instrBuf->getStmt(i)->toString());
    }
}

void Parser::printSymTable() {
    std::pair<std::pair<int, std::string>, TableEntry> symChunk;
    std::cout << "Symbol Table:" << std::endl;
    for (int i = 0; i < symTable->getNumEntries(); i++) {
        symChunk = symTable->getEntryAtIndex(i);
        
        std::cout << "(" + std::to_string(symChunk.first.first) + std::string(", ") +
            symChunk.first.second+ std::string("): (")+std::to_string(symChunk.second.getLocation())+ 
            std::string(", ")+std::to_string(symChunk.second.getLength())+")" << std::endl;
    }
}
