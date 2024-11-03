#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node{
    int data;
    Node * right;
    Node * left;

    Node(int value);
};

class BinaryTree{
    public:
    Node * root;

    //Constructor
    BinaryTree();
    Node * insert(Node*node, int value);
    Node * search(Node*node, int value);

};


#endif