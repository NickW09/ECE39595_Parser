#ifndef STMTNONE_H_
#define STMTNONE_H_
#include <iostream>
#include "Stmt.h"

class StmtNone : public Stmt {
public:
	StmtNone();
	virtual std::string toPrint();
};

#endif /* STMTNONE_H_ */