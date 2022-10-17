#ifndef STMTVARLEN_H_
#define STMTVARLEN_H_
#include <iostream>
#include "Stmt.h"

class StmtVarLen : public Stmt {
public:
	StmtVarLen();
	void print();
protected:
	std::string var;
	int len;
};

#endif /* STMTVARLEN_H_ */