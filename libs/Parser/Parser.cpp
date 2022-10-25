#include "Parser.h"

Parser* Parser::parser = nullptr; 

//Constructor
Parser::Parser(const char* inputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf, ToDoBuffer* _todoBuf) {
    instrBuf = _instrBuf; //Set instructionBuffer
    symTable = _symTable; //Set symbolTable
    strBuf = _strBuf; //Set stringBuffer
    toDoBuf = _todoBuf;
    readWrite = ReadWrite::getInstance(inputFileName); //give ReadWriteParser the input and output files
    start = nullptr;
    gosublabel = nullptr;
    error = 0;
    startDetected = 0;
    endDetected = 0;
}

Parser::~Parser() {
    readWrite->~ReadWrite();
    parser = nullptr;
}

//Singelton 
Parser* Parser::getInstance(const char* inputFileName, InstructionBuffer* _instrBuf, SymbolTable* _symTable, StringBuffer* _strBuf, ToDoBuffer* _todoBuf){
    if(parser == nullptr) {
        parser = new Parser(inputFileName, _instrBuf, _symTable, _strBuf, _todoBuf); // makes unique instantiation
    }
    return parser; // return singleton
}

//Starts the parsing
int Parser::beginParser(){

    std::string instr;// = readWrite->getInstruction();
    bool end = false;
    while (!(readWrite->getEOF() || readWrite->getError())) { //checking if end of file reached
        readWrite->updateInstruction();
        instr = readWrite->getInstruction();
        
        //If end statement detected and next instruction is not empty
        if (endDetected == 1 && !instr.empty()) {
            readWrite->writeLine("error: code encountered after an end statement");
            error = 1;
        }
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
    
    //End statement must have been detected
    if (!endDetected) {
        readWrite->writeLine("error: no end statement in program");
        error = 1;
    }
    
    if (error) {
        return 1;
    }

    writeOut();

    /*std::cout << std::endl;
    printSymTable();
    std::cout << std::endl;*/
    printStringBuf();
    printInstrBuf();

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
    else if (instr == "declscal" || instr == "pushscal" || instr == "pusharr" || instr == "popscal" || instr == "poparr" || instr == "prints") {
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
        || instr == "add" || instr == "negate" || instr == "mul" || instr == "div" || instr == "printtos") {
        type = NO_PARAM;
    }
    //END
    else if (instr == "end") {
        type = END;

    }
    //UNSURRORTED
    else {
        type = ERROR;
        std::cout << "Unsupported Instruction. Parser terminated." << std::endl;
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
    int loc;
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
                if (!symTable->checkForVar(var)) {
                    symTable->push(var, TableEntry(symTable->getCurrLoc(), integer));
                }
                else {
                    error = 1;
                    readWrite->writeLine("error: attempting to add variable with name "+var+" twice");
                }
            }
            break;
        case (VAR_PARAM):
            var = readWrite->getVariable();
            loc = -1;
            if (inst == "declscal") {           
                //is this instr buffer loc instead?
                if (!symTable->checkForVar(var)) {
                    symTable->push(var, TableEntry(symTable->getCurrLoc(), 1));
                }
                else {
                    error = 1;
                    readWrite->writeLine("error: attempting to add variable with name " + var + " twice");
                }
            }
            else if (inst == "prints") {
                //technically int param
                stmt = new Prints(strBuf->getSize());
                strBuf->push(var);
            }
            else {
                //stmtvars can be evaled immediately since vars are always declared bf use
                loc = symTable->getData(var).getLocation();
                if (loc >= 0) {
                    if (inst == "pushscal") {              
                        stmt = new Pushscal(var, symTable->getSubLv(), loc);
                    }
                    else if (inst == "pusharr") {                  
                        stmt = new Pusharr(var, symTable->getSubLv(), loc);
                    }
                    else if (inst == "popscal") {                  
                        stmt = new Popscal(var, symTable->getSubLv(), loc);
                    }
                    else if (inst == "poparr") {                      
                        stmt = new Poparr(var, symTable->getSubLv(), loc);
                    }
                }
                else {
                    errFlag = 1;
                }
                

            }
            
            break;
        case (LABEL_PARAM):
            label = readWrite->getLabel();
            if (inst == "label") {            
                if (!symTable->checkForLabel(label)) {
                    symTable->pushLabel(label, TableEntry(instrBuf->getSize(), 0));
                }
                else {
                    error = 1;
                    readWrite->writeLine("error: attempting to add label with name " + label + " twice");
                }
            }
            else if (inst == "gosublabel") {  
                if (!symTable->checkForLabel(label)) {
                    symTable->pushLabel(label, TableEntry(instrBuf->getSize(), 0));
                }
                else {
                    error = 1;
                    readWrite->writeLine("error: attempting to add label with name " + label + " twice");
                }
                gosublabel = new GoSubLabel(label);
                stmt = gosublabel;
                symTable->enterSubroutine();
            }
            else if (inst == "jump") {        
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
                //gosubs always pull labels from main and so check in depth 0 symTable
                StmtLab* stmtLab = new GoSub(label, 0);
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
            else if (inst == "return") { 
                stmt = new Return();
                gosublabel->setLength(symTable->getSubLength());
                
                //printSymTable();

                for (int i = 0; i < toDoBuf->getSize(); i++) {
                    if (toDoBuf->getStmt(i)->getDepth() == 1) {
                        int loc = -1;
                        if(toDoBuf->getStmt(i)->getIsStmtLab())
                            //labels can only pulled from main routine
                            loc = symTable->getData(toDoBuf->getStmt(i)->getVar()).getLocation();
                        else {
                            //vars are no longer set here.
                            //need to clean up toDoTable and delete isStmtLab
                        }
                        if (loc >= 0) {
                            toDoBuf->getStmt(i)->setLoc(loc);
                        }
                        else {
                            error = 1;
                            //Do we need?
                            readWrite->writeLine("error: cannot find symbol in symbol table");
                        }
                        //remove pointer from toDoBuf so it is not updated again
                        toDoBuf->remove(i);
                        //shift back the loop one step since elements will all shift left
                        i--;
                    }
                }
                symTable->exitSubroutine();
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

        case (END): 
            endDetected = 1;
            start->setLength(symTable->getTotalLength());
            for (int i = 0; i < toDoBuf->getSize(); i++) {
                if (toDoBuf->getStmt(i)->getDepth() == 0) { //should this allow depth of 0 or 1?
                    toDoBuf->getStmt(i)->setLoc(symTable->getData(toDoBuf->getStmt(i)->getVar()).getLocation());
                }
            }

            break;
    }

    if (stmt != nullptr) {
        instrBuf->push(stmt);
    }
}

void Parser::determineAction(std::string instr) {

}

void Parser::printStringBuf() {
    for (int i = 0; i < strBuf->getSize(); i++) {
        readWrite->writeLine(strBuf->get(i));
    }
}

void Parser::printInstrBuf() {
    for (int i = 0; i < instrBuf->getSize(); i++) {
        readWrite->writeLine(instrBuf->getStmt(i)->toString());
    }
}

void Parser::printSymTable() {
    std::pair<std::string, TableEntry> symChunk;
    std::cout << "Symbol Table:" << std::endl;
    for (int i = 0; i < symTable->getNumEntries(); i++) {
        symChunk = symTable->getEntryAtIndex(i);
        
        std::cout << "(" + symChunk.first + "): (" + std::to_string(symChunk.second.getLocation()) + 
            ", " + std::to_string(symChunk.second.getLength()) + ")" << std::endl;
    }
}

void Parser::writeOut() {
    readWrite->writeOut(std::to_string(instrBuf->getSize()));
    for (int i = 0; i < instrBuf->getSize(); i++) {
        readWrite->writeOut(std::to_string(instrBuf->getStmt(i)->getOp()));
        readWrite->writeOut(std::to_string(instrBuf->getStmt(i)->getData()));
    }
    readWrite->writeOut(std::to_string(strBuf->getSize()));
    for (int i = 0; i < strBuf->getSize(); i++) {
        readWrite->writeOut(strBuf->get(i));
    }
}