#ifndef START_H_
#define START_H_
#include <iostream>
#include "StmtNone.h"

class Start : public StmtNone {
public:
	Start();
	virtual void action();
};

#endif /* START_H_ */