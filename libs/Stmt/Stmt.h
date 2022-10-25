#ifndef STMT_H_
#define STMT_H_
#include <iostream>
#include <string>

class Stmt {
public:
    Stmt();
    virtual void action() = 0;
    virtual void print();
    virtual std::string toString() = 0;
    virtual uint32_t getOp();
    virtual int getData();
protected:
    uint32_t opcode;
    std::string instr; // word representing the name of the instruction to be toStringed
};

#endif /* STMT_H_ */