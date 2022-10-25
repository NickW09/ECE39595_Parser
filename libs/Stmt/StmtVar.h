#ifndef STMTVAR_H_
#define STMTVAR_H_
#include <iostream>
#include "Stmt.h"

class StmtVar : public Stmt {
public:
	StmtVar(std::string var, int _depth, int _loc);
	virtual std::string toString();
	virtual int getData();
protected:
	int loc;
	std::string var;
	int depth;
};

#endif /* STMTVAR_H_ */