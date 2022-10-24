#ifndef POPARR_H_
#define POPARR_H_
#include <iostream>
#include "StmtVar.h"

class Poparr : public StmtVar {
public:
	Poparr(std::string var, int depth, int loc);
	virtual void action();
};

#endif /* POPARR_H_ */