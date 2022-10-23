#ifndef GOSUB_H_
#define GOSUB_H_
#include <iostream>
#include "StmtLab.h"

class GoSub : public StmtLab {
public:
	GoSub(std::string lab, int depth);
	virtual void action();
};

#endif /* GOSUB_H_ */
