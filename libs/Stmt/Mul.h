#ifndef MUL_H_
#define MUL_H_
#include <iostream>
#include "StmtNone.h"

class Mul : public StmtNone {
public:
	Mul();
	virtual void action();
};

#endif /* MUL_H_ */