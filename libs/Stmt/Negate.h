#ifndef NEGATE_H_
#define NEGATE_H_
#include <iostream>
#include "StmtNone.h"

class Negate : public StmtNone {
public:
	Negate();
	virtual void action();
};

#endif /* NEGATE_H_ */