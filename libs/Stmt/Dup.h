#ifndef DUP_H_
#define DUP_H_
#include <iostream>
#include "StmtNone.h"

class Dup : public StmtNone {
public:
	Dup();
	virtual void action();
};

#endif /* DUP_H_ */