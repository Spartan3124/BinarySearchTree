// File: BinarySearchTree.cpp
#include "BinarySearchTree.h"

void print_inorder(const BinarySearchTree & bst)
{
    print_inorder(bst.root());
}

void print_preorder(const BinarySearchTree & bst)
{
    print_preorder(bst.root());
}

void print_postorder(const BinarySearchTree & bst)
{
    print_postorder(bst.root());
}

void print_breadthfirst(const BinarySearchTree & bst)
{
    std::cout << *bst.root() << '\n';
    print_breadthfirst(bst.root());
}

