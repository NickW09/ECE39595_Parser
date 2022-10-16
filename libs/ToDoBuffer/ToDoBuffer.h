#ifndef TODOBUFFER_H_
#define TODOBUFFER_H_
#include <iostream>
#include <vector>
#include "..\Stmt\Stmt.h"

class ToDoBuffer{

public:
    ~ToDoBuffer(); //DONE
    static ToDoBuffer* getInstance(); //DONE
    void AddToBuf(Stmt*); //DONE

private:
    static ToDoBuffer* todoBuf; //DONE
    ToDoBuffer(); //DONE
    std::vector<Stmt*> vec; //DONE

};

#endif /* TODOBUFFER_H_ */
