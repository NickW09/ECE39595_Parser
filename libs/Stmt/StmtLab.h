#ifndef STMTLAB_H_
#define STMTLAB_H_
#include <iostream>
#include "Stmt.h"

class StmtLab : public Stmt {
public:
	StmtLab();
	virtual std::string toPrint();
	virtual std::string toPrint2();
protected:
	std::string lab;
};

#endif /* STMTLAB_H_ */