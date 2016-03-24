#pragma once

#include "BaseHolder.h"

class IntHolder :
	public BaseHolder
{
public:
	IntHolder();
	IntHolder(int data);
	~IntHolder(void);

	virtual void PrintData();
	virtual void Serialize(std::ofstream &file);

	int GetData() const;
	void SetData(int data);

private:
	int _data;
};

