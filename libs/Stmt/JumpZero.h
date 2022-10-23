#ifndef JUMPZERO_H_
#define JUMPZERO_H_
#include <iostream>
#include "StmtLab.h"

class JumpZero : public StmtLab {
public:
	JumpZero(std::string lab, int depth);
	virtual void action();
	virtual std::string toString();
};

#endif /* JUMPZERO_H_ */

