#include <iostream>
#include <memory>
#include <functional>
#include "pch.h"
#include "Tree1.h"

template<typename V>
Tree<V> copyTreeWithoutLeaves(const Tree<V>& original) 
{
    if (original.isEmpty()) {
        return Tree<V>();
    }

    if (original.isLeaf()) {
        return Tree<V>();
    }

    auto leftCopy = copyTreeWithoutLeaves(original.left());
    auto rightCopy = copyTreeWithoutLeaves(original.right());

    return Tree<V>(leftCopy, original.rootValue(), rightCopy);
}


int main() 
{
    Tree<int> originalTree(make_shared<Tree<int>::Node>(1,make_shared<Tree<int>::Node>(2,make_shared<Tree<int>::Node>(4, nullptr, nullptr),nullptr),make_shared<Tree<int>::Node>(3, nullptr, nullptr)));

    Tree<int> newTree = copyTreeWithoutLeaves(originalTree);
    cout << "Original Tree (Inorder): ";
    originalTree.inorder([](int v) { cout << v << " "; });
    cout << endl;
    cout << "Modified Tree (Inorder, without leaves): ";
    newTree.inorder([](int v) { cout << v << " "; });
    cout << endl;
    return 0;
}

