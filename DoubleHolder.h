#pragma once

#include "BaseHolder.h"

class DoubleHolder :
	public BaseHolder
{
public:
	DoubleHolder();
	DoubleHolder(double data);
	~DoubleHolder(void);

	virtual void PrintData();
	virtual void Serialize(std::ofstream &file);

	double GetData() const;
	void SetData(double data);

private:
	double _data;
};

