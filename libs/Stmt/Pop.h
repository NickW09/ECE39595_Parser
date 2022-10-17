#ifndef POP_H_
#define POP_H_
#include <iostream>
#include "StmtNone.h"

class Pop : public StmtNone {
	//using StmtNone::print;
public:
	Pop();
	virtual void action();
};

#endif /* POP_H_ */