#ifndef STMTLAB_H_
#define STMTLAB_H_
#include <iostream>
#include "StmtToDo.h"

class StmtLab : public StmtToDo {
public:
	StmtLab();
	virtual void setLoc(int i);
	virtual void setDepth(int i);
	virtual int getDepth();
	virtual std::string getVar();
	virtual std::string getLabel();
	virtual std::string toString();
	virtual std::string toString2();
	virtual std::string toString3();
protected:
	std::string lab;
	int depth; //subroutine depth
};

#endif /* STMTLAB_H_ */