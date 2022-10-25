#ifndef STMTINT_H_
#define STMTINT_H_
#include <iostream>
#include "Stmt.h"

class StmtInt : public Stmt {
public:
	StmtInt();
	virtual std::string toString();
	virtual int getData();
protected:
	int num;
};

#endif /* STMTINT_H_ */