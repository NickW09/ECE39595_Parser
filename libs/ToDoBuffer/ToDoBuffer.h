#ifndef TODOBUFFER_H_
#define TODOBUFFER_H_
#include <iostream>
#include <vector>
#include "..\Stmt\StmtLab.h"

class ToDoBuffer{

public:
    ~ToDoBuffer();                      //DONE
    static ToDoBuffer* getInstance();   //DONE
    void push(StmtLab*);                //DONE
    int getSize();                      //DONE
    StmtLab* getStmt(int idx);          //DONE
    void remove(int idx);               //DONE

private:
    static ToDoBuffer* todoBuf;         //DONE
    ToDoBuffer();                       //DONE
    std::vector<StmtLab*> vec;          //DONE

};

#endif /* TODOBUFFER_H_ */
