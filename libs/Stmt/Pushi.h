#ifndef PUSHI_H_
#define PUSHI_H_
#include <iostream>
#include "StmtInt.h"

class Pushi : public StmtInt {
public:
	Pushi(int _num);
	virtual void action();
};

#endif /* PUSHI_H_ */