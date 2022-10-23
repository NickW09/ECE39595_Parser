#ifndef JUMPNZERO_H_
#define JUMPNZERO_H_
#include <iostream>
#include "StmtLab.h"

class JumpNZero : public StmtLab {
public:
	JumpNZero(std::string lab, int depth);
	virtual void action();
	virtual std::string toString();
};

#endif /* JUMPNZERO_H_ */

