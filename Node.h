#pragma once

#include <memory>
#include <vector>
#include <string>

#include "BaseHolder.h"
#include "IntHolder.h"
#include "DoubleHolder.h"
#include "CharArrayHolder.h"

struct Node
{
	BaseHolder *data;

	std::vector<Node> children;	

	Node()
	{
		
	}

	~Node()
	{
		
	}

	void AddChildInt(int data)
	{
		Node n;
		n.data = new IntHolder();
		static_cast<IntHolder*>(n.data)->SetData(data);

		children.push_back(n);
	}
	void AddChildDouble(double data)
	{
		Node n;
		n.data = new DoubleHolder();
		static_cast<DoubleHolder*>(n.data)->SetData(data);

		children.push_back(n);
	}
	void AddChildCharArray(std::string data)
	{
		Node n;
		n.data = new CharArrayHolder();
		static_cast<CharArrayHolder*>(n.data)->SetData(data);

		children.push_back(n);
	}
};