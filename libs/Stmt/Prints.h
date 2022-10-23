#ifndef PRINTS_H_
#define PRINTS_H_
#include <iostream>
#include "StmtNone.h"

class Prints : public StmtNone {
public:
	Prints();
	virtual void action();
};

#endif /* PRINTS_H_ */