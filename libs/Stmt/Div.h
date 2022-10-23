#ifndef DIV_H_
#define DIV_H_
#include <iostream>
#include "StmtNone.h"

class Div : public StmtNone {
public:
	Div();
	virtual void action();
};

#endif /* DIV_H_ */