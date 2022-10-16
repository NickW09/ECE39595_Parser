#ifndef STMT_H_
#define STMT_H_
#include <iostream>

class Stmt {
public:
    virtual void action() = 0;
    virtual void print() = 0;

private:
    uint32_t opcode;
};

#endif /* STMT_H_ */