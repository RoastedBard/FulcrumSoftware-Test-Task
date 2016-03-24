#include "DoubleHolder.h"

#include <iostream>

DoubleHolder::DoubleHolder()
{
}

DoubleHolder::DoubleHolder(double data)
{
	SetData(data);
}

DoubleHolder::~DoubleHolder(void)
{
}

void DoubleHolder::PrintData()
{
	printf("%f\n", _data);
}

double DoubleHolder::GetData() const
{
	return _data;
}

void DoubleHolder::SetData(double data)
{
	_data = data;
}

void DoubleHolder::Serialize(std::ofstream &file)
{
	file<<"DOUBLE_"<<_data<<"\n";
}