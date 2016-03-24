#include "CharArrayHolder.h"

CharArrayHolder::CharArrayHolder()
{
}

CharArrayHolder::CharArrayHolder(std::string data)
{
	SetData(data);
}

CharArrayHolder::~CharArrayHolder(void)
{
}

void CharArrayHolder::PrintData()
{
	printf("%s\n", _data);
}

const char* CharArrayHolder::GetData() const
{
	return _data;
}

void CharArrayHolder::SetData(std::string data)
{
	for(int i = 0 ; i < 10; ++i)
	{
		if(data[i] == '\0' || i == 9)
		{
			_data[i] = '\0';
			break;
		}

		_data[i] = data[i];
	}
}

void CharArrayHolder::Serialize(std::ofstream &file)
{
	file<<"CHARARRAY_"<<_data<<"\n";
}