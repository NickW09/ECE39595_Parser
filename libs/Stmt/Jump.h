#ifndef JUMP_H_
#define JUMP_H_
#include <iostream>
#include "StmtLab.h"

class Jump : public StmtLab {
public:
	Jump(std::string lab);
	virtual void action();
	virtual std::string toString();
};

#endif /* JUMP_H_ */
