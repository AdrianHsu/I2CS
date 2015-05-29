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
            
            if(val == root->data)
            {
                bool _root = false;
                if(root->right == NULL){
                    root = root->left;
                    _root = true;
                }
                else if(root->left == NULL){
                    root = root->right;
                    _root = true;
                }
                else if(root->right == NULL && root->left == NULL){
                    delete root;
                    _root = true;
                }
                if(_root)return;
            }

            Node* target = root;
            Node* parent = root;
            bool left_child; // no need to init; if the target is parent's left child(true)
            
            //while loop binary search
            while(true)
            {
                if(val == target->data)
                    break;

                parent = target;
                if(val < target->data)
                {
                    if(target->left == NULL) return; //ERROR: target not found                    
                    target = target->left;
                    left_child = 1;
                }
                else
                {
                    if(target->right == NULL) return; //ERROR: target not found
                    target = target->right;
                    left_child = 0;
                }
            }
            if(target->left == NULL && target->right == NULL) //delete leaf node
            {
                if(left_child) parent->left = NULL;
                else parent->right = NULL;
            }
            if(target->right == NULL)
            {
                if(left_child)parent->left = target->left;
                else parent->right = target->left;
            }
            else if(target->left == NULL)
            {
                if(left_child)parent->left = target->right;
                else parent->right = target->right;
            }
            else // The minimum node of the right subtree (keep going left).
            {
                parent = target;
                Node *tmp = target;
                target = target->right;
                left_child = 0;
                while(target->left != NULL)
                {
                    parent = target;
                    target = target->left;
                    left_child = 1;
                }
                //swap
                int _data = target->data;
                target->data = tmp->data;
                tmp->data = _data;
                
                if(target->right == NULL)
                {
                    if(left_child) parent->left = NULL;
                    else parent->right = NULL;
                }
                else
                {
                    if(left_child)parent->left = target->right;
                    else parent->right = target->right;
                }
            }
            delete target;
            return;
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