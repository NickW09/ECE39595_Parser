#ifndef STMTINT_H_
#define STMTINT_H_
#include <iostream>
#include "Stmt.h"

class StmtInt : public Stmt {
public:
	StmtInt();
	virtual std::string toPrint();
protected:
	int num;
};

#endif /* STMTINT_H_ */