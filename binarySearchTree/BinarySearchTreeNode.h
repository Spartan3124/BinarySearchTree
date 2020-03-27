// File: BinarySearchTreeNode.h
#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H
#include <iostream>

class BinarySearchTreeNode
{
public:
BinarySearchTreeNode(int key,
                     BinarySearchTreeNode * parent = NULL,
                     BinarySearchTreeNode * left = NULL,
                     BinarySearchTreeNode * right = NULL)
    : key_(key), parent_(parent), left_(left), right_(right)
    {}
    

    int key() const
    {
        return key_;
    }
    

    int & key()
    {
        return key_;
    }


    BinarySearchTreeNode * parent() const
    {
        return parent_;
    }

    
    BinarySearchTreeNode * & parent()
    {
        return parent_;
    }

    
    BinarySearchTreeNode * root()
    {
        if (this->is_root()) return this;
        this->parent_->root();
    }


    BinarySearchTreeNode * left() const
    {
        return left_;
    }


    BinarySearchTreeNode * & left()
    {
        return left_;
    }

    
// Returns pointer to the leftmost node of the subtree with this
// node as root.
    BinarySearchTreeNode * leftmost()
    {
        if (this->left_ == NULL) return this;
        this->left_->leftmost();
    }

    
    BinarySearchTreeNode * right() const
    {
        return right_;
    }

    
    BinarySearchTreeNode * & right()
    {
        return right_;
    }

    
// Returns pointer to the rightmost node of the subtree with this
// node as root.
    BinarySearchTreeNode * rightmost()
    {
        if (this->right_ == NULL) return this;
        this->right_->rightmost();
    }

    
// Returns true if the node is a leaf node, i.e., the left
// and right are both NULL.
    bool is_leaf() const
    {
        return (left_ == NULL && right_ == NULL);
    }

    
// Returns true if the node is not a leaf node
    bool is_nonleaf() const
    {
        return !(this->is_leaf());
    }

    
// Returns true if the parent is NULL
    bool is_root() const
    {
        return (parent_ == NULL);
    }

    
private:
    int key_;
    BinarySearchTreeNode * parent_;
    BinarySearchTreeNode * left_;
    BinarySearchTreeNode * right_;
};

std::ostream & operator<<(std::ostream &,
                          const BinarySearchTreeNode &);
void print_inorder(const BinarySearchTreeNode *);
void print_preorder(const BinarySearchTreeNode * node);
void print_postorder(const BinarySearchTreeNode * node);
void print_breadthfirst(const BinarySearchTreeNode * node);

bool insert(BinarySearchTreeNode * & node, BinarySearchTreeNode * copyNode);
bool insert(BinarySearchTreeNode * &, int);

BinarySearchTreeNode * find(BinarySearchTreeNode * node, int x);

bool remove(BinarySearchTreeNode * & node, int x);    
    
#endif
