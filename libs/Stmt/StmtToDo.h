#ifndef STMTTODO_H_
#define STMTTODO_H_
#include <iostream>
#include "Stmt.h"

class StmtToDo : public Stmt {
public:
	StmtToDo();
	virtual void setLoc(int i);
	virtual std::string getVar();
protected:
	std::string var;
	int loc;
	int depth; //subroutine depth
};

#endif /* STMTTODO_H_ */