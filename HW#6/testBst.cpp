#include <iostream>
using namespace std;

#include "bst.h"
int main()
{
	BST bst;

	bst.insert(20);
	bst.insert(10);
	bst.insert(40);
	bst.insert(6);
	bst.insert(15);
	bst.insert(30);
	bst.insert(2);
	bst.insert(8);
	bst.insert(12);
	bst.insert(18);
	bst.insert(25);
	bst.insert(35);
	bst.insert(7);
	bst.insert(14);
	
	bst.inorder();
	bst._delete(18);
	bst.inorder();
	return 0;
}