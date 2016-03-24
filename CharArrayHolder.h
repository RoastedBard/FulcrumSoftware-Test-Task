#pragma once

#include <string>

#include "BaseHolder.h"

class CharArrayHolder :
	public BaseHolder
{
public:
	CharArrayHolder();
	CharArrayHolder(std::string data);
	~CharArrayHolder(void);

	virtual void PrintData();
	virtual void Serialize(std::ofstream &file);

	const char* GetData() const;
	void SetData(std::string data);

private:
	char _data[10];
};

