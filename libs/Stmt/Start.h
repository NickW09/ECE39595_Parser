#ifndef START_H_
#define START_H_
#include <iostream>
#include "StmtNone.h"

class Start : public StmtNone {
public:
	Start();
	virtual void action();
	virtual std::string toString();
	void setLength(int _length);
	virtual int getData();
private:
	int length;
};

#endif /* START_H_ */