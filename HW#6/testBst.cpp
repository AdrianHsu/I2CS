#include <iostream>
using namespace std;

#include "bst.h"
int main()
{
	BST bst;

	for(int i = 1; i < 8; i++)
		bst.insert(i);
	bst.inorder();
	bst._delete(3);
	bst.inorder();
	return 0;
}