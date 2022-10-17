#ifndef STMTNONE_H_
#define STMTNONE_H_
#include <iostream>
#include "Stmt.h"

class StmtNone : public Stmt {
public:
	StmtNone();
	void print();
};

#endif /* STMTNONE_H_ */