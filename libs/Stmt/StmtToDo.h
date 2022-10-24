#ifndef STMTTODO_H_
#define STMTTODO_H_
#include <iostream>
#include "Stmt.h"

class StmtToDo : public Stmt {
public:
	StmtToDo();
	virtual void setLoc(int i);
	virtual std::string getVar();
	virtual int getDepth();
	virtual bool getIsStmtLab();
protected:
	std::string var;
	int loc;
	int depth; //subroutine depth
	bool isStmtLab;
};

#endif /* STMTTODO_H_ */