#ifndef _BASEHOLDER_H
#define _BASEHOLDER_H

#include <fstream>

class BaseHolder
{
public:
	virtual void PrintData() = 0;
	virtual void Serialize(std::ofstream &file) = 0;

	virtual ~BaseHolder(){};

protected:
};

#endif