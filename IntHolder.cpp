#include <iostream>
#include "IntHolder.h"

IntHolder::IntHolder()
{
	
}

IntHolder::IntHolder(int data)
{
	SetData(data);
	
}

IntHolder::~IntHolder(void)
{
}

void IntHolder::PrintData()
{
	printf("%d\n", _data);
}

int IntHolder::GetData() const
{
	return _data;
}

void IntHolder::SetData(int data)
{
	_data = data;
}

void IntHolder::Serialize(std::ofstream &file)
{
	file<<"INT_"<<_data<<"\n";
}