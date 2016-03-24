#include <iostream>
#include <conio.h>
#include <sstream>

#include "Tree.h"

using namespace std;

int main()
{
	Tree tree;

	tree.root.data = new IntHolder(1);

	tree.root.AddChildInt(2011);
	tree.root.AddChildCharArray("C++");
	tree.root.AddChildDouble(3.14);

	tree.root.children[0].AddChildCharArray("FULCRUM");
	tree.root.children[0].children[0].AddChildCharArray("LINUX");
	tree.root.children[0].children[0].AddChildInt(7);

	tree.root.children[2].AddChildCharArray("TEST");
	tree.root.children[2].AddChildInt(9);
	tree.root.children[2].AddChildInt(6);

	tree.PrintTree(&tree.root);

	// Serialization
	ofstream serilizedTreeFile;
	serilizedTreeFile.open("SerializedTree.txt");

	tree.SerializeTree(&tree.root, serilizedTreeFile);

	serilizedTreeFile.close();

	tree.DeleteTree(&tree.root);

	// Deserialization
	Tree deserializedTree;

	ifstream deSerilizedTreeFile("SerializedTree.txt");
	if (deSerilizedTreeFile.is_open())
	{
		deserializedTree.DeSerializeTree(deserializedTree.root, deSerilizedTreeFile);
	}

	deSerilizedTreeFile.close();

	cout<<endl;

	deserializedTree.PrintTree(&deserializedTree.root);
	deserializedTree.DeleteTree(&deserializedTree.root);

	_getch();

	return 0;
}