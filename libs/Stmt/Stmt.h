#ifndef STMT_H_
#define STMT_H_
#include <iostream>
#include <string>

class Stmt {
public:
    Stmt();
    virtual void action() = 0;
    virtual void print();
    virtual std::string toPrint() = 0;

protected:
    uint32_t opcode;
    std::string instr; // word representing the name of the instruction to be toPrinted
};

#endif /* STMT_H_ */