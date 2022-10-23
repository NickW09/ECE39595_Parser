#ifndef SWAP_H_
#define SWAP_H_
#include <iostream>
#include "StmtNone.h"

class Swap : public StmtNone {
public:
	Swap();
	virtual void action();
};

#endif /* SWAP_H_ */