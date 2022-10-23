#ifndef STMTLAB_H_
#define STMTLAB_H_
#include <iostream>
#include "Stmt.h"

class StmtLab : public Stmt {
public:
	StmtLab();
	virtual void setLoc(int i);
	virtual void setDepth(int i);
	virtual std::string toString();
	virtual std::string toString2();
	virtual std::string toString3();
protected:
	std::string lab;
	int loc;
	int depth; //subroutine depth
};

#endif /* STMTLAB_H_ */