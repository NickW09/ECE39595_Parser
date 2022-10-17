#ifndef PUSHSCAL_H_
#define PUSHSCAL_H_
#include <iostream>
#include "StmtVar.h"

class Pushscal : public StmtVar {
	//using StmtNone::print;
public:
	Pushscal(std::string var);
	virtual void action();
};

#endif /* PUSHSCAL_H_ */