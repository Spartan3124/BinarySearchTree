// File: BinarySearchTreeNode.cpp
#include "BinarySearchTreeNode.h"

std::ostream & operator<<(std::ostream & cout,
                          const BinarySearchTreeNode & node)
{
    cout << "<Node: " << &node
         << ", key:" << node.key()
         << ", parent:" << node.parent()
         << ", left:" << node.left()
         << ", right:" << node.right() << '>';
    return cout;
}


void print_inorder(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    print_inorder(node->left());
    std::cout << (*node) << '\n';
    print_inorder(node->right());
}


void print_preorder(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    std::cout << (*node) << '\n';
    print_preorder(node->left());
    print_preorder(node->right());
}


void print_postorder(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    print_postorder(node->left());
    print_postorder(node->right());
    std::cout << (*node) << '\n';
}


void print_breadthfirst(const BinarySearchTreeNode * node)
{
    if (node == NULL) return;
    if (node->left() != NULL) std::cout << (*node->left()) << '\n';
    if (node->right() != NULL) std::cout << (*node->right()) << '\n';
    print_breadthfirst(node->left());
    print_breadthfirst(node->right());
}


//copies a node
bool insert(BinarySearchTreeNode * & node, BinarySearchTreeNode * copyNode)
{
    BinarySearchTreeNode * n = new BinarySearchTreeNode(copyNode->key(),
                                                        copyNode->parent(),
                                                        copyNode->left(),
                                                        copyNode->right());
    if (n->key() > node->key())
    {
        node->right() = n;
    }
    else if (n->key() < node->key())
    {
        node->left() = n;
    }
    else
    {
        return 0;
    }
}
 


//x = new node
bool insert(BinarySearchTreeNode * & node, int x)
{
    if (node == NULL)
    {
        node = new BinarySearchTreeNode(x);
        return 1;
    }
    //left right compare != null insert
    if (x < node->key())
    {
        if (node->left() == NULL)
        {
            node->left() = new BinarySearchTreeNode(x, node);
            return 1;
        }
        else
        {
            insert(node->left(), x);
        }
    }
    else if (x > node->key())
    {
        if (node->right() == NULL)
        {
            node->right() = new BinarySearchTreeNode(x, node);
            return 1;
        }
        else
        {
            insert(node->right(), x);
        }
    }
    else
    {
        return 0;
    }
}


BinarySearchTreeNode * find(BinarySearchTreeNode * node, int x)
{
    BinarySearchTreeNode * f = node;
    while (1)
    {
        if (f == NULL) return NULL;
        if (x == f->key())
        {
            return f;
        }
        else if (x > f->key())
        {
            f = f->right();
        }
        else if (x < f->key())
        {
            f = f->left();
        }
    }
}


bool remove(BinarySearchTreeNode * & node, int x)
{
    BinarySearchTreeNode * f = find(node, x);
    if (f == NULL) return 0;
    if (f->is_leaf())
    {
        BinarySearchTreeNode * p = f->parent();
        if (p->left() == f) p->left() = NULL;
        else if (p->right() == f) p->right() = NULL;
        delete f;
        return 1;
    }
    else
    {
        if (f->left() != NULL)
        {
            BinarySearchTreeNode * r = f->left()->rightmost();
            BinarySearchTreeNode * rp = r->parent();
            f->key() = r->key();

            if (r == f->left())
            {
                f->left() = NULL;
            }
            else
            {
                rp->right() = NULL;
            }
            delete r;
            return 1;
        }
        else if (f->left() == NULL && f->right() != NULL)
        {
            BinarySearchTreeNode * l = f->right()->leftmost();
            BinarySearchTreeNode * lp = l->parent();
            f->key() = l->key();
            if (l == f->right())
            {
                f->right() = NULL;
            }
            else
            {
                lp->left() = NULL;
            }
            delete l;
            return 1;
        }
    }
}
