#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

class Node {
    public:
        Node() { left = right = NULL;}
        Node(int val) { 
            left = right = NULL;
            data = val;
        }
        Node *left;
        Node *right;
        int data;
};

class BST {

    public:
        BST() { root = NULL; }

        ~BST() 
        {
            if (root != NULL)
                release(root);
        }
        void postorder() const {
            if (root == NULL) 
                return;
            postorder(root);
            cout << endl;
        }
        void inorder() const {
            if (root == NULL) 
                return;
            inorder(root);
            cout << endl;
        }
    
        void insert(int val) {
            if (root == NULL) 
                root = new Node(val);
            else
                insert(root, val);
        }

        /*BONUS: DELETE FUNCION*/
        void _delete(int val) {
            
            Node* target = root;
            Node* parent;
            bool left_child;
            //while loop binary search
            while(true)
            {
                if(val == target->data)
                    break;
                else if(val < target->data)
                {
                    if(target->left == NULL) return; //ERROR: target not found
                    parent = target;
                    target = target->left;
                    left_child = 1;
                }
                else
                {
                    if(target->right == NULL) return;
                    parent = target;
                    target = target->right;
                    left_child = 0;
                }
            }
            if(target->left == NULL && target->right == NULL) //delete leaf node
            {
                if(left_child) parent->left = NULL;
                else parent->right = NULL;
                delete target;
                return;
            }
            if(target->right == NULL)
            {
                if(left_child)parent->left = target->left;
                else parent->right = target->left;
                delete target;
                return;
            }
            else if(target->left == NULL)
            {
                if(left_child)parent->right = target->right;
                else parent->right = target->right;
                delete target;
                return;
            }
            else
            {
                parent = target;
                Node *tmp = target;
                target = target->right;
                while(target->left != NULL)
                {
                    parent = target;
                    target = target->left;
                }
                //swap
                int _data = target->data;
                target->data = tmp->data;
                tmp->data = _data;
                if(target->right == NULL)
                {
                    parent->left = NULL;
                    delete target;
                    return;
                }
                else
                {
                    parent->left = target->right;
                    delete target;
                    return;
                }
            }
        }
    protected:
        
        Node *root;
        // p cannot be NULL
        void release(Node* p) {
            if (p->left != NULL)
                release(p->left);
            if (p->right != NULL)
                release(p->right);
            delete p;
        }

        void postorder(Node* p) const {
            if (p->left != NULL)
                postorder(p->left);
            if (p->right != NULL)
                postorder(p->right);
            cout << p->data << " ";
        }
    
        // p cannot be NULL
        void inorder(Node* p) const {
            if (p->left != NULL)
                inorder(p->left);
            cout << p->data << " ";
            if (p->right != NULL)
                inorder(p->right);
        }

        // p cannot be NULL
        void insert(Node* p, int val) {

            if (p->data > val) {
                // left
                if (p->left == NULL) 
                    p->left = new Node(val);
                else 
                    insert(p->left, val);
            }
            else {
                //right
                if (p->right == NULL) 
                    p->right = new Node(val);
                else 
                    insert(p->right, val);
            }
        }

};

#endif