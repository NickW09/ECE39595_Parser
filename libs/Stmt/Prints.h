#ifndef PRINTS_H_
#define PRINTS_H_
#include <iostream>
#include "StmtInt.h"

class Prints : public StmtInt {
public:
	Prints(int i);
	virtual void action();
};

#endif /* PRINTS_H_ */