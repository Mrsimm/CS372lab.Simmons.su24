#include <iostream>
#include <memory>
#include <functional>
using namespace std;
template<typename V>
class Tree {
public:
  
    struct Node
    {
        Node(V v, shared_ptr<Node> l, shared_ptr<Node> r) :
            value(v), left(l), right(r) {}
        V value;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
    };

    shared_ptr<Node> root;
    bool deleteNode(V x, shared_ptr<Node>& current)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (x < current->value)
        {
            return deleteNode(x, current->left);
        }
        else if (current->value < x)
        {
            return deleteNode(x, current->right);
        }
        else {

            if (current->left == nullptr && current->right == nullptr)
            {
                current = nullptr;
            }

            else if (current->left == nullptr)
            {
                current = current->right;
            }
            else if (current->right == nullptr)
            {
                current = current->left;
            }

            else
            {

                auto minNode = current->right;
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }


                current->value = minNode->value;


                deleteNode(minNode->value, current->right);
            }
            return true;
        }
    }
    Tree<V> copyTreeWithoutLeaves(const Tree<V>& original)
    {
        if (original.isEmpty())
        {
            return Tree<V>(); 
        }

        if (original.isLeaf()) 
        {
            return Tree<V>(); 
        }

        
        auto leftCopy = copyTreeWithoutLeaves(original.left());
        auto rightCopy = copyTreeWithoutLeaves(original.right());

        
        return Tree<V>(leftCopy, original.rootValue(), rightCopy);
    }
    Tree() : root(nullptr) {}

    Tree(const shared_ptr<Node>& node) : root(node) {}

    Tree(const Tree& lft, V value, const Tree& rgt) :
        root(make_shared<Node>(value, lft.root, rgt.root)) {}
    bool deleteValue(V x)
    {
        return deleteNode(x, root);
    }

    bool member(V x) const {
        if (isEmpty())
            return false;
        V y = root->value;
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }

    Tree insert(V x) const {
        if (isEmpty())
            return Tree(make_shared<Node>(x, nullptr, nullptr));
        V y = root->value;
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this;
    }

    void preorder(std::function<void(V)> visit) const {
        if (isEmpty())
            return;
        V contents = root->value;
        visit(contents);
        left().preorder(visit);
        right().preorder(visit);
    }

    void inorder(function<void(V)> visit) const {
        if (isEmpty())
            return;
        left().inorder(visit);
        V contents = root->value;
        visit(contents);
        right().inorder(visit);
    }

    void postorder(function<void(V)> visit) const {
        if (isEmpty())
            return;
        left().postorder(visit);
        right().postorder(visit);
        V contents = root->value;
        visit(contents);
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    V rootValue() const {
        return root->value;
    }

    Tree<V> left() const {
        return Tree<V>(root->left);
    }

    Tree<V> right() const {
        return Tree<V>(root->right);
    }

    bool isLeaf() const {
        return !root->left && !root->right;
    }

    
};
