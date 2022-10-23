#ifndef POPSCAL_H_
#define POPSCAL_H_
#include <iostream>
#include "StmtVar.h"

class Popscal : public StmtVar {
public:
	Popscal(std::string var);
	virtual void action();
};

#endif /* POPSCAL_H_ */