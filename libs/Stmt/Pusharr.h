#ifndef PUSHARR_H_
#define PUSHARR_H_
#include <iostream>
#include "StmtVar.h"

class Pusharr : public StmtVar {
public:
	Pusharr(std::string var, int depth);
	virtual void action();
};

#endif /* PUSHARR_H_ */