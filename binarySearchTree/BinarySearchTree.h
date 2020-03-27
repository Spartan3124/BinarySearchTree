// File: BinarySearchTree.h
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
#include "BinarySearchTreeNode.h"

class ValueError{};

class BinarySearchTree
{
public:
BinarySearchTree()
    : root_(NULL)
    {}

    
// Put x[0], x[1], ..., x[size - 1] into the tree
    BinarySearchTree(int x[], int size)
    {
        this->root_ = new BinarySearchTreeNode(x[0]);
        for (int i = 1; i < size; ++i)
        {
            this->insert(x[i]);
        }
    }
    
    
    BinarySearchTree(const BinarySearchTree & bst)
    {
        *this = bst;
    }


    ~BinarySearchTree()
    {
        if (root_ != NULL) deleteTree(root_);
    }


    bool deleteTree(BinarySearchTreeNode * n)
    {
        if (n != NULL)
        {
            if (n->left() != NULL) deleteTree(n->left());
            if (n->right() != NULL) deleteTree(n->right());
            n->left() = NULL;
            n->right() = NULL;
            delete n;
        }
        return 1;
    }

    
    BinarySearchTreeNode * root() const
    {
        return root_;
    }

    
// [HINT: Traverse *this and bst.]
    BinarySearchTree & operator=(const BinarySearchTree & bst)
    {
        if (bst.is_empty())
        {
            this->clear();
            return *this;
        }
        
        std::vector < BinarySearchTreeNode *> bnodes;
        preorder(bnodes, bst.get_root());
        this->clear();
        root_ = new BinarySearchTreeNode(bnodes[0]->key());
        
        for (int i = 1; i < bnodes.size(); ++i)
        {
            ::insert(root_, bnodes[i]->key()); //throw ValueError();
        }
        return (*this);
    }

    
    BinarySearchTreeNode * get_root() const
    {
        return root_;
    }

    
    void clear()
    {
        deleteTree(root_);
        root_ = NULL;
    }

    
// Returns true if the tree is empty
    bool is_empty() const
    {
        if (root_ == NULL) return 1;
        return (root_->is_leaf());
    }

    
// Returns the height of the tree. Note that the height of an
// empty tree is -1.
    int height()
    {
        //use depth function and max
        int h = height(root_);
        --h;
        return h;
    }


    int height(BinarySearchTreeNode * n)
    {
        int i = -1;
        int j = -1;
        int k = -1;    
        if (n->is_leaf())
        {
            return depth(n);
        }

        if (n->left() != NULL)
        {
            j = height(n->left());
            if (j > i)
            {
                i = j;
            }
        }

        if (n->right() != NULL)
        {
            k = height(n->right());
            if (k > i)
            {
                i = k;
            }
        }
        return i;
    }
    
// Returns the depth of the node pointer p parameter. This is the number
// of edges from the root to the node that p points to.
    int depth(BinarySearchTreeNode * p)
    {
        int d = 0;
        while (p != root_)
        {
            ++d;
            p = p->parent();
        }
        return d;
    }

    
// Returns the number of nodes in this tree.
    int size() const
    {
        std::vector< int > s = inorder();
        return s.size();
    }

    
// Returns a pointer to the node containing x. If x is not in the tree,
// NULL is returned.
    BinarySearchTreeNode * find(int x)
    {
        return ::find(root_, x);
    }

    
// Returns the minimum value in the tree. If the tree is empty,
// a ValueError exception object is thrown.
    int min() const
    {
        if (is_empty()) throw ValueError();
        std::vector< int > t = inorder();
        return t[0];
    }

    
// Returns the maximum value in the tree. If the tree is empty,
// a ValueError exception object is thrown.
    int max() const
    {
        if (is_empty()) throw ValueError();
        std::vector< int > t = inorder();
        return t[t.size() - 1];
    }

    
// Returns true if *this and t are the same trees, i.e., the
// values and structure of *this and t are the same.
    bool operator==(const BinarySearchTree & t)
    {
        std::vector < BinarySearchTreeNode *> bnodes1;
        preorder(bnodes1, root_);

        std::vector < BinarySearchTreeNode *> bnodes2;
        preorder(bnodes2, t.get_root());

        if (bnodes1.size() == bnodes2.size())
        {
            for (int i = 0; i < bnodes1.size(); ++i)
            {
                if (bnodes1[i]->key() != bnodes2[i]->key()) return false;
            }
            return true;
        }
        else
        {
            return false;
        }
        return true;
    }

    
// Inserts x into the tree. If x is already in the tree, a ValueError
// exception object is thrown.
    void insert(int x)
    {
        bool success = ::insert(root_, x);
        if (!success) throw ValueError();
    }


