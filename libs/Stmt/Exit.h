#ifndef EXIT_H_
#define EXIT_H_
#include <iostream>
#include "StmtNone.h"

class Exit : public StmtNone {
public:
	Exit();
	virtual void action();
};

#endif /* EXIT_H_ */