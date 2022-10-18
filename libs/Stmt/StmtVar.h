#ifndef STMTVAR_H_
#define STMTVAR_H_
#include <iostream>
#include "Stmt.h"

class StmtVar : public Stmt {
public:
	StmtVar();
	virtual std::string toPrint();
protected:
	std::string var;
};

#endif /* STMTVAR_H_ */