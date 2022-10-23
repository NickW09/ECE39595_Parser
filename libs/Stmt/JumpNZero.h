#ifndef JUMPNZERO_H_
#define JUMPNZERO_H_
#include <iostream>
#include "StmtLab.h"

class JumpNZero : public StmtLab {
public:
	JumpNZero(std::string lab);
	virtual void action();
	virtual std::string toPrint();
};

#endif /* JUMPNZERO_H_ */

