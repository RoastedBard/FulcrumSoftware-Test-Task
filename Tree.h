#pragma once

#include <fstream>

#include "Node.h"

enum DataType
{
	DATA_INT = 0,
	DATA_CHARARRAY,
	DATA_DOUBLE
};

class Tree
{
public:
	Node root;

public:
	Tree(void);
	~Tree(void);

public:
	void DeleteTree(Node *root);
	void PrintTree(Node* root);
	void SerializeTree(Node *root, std::ofstream &file);
	int DeSerializeTree(Node &root, std::ifstream &file);
};

