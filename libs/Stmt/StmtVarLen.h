#ifndef STMTVARLEN_H_
#define STMTVARLEN_H_
#include <iostream>
#include "Stmt.h"

//WHOLE THING DONT NEED! (I think)

class StmtVarLen : public Stmt {
public:
	StmtVarLen();
	virtual std::string toString();
protected:
	std::string var;
	int len;
};

#endif /* STMTVARLEN_H_ */