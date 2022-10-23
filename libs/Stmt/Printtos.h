#ifndef PRINTTOS_H_
#define PRINTTOS_H_
#include <iostream>
#include "StmtNone.h"

class Printtos : public StmtNone {
public:
	Printtos();
	virtual void action();
};

#endif /* PRINTTOS_H_ */