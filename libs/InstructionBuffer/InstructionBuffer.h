#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_
#include <iostream>
#include <vector>
#include "..\Stmt\Stmt.h"

//Holds list of instructions

class InstructionBuffer {

public:
    //~InstructionBuffer(); //DONE
    static InstructionBuffer* getInstance(); //DONE
    void AddToBuf(Stmt*); //DONE

private:
    static InstructionBuffer* instrBuf; //DONE
    InstructionBuffer(); //DONE
    std::vector<Stmt*> vec; //DONE

};

#endif /* INSTRUCTIONBUFFER_H_ */