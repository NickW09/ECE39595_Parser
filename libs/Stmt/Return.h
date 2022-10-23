#ifndef RETURN_H_
#define RETURN_H_
#include <iostream>
#include "StmtNone.h"

class Return : public StmtNone {
public:
	Return();
	virtual void action();
};

#endif /* RETURN_H_ */