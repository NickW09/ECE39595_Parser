#ifndef ADD_H_
#define ADD_H_
#include <iostream>
#include "StmtNone.h"

class Add : public StmtNone {
public:
	Add();
	virtual void action();
};

#endif /* ADD_H_ */