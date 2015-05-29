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
	
	/*bst.inorder();
	bst._delete(18);
	bst.inorder();
	bst._delete(10);
	bst.inorder();
	bst._delete(40);
	bst.inorder();
	bst._delete(6);
	bst.inorder();
	bst._delete(15);
	bst.inorder();
	bst._delete(30);
	bst.inorder();
	bst._delete(12);
	bst.inorder();
	bst._delete(2);
	bst.inorder();
	bst._delete(8);
	bst.inorder();
	bst._delete(35);
	bst.inorder();
	bst._delete(20);
	bst.inorder();
	bst._delete(7);
	bst.inorder();
	bst._delete(25);
	bst.inorder();
	bst._delete(14);
	bst.inorder();*/
	bst.postorder();
	bst._delete(20);
	bst.postorder();
	bst._delete(25);
	bst.postorder();
	bst._delete(8);
	bst.postorder();
	bst._delete(35);
	bst.postorder();
	bst._delete(15);
	bst.postorder();
	bst._delete(30);
	bst.postorder();
	bst._delete(12);
	bst.postorder();
	bst._delete(2);
	bst.postorder();
	bst._delete(40);
	bst.postorder();
	bst._delete(6);
	bst.postorder();
	bst._delete(18);
	bst.postorder();
	bst._delete(7);
	bst.postorder();
	bst._delete(10);
	bst.postorder();
	bst._delete(14);
	bst.postorder();
	return 0;
}