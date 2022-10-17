#ifndef STMT_H_
#define STMT_H_
#include <iostream>
#include <string>

class Stmt {
public:
    Stmt();
    virtual void action() = 0;
    virtual void print() = 0;

protected:
    uint32_t opcode;
    std::string instr; // word representing the name of the instruction to be printed
};

#endif /* STMT_H_ */