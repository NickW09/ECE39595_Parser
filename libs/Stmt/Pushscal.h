#ifndef PUSHSCAL_H_
#define PUSHSCAL_H_
#include <iostream>
#include "StmtVar.h"

class Pushscal : public StmtVar {
public:
	Pushscal(std::string var, int depth);
	virtual void action();
};

#endif /* PUSHSCAL_H_ */