#ifndef TODOBUFFER_H_
#define TODOBUFFER_H_
#include <iostream>
#include <vector>
#include "..\Stmt\Stmt.h"

class ToDoBuffer{

public:
    //~ToDoBuffer();                    //DONE
    static ToDoBuffer* getInstance();   //DONE
    void push(Stmt*);                   //DONE
    int getSize();                      //DONE
    Stmt* getStmt(int idx);             //DONE
    void remove(int idx);               //DONE

private:
    static ToDoBuffer* todoBuf;         //DONE
    ToDoBuffer();                       //DONE
    std::vector<Stmt*> vec;             //DONE

};

#endif /* TODOBUFFER_H_ */
