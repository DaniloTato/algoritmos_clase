#include <iostream>
#include "binary_tree.hpp"


int main(){

    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    int valueToSearch = 40;
    Node* result = tree.search(tree.root, valueToSearch);
    std::cout<<result->data;
    return 0;
}