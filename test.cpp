// File: test.cpp
#include <iostream>
#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

int main()
{
    std::cout << "testing BinarySearchTreeNode ...\n";
    BinarySearchTreeNode * n = new BinarySearchTreeNode(5);
    print_inorder(n);
    std::cout << "\n\n";
    
    insert(n, 3);
    print_inorder(n);
    std::cout << "\n\n";
    
    insert(n, 0);
    print_inorder(n);
    std::cout << "\n\n";
    
    insert(n, 1);
    print_inorder(n);
    std::cout << "\n\n";
    
    insert(n, 4);
    print_inorder(n);
    std::cout << "\n\n";
    
    insert(n, 8);
    print_inorder(n);
    std::cout << "\n\n";
    
    std::cout << "leftmost: " << *(n->leftmost());
    std::cout << '\n';
    std::cout << "rightmost: " << *(n->rightmost());
    std::cout << "\n\n";
    
    std::cout << "testing remove: remove(n, 0): " << remove(n, 0) << '\n';
    print_inorder(n);
    std::cout << "\n\n";
    
    std::cout << "testing BinarySearchTree ... \n";
    BinarySearchTree bst;
    std::cout << "is empty? " << bst.is_empty() << '\n';

    try
    {
        std::cout << "testing remove on empty ... ";
        bst.remove(7);
    }
    catch (ValueError & e)
    {
        std::cout << "pass" << std::endl;
    }
     
    print_inorder(bst); std::cout << '\n';
    bst.insert(5); print_inorder(bst); std::cout << '\n';
    bst.insert(0); print_inorder(bst); std::cout << '\n';
    bst.insert(2); print_inorder(bst); std::cout << '\n';
    bst.insert(-2); print_inorder(bst); std::cout << '\n';
    bst.insert(10); print_inorder(bst); std::cout << '\n';
    bst.insert(8); print_inorder(bst); std::cout << '\n';
    bst.insert(9); print_inorder(bst); std::cout << '\n';
    bst.insert(7); print_inorder(bst); std::cout << '\n';

    std::cout << "print preorder...\n";
    print_preorder(bst);
    std::cout << std::endl;
    std::cout << "print inorder...\n";
    print_inorder(bst);
    std::cout << std::endl;
    std::cout << "print postorder...\n";
    print_postorder(bst);
    std::cout << std::endl;
    std::cout << "print breadthfirst...\n";
    print_breadthfirst(bst);
    std::cout << std::endl;

    std::cout << "height: " << bst.height() << '\n';
    
    std::cout << "vector prints..... ";
    std::vector< int > io = bst.inorder();
    std::vector< int > preo = bst.preorder();
    std::vector< int > posto = bst.postorder();
    std::vector< int > bf = bst.breadthfirst();

    std::cout << "print inorder: \n"; 
    for (int i = 0; i < io.size(); ++i)
    {
        std::cout << io[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "print preorder: \n"; 
    for (int i = 0; i < preo.size(); ++i)
    {
        std::cout << preo[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "print postorder: \n"; 
    for (int i = 0; i < posto.size(); ++i)
    {
        std::cout << posto[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "print breadthfirst: \n"; 
    for (int i = 0; i < bf.size(); ++i)
    {
        std::cout << bf[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "find -2 : " << bst.find(-2) << '\n';
    std::cout << "find -11: " << bst.find(-11) << '\n';
    try
    {
        std::cout << "testing duplicate insert ... ";
        bst.insert(7);
    }
    catch (ValueError & e)
    {
        std::cout << "pass" << std::endl;
    }
    
    bst.clear();
    print_inorder(bst); std::cout << '\n';
    
    int y[10] = {6, 1, -10, -2, 8, 3, -7, 4, 9, 5};
    std::cout << "testing array....\n";
    BinarySearchTree bstArray(y, 10);
    print_inorder(bstArray); std::cout << '\n';

    std::cout << "testing vector inorder: ";
    std::vector< int > bv = bstArray.inorder();
    for (int i = 0; i < bv.size(); ++i)
    {
        std::cout << bv[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "test range between 5 and 10: ";
    std::vector< int > bv2 = bstArray.range(5, 10);
    for (int i = 0; i < bv2.size(); ++i)
    {
        std::cout << bv2[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "size: " << bstArray.size() << std::endl;
    std::cout << "min: " << bstArray.min() << " max: " << bstArray.max()
              << '\n';
    std::cout << "height: " << bstArray.height() << '\n';
    
    std::cout << "remove 6\n";
    bstArray.remove(6);
    print_inorder(bstArray); std::cout << '\n';

    std::cout << "remove -7\n";
    bstArray.remove(-7);
    print_inorder(bstArray); std::cout << '\n';

    std::cout<< "depth of 4 " << bstArray.depth(bstArray.find(4)) << '\n'; 
    std::cout << "height: " << bstArray.height() << '\n';

    std::cout << "preorder: \n";
    print_preorder(bstArray); std::cout << '\n';
    
    std::cout << "operator = \n";
    BinarySearchTree bstAC;
    bstAC = bstArray;
    print_inorder(bstAC); std::cout << '\n';
    
    std::cout << "copy constructor: copy bstAC to bstAC2\n";
    BinarySearchTree bstAC2(bstAC);
    std::cout << "bstAC: \n";
    print_inorder(bstAC); std::cout << '\n';
    std::cout << "bstAC2: \n";
    print_inorder(bstAC2); std::cout << '\n';

    std::cout << "bstAC == bstAC2 " << (bstAC == bstAC2) << '\n';
    
    bstAC2.remove(-10);
    std::cout << "bstAC: \n";
    print_inorder(bstAC); std::cout << '\n';
    std::cout << "bstAC2 remove 10: \n";
    print_inorder(bstAC2); std::cout << '\n';
    
    std::cout << "bstAC == bstAC2 " << (bstAC == bstAC2) << '\n';
    std::cout << "bstAC select 4: \n" << *bstAC.select(4) << '\n';
    return 0;

}
