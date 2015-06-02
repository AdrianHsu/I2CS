#include <iostream>
using namespace std;

#include "bst.h"
int main()
{
	BST bst;

	bst.insert(2);
	bst.insert(6);
	bst.insert(5);
	bst.insert(4);
	bst.insert(3);
	bst.postorder();
	bst.erase(2);
	bst.postorder();
	bst.erase(3);
	bst.postorder();
	bst.erase(4);
	bst.postorder();
	bst.erase(6);
	bst.postorder();
	bst.erase(5);
	bst.postorder();

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

	bst.postorder();
	bst.erase(7);
	bst.postorder();
	bst.erase(40);
	bst.postorder();
	bst.erase(10);
	bst.postorder();
	bst.erase(20);
	bst.postorder();
	bst.erase(18);
	bst.postorder();
	bst.erase(30);
	bst.postorder();
	bst.erase(8);
	bst.postorder();
	bst.erase(2);
	bst.postorder();
	bst.erase(14);
	bst.postorder();
	bst.erase(35);
	bst.postorder();
	bst.erase(6);
	bst.postorder();
	bst.erase(15);
	bst.postorder();
	bst.erase(12);
	bst.postorder();
	bst.erase(25);
	bst.postorder();
	/*bst.inorder();
	bst.erase(18);
	bst.inorder();
	bst.erase(10);
	bst.inorder();
	bst.erase(40);
	bst.inorder();
	bst.erase(6);
	bst.inorder();
	bst.erase(15);
	bst.inorder();
	bst.erase(30);
	bst.inorder();
	bst.erase(12);
	bst.inorder();
	bst.erase(2);
	bst.inorder();
	bst.erase(8);
	bst.inorder();
	bst.erase(35);
	bst.inorder();
	bst.erase(20);
	bst.inorder();
	bst.erase(7);
	bst.inorder();
	bst.erase(25);
	bst.inorder();
	bst.erase(14);
	bst.inorder();*/

	return 0;
}