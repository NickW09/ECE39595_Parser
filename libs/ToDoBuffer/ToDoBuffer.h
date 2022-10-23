#ifndef TODOBUFFER_H_
#define TODOBUFFER_H_
#include <iostream>
#include <vector>
#include "..\Stmt\StmtToDo.h"

class ToDoBuffer{

public:
    ~ToDoBuffer();                      //DONE
    static ToDoBuffer* getInstance();   //DONE
    void push(StmtToDo*);                //DONE
    int getSize();                      //DONE
    StmtToDo* getStmt(int idx);          //DONE
    void remove(int idx);               //DONE

private:
    static ToDoBuffer* todoBuf;         //DONE
    ToDoBuffer();                       //DONE
    std::vector<StmtToDo*> vec;          //DONE

};

#endif /* TODOBUFFER_H_ */
