#ifndef JUMPZERO_H_
#define JUMPZERO_H_
#include <iostream>
#include "StmtLab.h"

class JumpZero : public StmtLab {
public:
	JumpZero(std::string lab);
	virtual void action();
	virtual std::string toPrint();
};

#endif /* JUMPZERO_H_ */

