#ifndef GOSUBLABEL_H_
#define GOSUBLABEL_H_
#include <iostream>
#include "StmtLab.h"

class GoSubLabel : public StmtLab {
public:
	GoSubLabel(std::string lab);
	virtual void action();
	virtual std::string toString();
	virtual void setLength(int len);
private:
	int len;
};

#endif /* GOSUBLABEL_H_ */
