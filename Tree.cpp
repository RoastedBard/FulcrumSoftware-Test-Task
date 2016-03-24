#include "Tree.h"

#include <iostream>

using namespace std;

DataType getEnumValue(string str)
{
	if(str == "INT") return DATA_INT;
	if(str == "CHARARRAY") return DATA_CHARARRAY;
	if(str == "DOUBLE") return DATA_DOUBLE;
}

Tree::Tree(void)
{
}


Tree::~Tree(void)
{
}

void Tree::DeleteTree(Node *root)
{
	if(root->data == NULL)
		return;
	
	cout<<">DELETED: "; 
	root->data->PrintData();
	
	delete root->data;

	for(int i = 0; i < root->children.size(); ++i)
		DeleteTree(&root->children[i]);
}

void Tree::PrintTree(Node* root)
{
	if(root == NULL)
		return;

	root->data->PrintData();

	for(int i = 0; i < root->children.size(); ++i)
		PrintTree(&root->children[i]);
}

void Tree::SerializeTree(Node *root, ofstream &file)
{
	if(root == NULL)
		return;

	root->data->Serialize(file);

	for(int i = 0; i < root->children.size(); ++i)
	{
		SerializeTree(&root->children[i], file);
		file<<")\n";
	}
}

int Tree::DeSerializeTree(Node &root, ifstream &file)
{
	string line;
	getline(file, line);

	if(line == ")" || line == "")
		return 1;

	// Parse the string
	string type, data;

	int pos = line.find('_');
	int typeLength = (line.length() + 1) - pos;
	type = line.substr(0, pos);

	data = line.substr(pos + 1, line.npos);

	// Create node
	Node n;
	root = n;

	switch(getEnumValue(type))
	{
	case DATA_INT:
		root.data = new IntHolder(stoi(data));
		break;

	case DATA_CHARARRAY:
		root.data = new CharArrayHolder(data);
		break;

	case DATA_DOUBLE:
		root.data = new DoubleHolder(stod(data));
		break;
	}

	
	for(int i = 0; ; ++i)
	{
		Node n;
		root.children.push_back(n);
		if(DeSerializeTree(root.children.back(), file))
		{
			root.children.pop_back();
			break;
		}
	}

	return 0;
}