    //copies an existing node
    void insert(BinarySearchTreeNode * node)
    {
        bool success = ::insert(root_, node);
        if (!success) throw ValueError();
    }


// Remove x from the tree. If x is not in the tree, a ValueError
// exception object is thrown.
    void remove(int x)
    {
        bool success = ::remove(root_, x);
        if (!success) throw ValueError();
    }


// Returns a vector of integers built by traversing the tree
// using inorder traversal
    std::vector< int > inorder() const
    {
        std::vector< int > ret;
        std::vector< BinarySearchTreeNode *> bst;
        inorder(bst, root_);

        for (int i = 0; i < bst.size(); ++i) 
        {
            ret.push_back(bst[i]->key());
        }
        return ret;
    }
    
    
    void inorder(std::vector< BinarySearchTreeNode *> & ret,
                 BinarySearchTreeNode * node) const
    {
        if (node == NULL) return;
        inorder(ret, node->left());
        ret.push_back(node);
        inorder(ret, node->right());
    }

    
// Returns a vector of integers built by traversing the tree
// using preorder traversal
    std::vector< int > preorder() const
    {
        std::vector< int > ret;
        std::vector< BinarySearchTreeNode *> bst;
        preorder(bst, root_);

        for (int i = 0; i < bst.size(); ++i) 
        {
            ret.push_back(bst[i]->key());
        }
        return ret;
    }


    void preorder(std::vector< BinarySearchTreeNode *> & ret,
                 BinarySearchTreeNode * node) const
    {
        if (node == NULL) return;
        ret.push_back(node);
        preorder(ret, node->left());
        preorder(ret, node->right());
    }
     
// Returns a vector of integers built by traversing the tree
// using postorder traversal
    std::vector< int > postorder() const
    {
        std::vector< int > ret;
        std::vector< BinarySearchTreeNode *> bst;
        postorder(bst, root_);

        for (int i = 0; i < bst.size(); ++i) 
        {
            ret.push_back(bst[i]->key());
        }
        return ret;
    }


    void postorder(std::vector< BinarySearchTreeNode *> & ret,
                   BinarySearchTreeNode * node) const
    {
        if (node == NULL) return;
        postorder(ret, node->left());
        postorder(ret, node->right());
        ret.push_back(node);
    }

// Returns a vector of integers built by traversing the tree
    // using breadth first traversal
    std::vector< int > breadthfirst() const
    {
        std::vector< int > ret;
        std::vector< BinarySearchTreeNode *> bst;
        breadthfirst(bst, root_);
        
        ret.push_back(root_->key());
        for (int i = 0; i < bst.size(); ++i) 
        {
            ret.push_back(bst[i]->key());
        }
        return ret;
    }

    void breadthfirst(std::vector< BinarySearchTreeNode *> & ret,
                      BinarySearchTreeNode * node) const
    {
        if (node == NULL) return;
        if (node->left() != NULL) ret.push_back(node->left());
        if (node->right() != NULL) ret.push_back(node->right());
        breadthfirst(ret, node->left());
        breadthfirst(ret, node->right());
    }

    
// Return pointer to k-th ordered node
// [HINT: Use a traversal]
    BinarySearchTreeNode * select(int k)
    {
        if (root_ == NULL) throw ValueError();
        std::vector < BinarySearchTreeNode *> bnodes;

        bnodes.push_back(root_);
        breadthfirst(bnodes, root_);
        return bnodes[k];
    }

    
// Return vector of integers in tree with key values >= m and < M.
    std::vector< int > range(int m, int M)
    {
        std::vector< int > ret;
        std::vector< int > t = inorder();
        
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] >= m && t[i] < M)
            {
                ret.push_back(t[i]);
            }
        }
        return ret;
    }
    
private:
    BinarySearchTreeNode * root_;
};

void print_inorder(const BinarySearchTree & bst);
void print_preorder(const BinarySearchTree & bst);
void print_postorder(const BinarySearchTree & bst);
void print_breadthfirst(const BinarySearchTree & bst);

#endif
