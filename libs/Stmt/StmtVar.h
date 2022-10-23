#ifndef STMTVAR_H_
#define STMTVAR_H_
#include <iostream>
#include "StmtToDo.h"

class StmtVar : public StmtToDo {
public:
	StmtVar();
	virtual std::string toString();
protected:
};

#endif /* STMTVAR_H_ */