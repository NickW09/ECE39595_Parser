#ifndef STMTLAB_H_
#define STMTLAB_H_
#include <iostream>
#include "Stmt.h"

class StmtLab : public Stmt {
public:
	StmtLab();
	virtual std::string toString();
	virtual std::string toString2();
	virtual std::string toString3();
protected:
	std::string lab;
};

#endif /* STMTLAB_H_ */